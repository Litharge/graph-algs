#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"


/* Function: get_smallest_in_unvisited
 * Selects the vertex with the smallest tentative distance that is not yet visited
 * 
 * unvisited: array with 0 meaning unvisited, 1 meaning visited
 * shortest_distances: tentative distances
 * n_vertexes: total number of vertexes in the graph
 *
 * returns: int specifying the vertex, -1 if all vertexes are visited
 */
int get_smallest_in_unvisited(int *unvisited, int *shortest_distances, int n_vertexes) {
	int min_dist = -1;
	int min_dist_vertex = -1;

	for (int i = 0; i < n_vertexes; i++) {
		if (unvisited[i] == 0 && (shortest_distances[i] <= min_dist || min_dist == -1) && shortest_distances[i] != -1) {
			min_dist = shortest_distances[i];
			min_dist_vertex = i;
		}
	}

	return min_dist_vertex;
}


/* Function: add_connections_to_shortest
 * Modifies the tentative distances and previous nodes when a shorter path is found to a vertex
 *
 * current: the vertex to recalculate distances via
 * shortest_distances: array of tentative distances
 * prev_vertexes: array of vertexes when prev_vertexes[i] gives the vertex previous to vertex i
 * unvisited: array describing whether the vertex has been current before, 0 for unvisited, 1 for visited
 * graph: martix describing problem graph
 * n_vertexes: number of vertexes in graph
 *
 */
void add_connections_to_shortest(int current, int *shortest_distances, int *prev_vertexes, int *unvisited, int **graph, int n_vertexes) {
	for (int i = 0; i < n_vertexes; i++) {
		if (graph[current][i] == -1 || unvisited[i] == 1) {
			continue;
		}

		int tentative = shortest_distances[current] + graph[current][i];
		if (tentative < shortest_distances[i] || shortest_distances[i] == -1) {
			shortest_distances[i] = tentative;
			prev_vertexes[i] = current;
		}
	}

	return;
}

/* Function: reverse_array
 * reverses an array
 *
 * to_reverse: array to reverse
 * n: number of items in to_reverse
 *
 * returns: reversed array
 */
int *reverse_array(int *to_reverse, int n) {
	int a = 0;
	int b = n-1;

	while (a < b) {
		int temp = to_reverse[a];
		to_reverse[a] = to_reverse[b];
		to_reverse[b] = temp;
		a++;
		b--;
	}

	return to_reverse;
}


/* Function: produce_path_from_prev_vertexes
 * backtracks along prev_vertexes and reverses to generate path from 0 to target vertex
 *
 * prev_vertexes: array describing previous vertexes, including the actual path
 * target_vertex: the desired end vertex
 *
 * returns: array containing shortest path vertexes
 */
int *produce_path_from_prev_vertexes(int *prev_vertexes, int target_vertex) {
	int size = 1;
	int *path = (int*)malloc(1 * sizeof(int));
	path[0] = target_vertex;
	int current = target_vertex;
	while (1) {
		if (current == 0) {
			break;
		}
		size++;
		path = realloc(path, (size) * sizeof(int));

		path[size-1] = prev_vertexes[current];
		current = prev_vertexes[current];
	}

	path = reverse_array(path, size);

	return path;
}


/* Function: dijkstra_alg
 * runs dijkstra's algorithm on a graph matrix, funding the shortest path from vertex 0 to a target vertex
 *
 * graph: matrix describing graph, with -1 denoting no connection
 * n_vertexes: number of vertexes in the graph
 * target: integer specifying the target vertex
 *
 * returns: PathInfo describing the path and giving its total length, if the path_length member variable is equal to -1, then the other member variables contents are undefiend
 */
PathInfo dijkstra_alg(int **graph, int n_vertexes, int target) {
	PathInfo result;
	// shortest_distances holding shortest distance to each vertex
	result.shortest_distances = malloc(n_vertexes * sizeof(int));

	// designate all vertexes not visited
	for (int i = 0; i < n_vertexes; i++)
		result.shortest_distances[i] = -1;

	// unvisited[i] holding 0 for vertex i unvisited, 1 visited
	int *unvisited = calloc(n_vertexes, sizeof(int));

	// prev_vertexes[i] holding the node previous to node i
	int *prev_vertexes = calloc(n_vertexes, sizeof(int));

	unvisited[0] = 0;
	result.shortest_distances[0] = 0;

	while(1) {
		int current = get_smallest_in_unvisited(unvisited, result.shortest_distances, n_vertexes);

		// current == -1 indicates all vertexes connected to 0 are visited and that no path to the target has been found
		if (current == -1) {
			free(unvisited);

			result.path_length = -1;

			return result;
		}

		add_connections_to_shortest(current, result.shortest_distances, prev_vertexes, unvisited, graph, n_vertexes);

		unvisited[current] = 1;

		if (unvisited[target] == 1) {
			free(unvisited);
			result.path = produce_path_from_prev_vertexes(prev_vertexes, target);

			result.path_length = result.shortest_distances[target];
			return result;
		}
	}
}

/* Function: free_path_info
 * frees allocated memory pointed to by PathInfo members
 *
 * to_free: the PathInfo instance to free
 */
void free_path_info(PathInfo to_free) {
	if (to_free.path_length != -1) {
		free(to_free.path);
	}

	free(to_free.shortest_distances);
}

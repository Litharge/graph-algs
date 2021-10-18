#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"


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


void print_arr(int *to_print, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", to_print[i]);
	}
	printf("\n");
}


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

		if (current == -1) {
			free(unvisited);

			result.path_length = -1;
			// placeholder
			// TODO: remove and add test for path_length==-1 in tests
			result.path = malloc(1);

			return result;
		}


		printf("current: %d\n", current);

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

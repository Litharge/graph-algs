#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_


/* Struct: PathInfo
 * struct describing a shortest path
 *
 * shortest_distances: tentative shortest distances to each vertex
 * path: the vertexes in the shortest path
 * path_length: the length of the shortest path
 */
typedef struct PathInfo {
	int *shortest_distances;
	int *path;
	int path_length;
} PathInfo;


/* Function: dijkstra_alg
 * runs dijkstra's algorithm on a graph matrix, funding the shortest path from vertex 0 to a target vertex
 *
 * graph: matrix describing graph, with -1 denoting no connection
 * n_vertexes: number of vertexes in the graph
 * target: integer specifying the target vertex
 *
 * returns: PathInfo describing the path and giving its total length, if the path_length member variable is equal to -1, then the other member variables contents are undefiend
 */
PathInfo dijkstra_alg(int **graph, int n_vertexes, int target);

int get_smallest_in_unvisited(int *unvisited, int *shortest_distances, int n_vertexes);

void free_path_info(PathInfo to_free);

#endif

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

typedef struct PathInfo {
	int *shortest_distances;
	int *path;
	int path_length;
} PathInfo;



PathInfo dijkstra_alg(int **graph, int n_vertexes, int target);

int get_smallest_in_unvisited(int *unvisited, int *shortest_distances, int n_vertexes);

#endif

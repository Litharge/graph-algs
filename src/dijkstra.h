#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

int * dijkstra_alg(int **graph, int n_vertexes, int target);

int get_smallest_in_unvisited(int *unvisited, int *shortest_distances, int n_vertexes);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

int get_smallest_in_unvisited(int *unvisited, int *shortest_distances, int n_vertexes) {
	int min_dist = -1;
	int min_dist_vertex = 0;

	for (int i = 0; i < n_vertexes; i++) {
		if (unvisited[i] == 0 && (shortest_distances[i] <= min_dist || min_dist == -1) && shortest_distances[i] != -1) {
			min_dist = shortest_distances[i];
		       min_dist_vertex = i;
		}
	}

	return min_dist_vertex;
}


void add_connections_to_shortest(int current, int *shortest_distances, int *unvisited, int **graph, int n_vertexes) {
	for (int i = 0; i < n_vertexes; i++) {
		if (graph[current][i] == -1 || unvisited[i] == 1) {
			continue;
		}

		int tentative = shortest_distances[current] + graph[current][i];
		if (tentative < shortest_distances[i] || shortest_distances[i] == -1) {
			shortest_distances[i] = tentative;
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


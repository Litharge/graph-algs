#include "dijkstra.h"
#include <stdio.h>

void test_smallest() {
	int unvisited[] = {1, 0, 0, 0};
	int shortest_distances[] = {0, 4, 3, 5};
	int n_vertexes = 4;

	int smallest_result = get_smallest_in_unvisited(unvisited, shortest_distances, n_vertexes);

	if (smallest_result == 2) 
		printf("test_smallest PASSED\n");
	else
		printf("test_smallest FAILED\n");
}

void test_skips_visited() {
	int unvisited[] = {1, 0, 0, 0, 1, 1};
	int shortest_distances[] = {0, 4, 3, 5, 2, 1};
	int n_vertexes = 6;

	int smallest_result = get_smallest_in_unvisited(unvisited, shortest_distances, n_vertexes);

	if (smallest_result == 2) 
		printf("test_skips_visited PASSED\n");
	else
		printf("test_skips_visited FAILED\n");
}

void test_skips_not_connected() {
	int unvisited[] = {1, 0, 0, 0};
	int shortest_distances[] = {0, -1, -1, 5};
	int n_vertexes = 4;

	int smallest_result = get_smallest_in_unvisited(unvisited, shortest_distances, n_vertexes);

	if (smallest_result == 3) 
		printf("test_skips_not_connected PASSED\n");
	else
		printf("test_skips_not_connected FAILED\n");
}

int main(int argc, char **argv) {
	printf("---In test_get_smallest_in_unvisited---\n");
	test_smallest();

	test_skips_visited();

	test_skips_not_connected();

	printf("------\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dijkstra.h>


//int **static_sparse_to_pointer(

void test_dijkstra_simple_graph() {
	int **test_graph = (int**)malloc(3 * sizeof(int*));

	int test_graph_row_0[] = {-1, 2, 4};
	int test_graph_row_1[] = {2, -1, 1};
	int test_graph_row_2[] = {4, 1, -1};

	test_graph[0] = test_graph_row_0;
	test_graph[1] = test_graph_row_1;
	test_graph[2] = test_graph_row_2;

	PathInfo test_result = dijkstra_alg(test_graph, 3, 2);

	// test that the shortest distance to vertex 2 is 2 + 1 = 3
	if (test_result.shortest_distances[2] == 2 + 1) {
		printf("test_dijkstra_simple_graph PASSED\n");
	}
	else {
		printf("test_dijkstra_simple_graph FAILED\n");
	}

	free_path_info(test_result);

	free(test_graph);

}

void print_arr_1(int *to_print, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", to_print[i]);
	}
	printf("\n");
}

// generate a longer graph
// matrix rows are written as literals for brevity, which are then copied over 
// so the data is on the heap
int **get_long_test_graph(){
	int **test_graph = (int**)malloc(6 * sizeof(int*));

	const int test_graph_row_0[6] = {-1, 1, 2, -1, -1, -1};
	const int test_graph_row_1[6] = {1, -1, -1, 6, 1, -1};
	const int test_graph_row_2[6] = {2, -1, -1, 4, -1, -1};
	const int test_graph_row_3[6] = {-1, 6, 4, -1, -1, 1};
	const int test_graph_row_4[6] = {-1, 1, -1, -1, -1, 10};
	const int test_graph_row_5[6] = {-1, -1, -1, 1, 10, -1};

	test_graph[0] = malloc(6 * sizeof(int));
	test_graph[1] = malloc(6 * sizeof(int));
	test_graph[2] = malloc(6 * sizeof(int));
	test_graph[3] = malloc(6 * sizeof(int));
	test_graph[4] = malloc(6 * sizeof(int));
	test_graph[5] = malloc(6 * sizeof(int));

	memcpy(test_graph[0], test_graph_row_0, sizeof(test_graph_row_0));
	
	memcpy(test_graph[1], test_graph_row_1, sizeof(test_graph_row_1));

	memcpy(test_graph[2], test_graph_row_2, sizeof(test_graph_row_1));

	memcpy(test_graph[3], test_graph_row_3, sizeof(test_graph_row_1));

	memcpy(test_graph[4], test_graph_row_4, sizeof(test_graph_row_1));

	memcpy(test_graph[5], test_graph_row_5, sizeof(test_graph_row_1));


	return test_graph;
}


void test_dijkstra_longer_graph() {
	int **test_graph = get_long_test_graph();

	PathInfo test_result = dijkstra_alg(test_graph, 6, 5);

	print_arr_1(test_result.shortest_distances, 6);

	if (test_result.shortest_distances[5] == 7) {
		printf("test_dijkstra_longer_graph PASSED\n");
	}
	else {
		printf("test_dijkstra_longer_graph FAILED\n");
	}

	free_path_info(test_result);	

	for (int i = 0; i < 6; i++) {
		free(test_graph[i]);
	}
	free(test_graph);
}


int compare_arrays(int *a, int *b, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}

	return 1;
}


void test_dijkstra_path_longer_graph() {
	int **test_graph = get_long_test_graph();

	PathInfo test_result = dijkstra_alg(test_graph, 6, 5);

	print_arr_1(test_result.path, 4);

	int expected_path[] = {0, 2, 3, 5};
	
	if (compare_arrays(test_result.path, expected_path, 4)) {
		printf("test_dijkstra_path_longer_graph PASSED\n");
	}
	else {
		printf("test_dijkstra_path_longer_graph FAILED\n");
	}

	free_path_info(test_result);

	for (int i = 0; i < 6; i++) {
		free(test_graph[i]);
	}
	free(test_graph);
}


void test_dijkstra_length_longer_graph() {
	int **test_graph = get_long_test_graph();

	PathInfo path_result = dijkstra_alg(test_graph, 6, 5);

	if (path_result.path_length == 7) {
		printf("test_dijkstra_length_longer_graph PASSED\n");
	}
	else {
		printf("test_dijkstra_length_longer_graph FAILED\n");
	}

	free_path_info(path_result);

	for (int i = 0; i < 6; i++) {
		free(test_graph[i]);
	}
	free(test_graph);

}


void test_dijkstra_length_unconnected_graph() {
	int **test_graph = (int**)malloc(3 * sizeof(int*));

	// vertex 0 is connected to vertex 1 only
	int test_graph_row_0[] = {-1, 2, -1};
	int test_graph_row_1[] = {2, -1, -1};
	int test_graph_row_2[] = {-1, -1, -1};

	test_graph[0] = test_graph_row_0;
	test_graph[1] = test_graph_row_1;
	test_graph[2] = test_graph_row_2;

	PathInfo result = dijkstra_alg(test_graph, 3, 2);

	if (result.path_length == -1) {
		printf("test_dijkstra_length_unconnected_graph PASSED\n");
	}
	else {
		printf("test_dijkstra_length_unconnected_graph FAILED\n");
	}

	free_path_info(result);
}


int main(int argc, char **argv) {
	printf("---In test_dijkstra_alg---\n");
	test_dijkstra_simple_graph();
	test_dijkstra_longer_graph();
	test_dijkstra_path_longer_graph();
	test_dijkstra_length_longer_graph();
	test_dijkstra_length_unconnected_graph();

	return 0;
}


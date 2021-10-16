#include <stdio.h>
#include <stdlib.h>
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

	int *dists = dijkstra_alg(test_graph, 3, 2);

	// test that the shortest distance to vertex 2 is 2 + 1 = 3
	if (dists[2] == 2 + 1) {
		printf("test_dijkstra_simple_graph passed\n");
	}
	else {
		printf("test_dijkstra_simple_graph failed\n");
	}

	free(test_graph);

}

void print_arr_1(int *to_print, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d,", to_print[i]);
	}
	printf("\n");
}

void test_dijkstra_longer_graph() {
	int **test_graph = (int**)malloc(6 * sizeof(int*));

	int test_graph_row_0[] = {-1, 1, 2, -1, -1, -1};
	int test_graph_row_1[] = {1, -1, -1, 6, 1, -1};
	int test_graph_row_2[] = {2, -1, -1, 4, -1, -1};
	int test_graph_row_3[] = {-1, 6, 4, -1, -1, 1};
	int test_graph_row_4[] = {-1, 1, -1, -1, -1, 10};
	int test_graph_row_5[] = {-1, -1, -1, 1, 10, -1};

	test_graph[0] = test_graph_row_0;
	test_graph[1] = test_graph_row_1;
	test_graph[2] = test_graph_row_2;
	test_graph[3] = test_graph_row_3;
	test_graph[4] = test_graph_row_4;
	test_graph[5] = test_graph_row_5;

	int *dists = dijkstra_alg(test_graph, 6, 5);

	print_arr_1(dists, 6);

	if (dists[5] == 7) {
		printf("test_dijkstra_longer_graph passed\n");
	}
}


int main(int argc, char **argv) {
	printf("---In test_dijkstra_alg---\n");
	test_dijkstra_simple_graph();
	test_dijkstra_longer_graph();

	return 0;
}


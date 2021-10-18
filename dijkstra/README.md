# Dijkstra

Implementation of Dijkstra's algorithm for finding the shortest path between
vertexes of an undirected weighted graph.

## Installation

Place src/ in a convenient location and include dijkstra.h

## Example

> #include "dijkstra.h"  
> ...  
> int **test_graph = (int**)malloc(3 * sizeof(int*));  
> 
> int test_graph_row_0[] = {-1, 2, 4};  
> int test_graph_row_1[] = {2, -1, 1};  
> int test_graph_row_2[] = {4, 1, -1};  
> 
> test_graph[0] = test_graph_row_0;  
> test_graph[1] = test_graph_row_1;  
> test_graph[2] = test_graph_row_2;  
> 
> PathInfo test_result = dijkstra_alg(test_graph, 3, 2);  

Then 
* `test_result.path` contains
	`[0, 1, 2]`
* `test_result.path_length` contains
	`3`
* `test_result.shortest_distances` contains 
	`[0, 2, 3]`

## API

### (Struct) PathInfo

* Member variables
	* `int*`: `path` - an array of vertexes in a shortest path from vertex 0 to target
	* `int`: `path_length` - the length of the path described by `path`, `-1` if there is no path from 0 to the target
	* `int*`: `shortest_distances` - contains final distances to vertexes according to dijkstra's algorithm

### (Function) dijkstra_alg

* Syntax
* Parameters
	* `int**`: `graph` - matrix describing an undirected graph
	* `int`: `n_vertexes` - number of vertexes in `graph`
	* `int`: `target` - vertex index in `graph` to find a shortest path to from vertex 0
* Return
	* `PathInfo`: `dijkstra_alg` - struct containing info about the shortest path (see PathInfo documentation above)

### (Function) free_path_info

* Syntax
	* `void free_path_info(PathInfo to_free);`
* Parameters
	* `PathInfo`: `to_free` - the PathInfo instance to free memory for

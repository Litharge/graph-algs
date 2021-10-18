# Dijkstra

Implementation of Dijkstra's algorithm for finding the shortest path between
vertexes of an undirected weighted graph.

## Installation

Place src/ in a convenient location and include dijkstra.h

## Example

> #include "dijkstra.h"
> ...
> int \*\*test\_graph = (int\*\*)malloc(3 \* sizeof(int\*));
> 
> int test\_graph\_row\_0[] = {-1, 2, 4};
> int test\_graph\_row\_1[] = {2, -1, 1};
> int test\_graph\_row\_2[] = {4, 1, -1};
> 
> test\_graph[0] = test\_graph\_row\_0;
> test\_graph[1] = test\_graph\_row\_1;
> test\_graph[2] = test\_graph\_row\_2;
> 
> PathInfo test\_result = dijkstra\_alg(test\_graph, 3, 2);

Then 
* `test\_result.path` contains
	`[0, 1, 2]`
* `test\_result.path\_length` contains
	`3`
* `test\_result.shortest\_distances` contains 
	`[0, 2, 3]`

## API

### (Struct) PathInfo

* Member variables
	* `int\*`: `path` - an array of vertexes in a shortest path from vertex 0 to target
	* `int`: `path\_length` - the length of the path described by `path`, `-1` if there is no path from 0 to the target
	* `int\*`: `shortest\_distances` - contains final distances to vertexes according to dijkstra's algorithm

### (Function) dijkstra\_alg

* Syntax
* Parameters
	* `int\*\*`: `graph` - matrix describing an undirected graph
	* `int`: `n\_vertexes` - number of vertexes in `graph`
	* `int`: `target` - vertex index in `graph` to find a shortest path to from vertex 0
* Return
	* `PathInfo`: `dijkstra\_alg` - struct containing info about the shortest path (see PathInfo documentation above)

### (Function) free\_path\_info

* Syntax
	* `void free\_path\_info(PathInfo to\_free);`
* Parameters
	* `PathInfo`: `to\_free` - the PathInfo instance to free memory for

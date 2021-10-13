CC=gcc
BINDIR=../bin
TESTSDIR=tests

dijkstra: main.c dijkstra.c
	$(CC) -o $(BINDIR)/dijkstra main.c dijkstra.c

run: dijkstra
	$(BINDIR)/dijkstra

.PHONY: run

test_suite: test_dijkstra

test_dijkstra: $(TESTSDIR)/test_get_smallest_in_unvisited.c dijkstra.c
	$(CC) -o $(BINDIR)/test_get_smallest_in_unvisited.c $(TESTSDIR)/test_get_smallest_in_unvisited.c dijkstra.c -I.

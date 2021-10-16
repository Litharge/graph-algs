CC=gcc
BINDIR=../bin
TESTSDIR=tests

dijkstra: main.c dijkstra.c
	$(CC) -o $(BINDIR)/dijkstra main.c dijkstra.c

run: dijkstra
	$(BINDIR)/dijkstra

.PHONY: run

test_suite: test_subroutine test_dijkstra

test_subroutine: $(TESTSDIR)/test_get_smallest_in_unvisited.c dijkstra.c
	$(CC) -o $(BINDIR)/test_get_smallest_in_unvisited $(TESTSDIR)/test_get_smallest_in_unvisited.c dijkstra.c -I.

test_dijkstra: $(TESTSDIR)/test_dijkstra_alg.c dijkstra.c
	$(CC) -o $(BINDIR)/test_dijkstra_alg $(TESTSDIR)/test_dijkstra_alg.c dijkstra.c -I.

run_test_suite: test_suite
	$(BINDIR)/test_dijkstra_alg
	$(BINDIR)/test_get_smallest_in_unvisited

# Ford-Fulkerson Maximum Flow in C

This project contains a C implementation of the Ford-Fulkerson method for finding the maximum possible flow from a source vertex to a sink vertex in a directed capacitated graph.

The code uses the Edmonds-Karp variation of Ford-Fulkerson, which means it finds augmenting paths with Breadth-First Search (BFS). This makes the path selection deterministic and easier to follow than a generic depth-first Ford-Fulkerson implementation.

## File

- `Ford–Fulkerson.c`: Implements BFS, the residual graph update process, and a small sample graph in `main()`.

## How It Works

The graph is represented as a `6 x 6` adjacency matrix, where each value is the capacity of the directed edge from one vertex to another. A value of `0` means there is no direct edge.

The algorithm:

1. Copies the original capacity graph into a residual graph.
2. Uses BFS to find an augmenting path from the source to the sink.
3. Finds the bottleneck capacity along that path.
4. Subtracts that bottleneck from forward residual edges.
5. Adds that bottleneck to reverse residual edges.
6. Repeats until no more augmenting path exists.

The final accumulated flow is the maximum flow.

## Functions

### `bfs(int rGraph[V][V], int s, int t, int parent[])`

Searches the residual graph for a path from source `s` to sink `t`.

It also fills the `parent` array so the path can be reconstructed by `fordFulkerson()`.

### `fordFulkerson(int graph[V][V], int s, int t)`

Computes and returns the maximum flow from source `s` to sink `t`.

It repeatedly calls `bfs()`, updates residual capacities, and adds each augmenting path's bottleneck value to the total flow.

### `main()`

Defines a sample graph with 6 vertices and prints the maximum flow from vertex `0` to vertex `5`.

## Sample Graph

The graph used in the program is:

```c
int graph[V][V] = {
    {0, 10, 10, 0, 0, 0},
    {0, 0, 2, 8, 4, 0},
    {0, 0, 0, 9, 0, 0},
    {0, 0, 0, 0, 6, 10},
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 0, 0}
};
```

For this graph:

- Source vertex: `0`
- Sink vertex: `5`
- Maximum flow: `19`

## Build and Run

Compile the program with `gcc`:

```bash
gcc 'Ford–Fulkerson.c' -o ford_fulkerson
```

Run it:

```bash
./ford_fulkerson
```

Expected output:

```text
The maximum possible flow is 19
```

## Notes

- The number of vertices is fixed by `#define V 6`.
- To use a different graph size, update `V` and provide a matching adjacency matrix.
- All capacities are stored as integers.
- This implementation assumes non-negative edge capacities.

To learn more about the max flow topic, watch Professor Hadi Yousefi's video: https://www.aparat.com/v/u1441mi

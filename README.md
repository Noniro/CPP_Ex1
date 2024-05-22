# System Programming 2 , assignment 1.

### Author
 -Name:    Yuval Vogdan.
 -Email:   yuvalv126@gmail.com
 -git url: https://github.com/Noniro 


This repository contains implementations of various graph algorithms in C++.

## Classes

### 1. Algorithms

The `Algorithms` class provides implementations of the following graph algorithms:

- **isConnected**: Determines whether the graph is connected. For directed graphs,
    it checks if the graph is strongly connected.
- **shortestPath**: Computes the shortest path between two vertices. 
    It uses Bellman-Ford algorithm for weighted graphs and BFS for unweighted graphs.
- **isContainsCycle**: Checks if the graph contains a cycle and returns the cycle path if present.
- **isBipartite**: Determines if the graph is bipartite. 
    It returns the two groups of vertices if the graph is bipartite.
- **negativeCycle**: Checks if the graph contains a negative cycle. 
    It uses the Bellman-Ford algorithm for this purpose.

### 2. Graph

The `Graph` class represents a graph using an adjacency matrix. 
It provides the following functionalities:

 - **loadGraph(const vector<vector<int>>& adjacencyMatrix)**: Loads the graph with the provided adjacency matrix and initialize fields accordingly.
- **getTranspose()**: Returns the transpose of the graph.
- **printGraph()**: Prints number of edges and vertecies.
- **countEdges()**: Counts the number of edges in the graph.
- **getVerticesCount()**: Returns the number of vertices in the graph.
- **getNeighbors(int v)**: Returns the neighbors of a vertex.
- **getAdjacencyMatrix()**: Returns the adjacency matrix of the graph.
- **getIsDirected()**: Returns true if the graph is directed, false otherwise.
- **getEdgeWeight(int u, int v)**: Returns the weight of the edge between vertices u and v.
- **setDirected(bool isDirected)**: Sets the directedness of the graph.



## Usage

To use these graph algorithms, include the necessary headers (`Algorithms.hpp` and `Graph.hpp`) 
and instantiate the `Graph` class with the required graph data.
also, make sure to use the VOGDAN namespace or declare it before each method.
Then, use the methods provided by the `Algorithms` class to perform graph operations.
example:
````````````````````````````````````cpp
VOGDAN::Graph g;
VOGDAN::Algorithms::isConnected(graph);

````````````````````````````````````
or add "using namespace VOGDAN; at the top of the file"
To initialize a `Graph` object, you need to pass if the graph is directed or not.
(default is undirected)
examples:
````````````````````````````````````cpp
using namespace VOGDAN;
Graph g(true);  // directed graph
Graph g(false); // undirected graph
Graph g;        // undirected graph
````````````````````````````````````
A graph is represented as a matrix, therefore after creating your desired graph (matrix)
we use the loadGraph function to initialize the adjacencyMatrix:

````````````````````````````````````cpp
// 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
````````````````````````````````````
## Main algorithms:

# isConnected:

This method determines if the graph is connected, meaning that there exists a path between every pair of vertices in the graph.
It employs Depth-First Search (DFS) to traverse the graph and mark visited vertices.
For directed graphs, it additionally checks for strong connectivity by performing DFS on the transpose of the graph.
If any vertex remains unvisited after DFS traversal, the graph is deemed disconnected.

# shortestPath:

This method finds the shortest path between two vertices in the graph.
If the graph is unweighted, it uses Breadth-First Search (BFS) to find the shortest path.
If the graph is weighted, it employs the Bellman-Ford algorithm, which works even with negative edge weights and detects negative weight cycles.
The function initializes distances and parent arrays, then relaxes edges iteratively to find the shortest paths.

# isContainsCycle:

This method determines whether the graph contains any cycles.
It uses DFS traversal to explore the graph and detect cycles.
While traversing, it maintains a color array to mark vertices as white (unvisited), gray (visited but not yet processed), or black (visited and processed).
If it encounters a gray vertex during traversal, it indicates the presence of a cycle.

# isBipartite:

This method checks if the graph is bipartite, meaning its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.
It uses BFS traversal to assign colors (0 and 1) to vertices, ensuring that adjacent vertices have different colors.
If a vertex is found to have conflicting colors (i.e., adjacent vertices with the same color), the graph is not bipartite.
For directed graphs, the method simply returns that the graph is not bipartite, as bipartite classification typically applies to undirected graphs.

# Testing:

In this assignment you can find in *Test.cpp* a bunch of test casses i wrote that test all the graph algorithms. 
Each test case describes the main thing i want to test in the graph. 


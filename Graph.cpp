#include "Graph.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace VOGDAN;
/*In this Graph implementation, we have all the basic functions needed for the graph Algorithms.
  in Graph.hpp the class declaration. 
  we can declare the graph useing default contructor or constructor with needed parameters.
  in here (Graph.cpp) we have the following functions:
*/

/*loadGraph: this function takes the graph adjacency matrix and checking if 
  the representaion is valid by going thru the matrix and checking if the matrix is square.
  then it checks if the graph is directed or not by checking if the matrix is symmetric or not.
  and lastly if there are self vertex loops.
  and update the isDirected variable accordingly.
  then it loads the graph by assigning the adjacency matrix to the adjacencyMatrix variable.
*/
void Graph::loadGraph(const vector<vector<int>>& adjacencyMatrix) {
    size_t n = adjacencyMatrix.size();
    for (size_t i = 0; i < n; ++i) {
        if (adjacencyMatrix[i].size() != n) {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    bool isSymmetric = true;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    for(int i=0; i<n;i++){
        if(adjacencyMatrix[i][i]!=0){
            throw invalid_argument("graph with self loops not allowed.");
        }
    }

    setDirected(!isSymmetric);
    this->adjacencyMatrix = adjacencyMatrix;
}
// Using for when graph is directed, creating a new graph with the transposed matrix.
Graph Graph::getTranspose() const {
    Graph GT;
    size_t n = adjacencyMatrix.size();
    vector<vector<int>> transpose(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            transpose[j][i] = adjacencyMatrix[i][j];
        }
    }
    GT.loadGraph(transpose); // Assign the transposed matrix to GT
    return GT;
}

bool Graph::getIsDirected() const {
    return isDirected;
}


void Graph::printGraph() {
    cout << "Graph with " << adjacencyMatrix.size() << " vertices and " << countEdges() << " edges." << endl;
}


void Graph::setDirected(bool isDirected) {
    this->isDirected = isDirected;
}


size_t Graph::countEdges() {
    size_t edges = 0;
    if (isDirected) {
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    ++edges;
                }
            }
        }
    } else {
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = i; j < adjacencyMatrix[i].size(); ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    ++edges;
                }
            }
        }
    }
    return edges; 
}

vector<vector<int>>& Graph::getAdjacencyMatrix() {
    return adjacencyMatrix;
}

size_t Graph::getVerticesCount() {
    return adjacencyMatrix.size();
}
// get neighbors -> returning the vertex row.
vector<int> Graph::getNeighbors(int v) {
    if (v < 0 || v >= adjacencyMatrix.size()) {
        throw out_of_range("Vertex out of range");
    }
    return adjacencyMatrix[v];
}

    




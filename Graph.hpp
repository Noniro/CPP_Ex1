#pragma once
#include <vector>
using namespace std;
namespace VOGDAN{
//graph class, contains the private fields and the public functionalities declarations.
    class Graph { 
    private:
        vector<vector<int>> adjacencyMatrix;
        bool isDirected;

    public:
        Graph(): isDirected(false) {} // Default constructor
        Graph(vector<vector<int>>& adjacencyMatrix); // Constructor
        void loadGraph(const vector<vector<int>>& adjacencyMatrix);
        Graph getTranspose() const;
        void printGraph();
        size_t countEdges();
        size_t getVerticesCount();
        vector<int> getNeighbors(int v);
        vector<vector<int>>& getAdjacencyMatrix();
        Graph(bool isDirected);
        bool getIsDirected() const;
        int getEdgeWeight(int u, int v);
        void setDirected(bool isDirected);
        
    };
}
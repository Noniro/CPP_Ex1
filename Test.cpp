#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace VOGDAN;

TEST_CASE("Graph functions test graph 1")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::isContainsCycle(g) == "-1");
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}.");
}

TEST_CASE("Graph functions test graph 2")
{
    Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");
    // CHECK(Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");
    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");
}

TEST_CASE("Test functions graph 3")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->2");
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");
    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");
}

TEST_CASE("Test functions graph 4")
{
    Graph g;
     vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 2, 0, 0},
        {0, 2, 0, 3, 0},
        {0, 0, 3, 0, 4},
        {0, 0, 0, 4, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->1->2->3->4");
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}.");
}
TEST_CASE("Test functions weighted graph 5"){ 
    Graph g;
    vector<vector<int>> graph5{
        {0, 6, 7, 0, 0},
        {6, 0, 8, -4, 0},
        {7, 8, 0, 0, 5},
        {0, -4, 0, 0, 7},
        {0, 0, 5, 7, 0}};
    g.loadGraph(graph5);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "Negative cycle detected");
    CHECK(Algorithms::negativeCycle(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");
}

TEST_CASE("Test big graph 6")
{
    Graph g;
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, -10, 0, 0, 0, 0, 0, 0},
        {0, -10, 0, 20, 0, 0, 0, 0, 0},
        {0, 0, 20, 0, -30, 0, 0, 0, 0},
        {0, 0, 0, -30, 0, 40, 0, 0, 0},
        {0, 0, 0, 0, 40, 0, -50, 0, 10},
        {0, 0, 0, 0, 0, -50, 0, 60, 0},
        {0, 0, 0, 0, 0, 0, 60, 0, -70},
        {0, 0, 0, 0, 0, 10, 0, -70, 0}};

    g.loadGraph(graph6);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == "5->6->7->8->5");
    CHECK(Algorithms::shortestPath(g, 0, 8) == "Negative cycle detected");
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4, 6, 8}, B={1, 3, 5, 7}.");
    CHECK(Algorithms::negativeCycle(g) == true);
}
TEST_CASE("Test invalid graph 7")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test undirected weighted graph 8")
{
    Graph g;
    vector<vector<int>> graph8 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 2, 0, 0}};
    g.loadGraph(graph8);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "0->2->3");
    CHECK(Algorithms::isContainsCycle(g) == "0->1->0");
    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");
        
}
    TEST_CASE("Test negative Weighted graph 9")
    {
        Graph g;
        vector<vector<int>> graph9 = {
            {0, -5, 2, 0,-7,4},
            {1, 0, 3, 0, 4, 0},
            {2, 3, 0, 4, 0, 0},
            {0, 0, -9, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 2, 0, 0}};
        g.loadGraph(graph9);
        CHECK(Algorithms::isConnected(g) == true);
        CHECK(Algorithms::shortestPath(g, 0, 3) == "Negative cycle detected");
        CHECK(Algorithms::isContainsCycle(g) == "0->1->0");
        CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");
    }
    TEST_CASE("Test")
{
        Graph g;
        vector<vector<int>> graph = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 2, 0, 0}};
        g.loadGraph(graph);
        CHECK(Algorithms::isConnected(g) == true);
        CHECK(Algorithms::shortestPath(g, 0, 3) == "0->2->3");
        CHECK(Algorithms::isContainsCycle(g) == "0->1->0");
        CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");
    
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");
    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == true);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->2->3->4");
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0"); 
    CHECK(Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph4 ={
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {1 ,0, 0, 0, 0}};
        g.loadGraph(graph4);
        CHECK (Algorithms::shortestPath(g,0,4)=="0->1->2->3->4");


    vector<vector<int>> graph5 = {
        {0, 1, 0, 3, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};

        g.loadGraph(graph5);
        CHECK(Algorithms::shortestPath(g,0,4)=="0->3->4");
    
    }


TEST_CASE("for cycles")
{
Graph g;
 vector<vector<int>> graph = {
            {0, 1, 2, 0},
            {0, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 2, 0, 0}};
        g.loadGraph(graph);
        CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

}


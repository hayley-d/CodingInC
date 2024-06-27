//
// Created by hayley on 2024/06/27.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <unordered_map>
#include <unordered_set>


class Graph {
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

public:
    void printGraph();
    Graph();
    bool addEdge(std::string v1, std::string v2);
    bool addVertex(std::string v);
    bool removeEdge(std::string v1, std::string v2);
    bool removeVertex(std::string v);
};



#endif //GRAPH_H

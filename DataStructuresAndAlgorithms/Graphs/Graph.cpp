//
// Created by hayley on 2024/06/27.
//

#include "Graph.h"
#include <iostream>
Graph::Graph() {

}

void Graph::printGraph() {
    std::unordered_map<std::string, std::unordered_set<std::string>>::iterator kvPair = adjList.begin();
    while (kvPair != adjList.end()) {
        std::cout << kvPair->first << ": [";
        std::unordered_set<std::string>::iterator edge = kvPair->second.begin();
        bool first = true;
        while (edge != kvPair->second.end()) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << *edge;
            edge++;
            first = false;
        }
        std::cout << "]" << std::endl;
        kvPair++;
    }
}

bool Graph::addVertex(std::string vertex) {
    if (adjList.count(vertex) == 0) {
        adjList[vertex];
        return true;
    }
    return false;
}

bool Graph::addEdge(std::string vertex1, std::string vertex2) {
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
        adjList.at(vertex1).insert(vertex2);
        adjList.at(vertex2).insert(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeEdge(std::string vertex1, std::string vertex2) {
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
        adjList.at(vertex1).erase(vertex2);
        adjList.at(vertex2).erase(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeVertex(std::string vertex) {
    if (adjList.count(vertex) == 0) return false;
    for (auto otherVertex : adjList.at(vertex)) {
        adjList.at(otherVertex).erase(vertex);
    }
    adjList.erase(vertex);
    return true;
}


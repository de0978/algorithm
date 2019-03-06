//
//  Graph.hpp
//  그래프
//
//  Created by KHJ on 2018. 5. 30..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <queue>
class Graph
{
private:
    int vertice;
    int edge;
public:
    Graph(int vertice=0, int edge=0 ):vertice(vertice),edge(edge){};
    //virtual ~Graph();
    void setVertix(int v){ vertice = v;}
    bool isEmpty() const { return vertice == 0; }
    int getVertices() const { return vertice; }
    int getEdges() const { return edge; }
    virtual int degree(int vertice) const = 0;
    virtual bool existsEdge(int u, int v) = 0;
    virtual void insertVertex(int n) = 0;
//    virtual void deleteVertex(int v) = 0;
    virtual void deleteEdge(int u, int v) = 0;
    virtual void insertEdge(int u, int v) = 0;
    virtual void DFS(int vertice, bool *check)=0;
    virtual void BFS(int vertice, bool *check)=0;
};


#endif /* Graph_hpp */

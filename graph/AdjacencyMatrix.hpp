//
//  AdjacencyMatrix.hpp
//  그래프
//
//  Created by KHJ on 2018. 5. 30..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef AdjacencyMatrix_hpp
#define AdjacencyMatrix_hpp

#include <iostream>
#include "Graph.hpp"
using namespace std;

class AdjacencyMatrix:public Graph{
private:
    bool **array;
public:
    AdjacencyMatrix():Graph(){}
    AdjacencyMatrix(int n):Graph(n){
        array = new bool*[n];

        for ( int i=0; i<n; i++){
            array[i]=new bool[n];
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                array[i][j]=false;
            }
        }
    }
    ~AdjacencyMatrix(){
        for ( int i=0; i<getVertices(); i++){
            delete []array[i];
        }
        delete []array;
    }
    void insertVertex(int n){
        setVertix(n);
        array = new bool*[n];
        
        for ( int i=0; i<n; i++){
            array[i]=new bool[n];
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                array[i][j]=false;
            }
        }

    }
    int degree(int vertice) const {
        int count=0;
        for(int i=0;i<getVertices();i++){
            if(array[vertice][i]==1){
                count++;
            }
        }
        return count;
    }
    bool existsEdge(int u, int v){
        if(array[u][v]==1 && array[v][u] ==1) return true;
        else return false;
    }
//    void insertVertex(int v) = 0;
//    void deleteVertex(int v) = 0;
    void insertEdge(int u, int v){
        array[u][v]=1;
        array[v][u]=1;
    }
    void deleteEdge(int u, int v){
        array[u][v]=0;
        array[v][u]=0;
    }
    void print(){
        for(int i=0; i<getVertices(); i++){
            for(int j=0; j<getVertices(); j++){
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    void DFS(int vertice, bool *check){
        check[vertice]=true;
        cout << vertice ;
        for(int i=0; i<getVertices(); i++){
            if(array[vertice][i]&&check[i]==false){
                DFS(i, check);
            }
        }
    }
    void BFS(int vertice, bool *check){
        check[vertice]=true;
        queue<int> q;
        q.push(vertice);
        while(!q.empty()){
            vertice=q.front();
            cout << q.front();
            q.pop();
            for(int i=0; i<getVertices(); i++){
                if(array[vertice][i]==true&&check[i]==false){
                    q.push(i);
                    check[i]=true;
                }
            }
        }
    }



};

#endif /* AdjacencyMatrix_hpp */

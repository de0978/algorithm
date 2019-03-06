//
//  AdjacencyLists.hpp
//  그래프
//
//  Created by KHJ on 2018. 5. 30..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef AdjacencyLists_hpp
#define AdjacencyLists_hpp

#include <iostream>
#include "Graph.hpp"
#include "List.hpp"
#include <stack>
using namespace std;

class AdjacencyLists:public Graph{
private:
    List *list;
    int *array;
public:
    AdjacencyLists():Graph(){}
    AdjacencyLists(int n):Graph(n){
        list= new List[n];
        array = new int[n*(n-1)/2];
    }
    ~AdjacencyLists(){
//        delete [] list; delete []array;
    }
    int degree(int vertice) const{
        return list[vertice].getSize();
    }
    bool existsEdge(int u, int v){
        Node *data = list[u].getHead();
        while(data->getLink()!=NULL){
            if(data->getData()==v){
                return true;
            }
            data=data->getLink();
        }
        return false;
        
    }
    void insertVertex(int n){
        setVertix(n);
        list= new List[n];
        array = new int[n*(n-1)/2];

    }
    void deleteVertex(int v){}
    void deleteEdge(int u, int v){}
    void insertEdge(int u, int v){
        list[u].insertNode(v);
    }
    void print(){
        for(int i=0;i<getVertices();i++){
            cout << i << "->";
            Node *data = list[i].getHead();
            if(degree(i)==0)
                cout << "NULL";
            for(int j=0; j<degree(i);j++){
                cout << data->getData();
                if(j+1!=degree(i))
                    cout << "-";
                data=data->getLink();
            }
            cout << endl;
        }
    }
    void DFS(int vertice, bool *check){
        check[vertice]=true;
        Node *data = list[vertice].getHead();
        cout << vertice ;
        for(int i=0; i<degree(vertice); i++){
            if(check[data->getData()]==false){
                DFS(data->getData(), check);
            }
            data=data->getLink();
        }
    }
    void BFS(int vertice, bool *check){
        check[vertice]=true;
        queue<int> q;
        
        q.push(vertice);
        while(!q.empty()){
            vertice=q.front();
            Node *data = list[vertice].getHead();
            cout << q.front();
            q.pop();
            for(int i=0; i<degree(vertice); i++){
                if(check[data->getData()]==false){
                    q.push(data->getData());
                    check[data->getData()]=true;
                }
                data=data->getLink();
            }
        }
    }
    
    int* searchCycle(int vertice, bool *check){
        int cnt=0;
        check[vertice]=true;
        queue<int> q;
        
        q.push(vertice);
        while(!q.empty()){
            vertice=q.front();
            Node *data = list[vertice].getHead();
            array[cnt]=q.front();
            cnt++;
            q.pop();
            for(int i=0; i<degree(vertice); i++){
                if(check[data->getData()]==false){
                    q.push(data->getData());
                    check[data->getData()]=true;
                }
                data=data->getLink();
            }
        }
        array[cnt]= -1;
        return array;
    }
    void topologicalSort(){
        int *verPoint = new int[getVertices()];
        bool *check=new bool[getVertices()];
        fill(check,check+getVertices(),true);
        int start;
        for(int i=0; i<getVertices(); i++){
            verPoint[i]=0;
        }
        for(int i=0; i<getVertices();i++){
            Node *data = list[i].getHead();
            for(int j=0; j<degree(i);j++){
                verPoint[data->getData()]+=1;
                data=data->getLink();
            }
        }
        for(start=0; start<getVertices(); start++){
            if(verPoint[start]==0){
                check[start]=false;
                break;
            }
        }
        cout << "가능한 하나의 위상 정렬 : " << start << " " ;
        stack<int> s;
        s.push(-1);
        while(1){
            Node* data = list[start].getHead();
            for(int i=0; i<degree(start); i++){
                verPoint[data->getData()]=verPoint[data->getData()]-1;
                if(verPoint[data->getData()]==0){
                    s.push(data->getData());
                    data=data->getLink();
                }else{
                    data=data->getLink();
                }
            }
            if(s.top()==-1){
                    break;
            }

            start = s.top(); s.pop();
            cout << start << " ";
            check[start]=false;

            

        }
        delete []verPoint; delete []check;
        
    }

    

};
#endif /* AdjacencyLists_hpp */

//
//  MST.hpp
//  그래프
//
//  Created by KHJ on 2018. 6. 5..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef MST_hpp
#define MST_hpp

#include <iostream>
#include "AdjacencyLists.hpp"
struct Data{
    int u,v,cost;
    bool check;
};

class MST{
    int size,cnt;
    Data *data;
    AdjacencyLists *list;
    bool *check;
public:
    MST(int n=0):size(n){
        data=new Data[size*(size-1)/2];
        cnt=0;
        for(int i=0; i<size*(size-1)/2; i++){
            data[i].check=false;
        }
        list = new AdjacencyLists(n);
        check= new bool[size];
        
    }
    ~MST(){
//        delete [] data; delete [] list; delete []check;
    }
    void setVertex(int n){
        size=n;
        data=new Data[size*(size-1)/2];
        cnt=0;
        for(int i=0; i<size*(size-1)/2; i++){
            data[i].check=false;
        }
        list = new AdjacencyLists(n);
        check= new bool[size];
        
    }
    void insertEdge(int u,int v, int cost){
        data[cnt].u=u;
        data[cnt].v=v;
        data[cnt].cost=cost;
        cnt++;
    }
    void sortBycost(){
        Data temp;
        for(int i=0; i<cnt; i++){
            for(int j=0; j<cnt; j++){
                if(data[i].cost<data[j].cost){
                    temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

    bool isCycle(int u, int v){
        int count =0;
        int a=0;
        fill(check,check+size,false);

        int *n = list->searchCycle(u, check);
        while(1){
            if(n[count]==u||n[count]==v){
                a++;
            }
            count++;
            if(n[count]==-1)
                break;
        }
        if(a==2)return true;
        else return false;
    }
    void getMST(){
        sortBycost();
        for(int i=0; i<cnt; i++){
            int u = data[i].u;
            int v = data[i].v;
            if(isCycle(data[i].u, data[i].v)==false){
                data[i].check=true;
                list->insertEdge(u, v);
                list->insertEdge(v, u);
            }
        }
    }
    
    void print(){
        cout << "선택된 간선 ";
        for(int i=0 ; i<cnt; i++){
            if(data[i].check==true){
                cout << "(" << data[i].u << " " << data[i].v << " " << data[i].cost << ")";
            }
        }
        cout << endl;
    }
    void minimumCost(){
        int num = 0;
        int last =0;
        for(int i=0; i<cnt; i++){
            if(data[i].check==true){
                num++;
                last =i;
            }
        }
        int ac=0;
        if(num==size-1){
            cout << "최소비용 신장트리를 구할 수 있음" << endl;
            cout << "최소비용은 ";
            for(int j=0; j<last-1; j++){
                if(data[j].check==true){
                    cout << data[j].cost << "+";
                    ac+=data[j].cost;
                }
            }
            ac+=data[last].cost;
            cout << data[last].cost << "=" << ac << endl;
        }
        else {
            cout << "최소비용 신장트리를 구할수 없음" << endl;
        }
    }
};

#endif /* MST_hpp */

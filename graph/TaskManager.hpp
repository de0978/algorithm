//
//  TaskManager.hpp
//  그래프
//
//  Created by KHJ on 2018. 6. 8..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef TaskManager_hpp
#define TaskManager_hpp

#include <stdio.h>
#include <iostream>
#include "AdjacencyMatrix.hpp"
#include "AdjacencyLists.hpp"
#include "MST.hpp"
#include <fstream>
#include <string>

using namespace std;

class TaskManager{
public:
    char selectMenu(){
        char c;
        cout << "프로그램을 선택하세요 ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit]) : ";
        cin >> c;
        return c;
    }
    string getFileName(){
        string fileName;
        cin >> fileName;
        if(fileName=="quit")exit(0);
        return fileName;
    }
    void search(string fileName){
        AdjacencyMatrix matrix;
        AdjacencyLists list;
        ifstream is;
        is.open(fileName);
        int vertex, u, v;
        is >> vertex;
        matrix.insertVertex(vertex);
        list.insertVertex(vertex);
        while(1){
            is >> u;
            if(u==-1)break;
            is >> v;
            matrix.insertEdge(u, v);
            
            list.insertEdge(u, v);
            list.insertEdge(v, u);
        }
        cout << "입력된 그래프의 인접 행렬 표현" << endl;
        matrix.print();
        bool *check;
        check=new bool[vertex];
        fill(check,check+vertex,false);
        int cnt =1;
        cout << "연결요소" << endl;
        cout << "1. 인접행렬 + DFS" << endl;
        for(int i=0; i<vertex; i++){
            if(check[i]==false){
                cout << "   연결요소" << cnt++ << "-";
                matrix.DFS(i, check);
                cout << endl;
            }
        }
        bool *check1;
        check1=new bool[vertex];
        fill(check1,check1+vertex,false);
        int cnt1 =1;
        cout << endl;
        cout << "연결요소" << endl;
        cout << "2. 인접행렬 + BFS" << endl;
        for(int i=0; i<vertex; i++){
            if(check1[i]==false){
                cout << "   연결요소" << cnt1++ << "-";
                matrix.BFS(i, check1);
                cout << endl;
            }
        }
        cout << endl;
        
        cout << "입력된 그래프의 인접리스트 표현" << endl;
        list.print();
        bool *check2;
        check2=new bool[vertex];
        fill(check2,check2+vertex,false);
        int cnt2 =1;
        cout << "연결요소" << endl;
        cout << "1. 인접리스트 + DFS" << endl;
        for(int i=0; i<vertex; i++){
            if(check2[i]==false){
                cout << "   연결요소" << cnt2++ << "-";
                list.DFS(i, check2);
                cout << endl;
            }
        }
        bool *check3;
        check3=new bool[vertex];
        fill(check1,check1+vertex,false);
        int cnt3 =1;
        cout << endl;
        cout << "연결요소" << endl;
        cout << "2. 인접리스트 + BFS" << endl;
        for(int i=0; i<vertex; i++){
            if(check3[i]==false){
                cout << "   연결요소" << cnt3++ << "-";
                list.BFS(i, check3);
                cout << endl;
            }
        }
        cout << endl;
        delete []check;delete []check1;delete []check2;delete []check3;

    }
    void MCST(string fileName){
        class MST mst;
        ifstream is;
        is.open(fileName);
        int vertex, u, v , cost;
        is >> vertex;
        mst.setVertex(vertex);
        while(1){
            is >> u;
            if(u==-1)break;
            is >> v;
            is >> cost;
            mst.insertEdge(u,v,cost);
        }

            mst.getMST();
            mst.print();
            mst.minimumCost();
    }
    void TS(string fileName){
        AdjacencyLists list;
        ifstream is;
        is.open(fileName);
        int vertex, u, v;
        is >> vertex;
        list.insertVertex(vertex);
        while(1){
            is >> u;
            if(u==-1)break;
            is >> v;
            list.insertEdge(u, v);
        }
//        list.print();
        list.topologicalSort();
        cout << endl;

    }
    
    void run(){
        char c =selectMenu();
        switch (c) {
            case 'S':
                cout << "무방향 그래프가 저장된 파일명을 입력하시오(종료는 quit) :";
                search(getFileName());
                break;
            case 'M':
                cout << "무방향 가중치 그래프가 저장된 파일명을 입력하시오(종료는 quit):";
                MCST(getFileName());
                break;
            case 'T':
                cout << "방향 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
                TS(getFileName());
                break;
            case 'Q':
                cout << "*** 종료 ***" << endl;
                exit(0);
                break;

            default:
                break;
        }
    }
};

#endif /* TaskManager_hpp */

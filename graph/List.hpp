//
//  List.hpp
//  그래프
//
//  Created by KHJ on 2018. 6. 4..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <iostream>
#include "Node.hpp"

class List{
private:
    Node* head;
    int size;
public:
    List(){
        size=0;
        head=NULL;
    }
    ~List(){
        delete [] head;
    }
    
    void insertNode(int vertice){
        Node *data = new Node(vertice);
        if(head==NULL){
            head=data;
        }else{
            data->setLink(head);
            head=data;
        }
        size++;
    }
    void insertNode(int vertice,int cost){
        Node *data = new Node(vertice,cost);
        if(head==NULL){
            head=data;
        }else{
            data->setLink(head);
            head=data;
        }
        size++;
    }
    Node* getHead(){ return head;}
    int getSize(){
        return size;
    }
    
};

#endif /* List_hpp */

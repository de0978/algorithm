//
//  Node.hpp
//  그래프
//
//  Created by KHJ on 2018. 6. 4..
//  Copyright © 2018년 KHJ. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <iostream>
class Node{
private:
    int data;
    Node *link;
public:
    Node(){ link=NULL; }
    Node(int data, Node *link = NULL ):data(data),link(link){}
    Node(int data, int cost, Node *link = NULL):data(data){}
    int getData(){return data;}
    Node* getLink(){return link;}
    void setLink(Node *link){
        this->link=link;
    }
    void setData(int n){
        data=n;
    }
};



#endif /* Node_hpp */

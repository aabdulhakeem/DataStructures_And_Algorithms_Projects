/*
 * Name: Ahmed Abdulhakeem Salah Eldeen
 * Date: 5/22/2024
 */

#include <iostream>
using  namespace std;
#ifndef UNTITLED1_STACK_H
#define UNTITLED1_STACK_H

template <class t>
class Stack {
    struct node{
        t data;
        node* next;
    };
    node* top;
    int s;
public:
    Stack(){
        top = NULL;
        s = 0;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void push(t element){
        node* newNode = new node;
        if (newNode == NULL){
            cerr<<"error allocating memory";
            return;
        }
        newNode->data = element;
        newNode->next = top;
        top = newNode;
        ++s;
    }
    t pop(){

        if (isEmpty()){
            cout<<"Empty Stack\n";
            return t() ;
        }
        node* popItem = top;
        top = top->next;
        t dataa = popItem->data;
        delete popItem;
        popItem = NULL;
        --s;
        return dataa;
    }

    t topElement(){
        if (isEmpty()){
            cout<<"Empty Stack\n";
            return t();
        }
        return top->data;
    }
    int size(){
        return s;
    }
    void print(){
        node* curr = top;
        while (curr!= NULL){
            cout<<'|';
            cout<<' ';
            cout<<curr->data;
            cout<<' ';
            cout<<'|';
            cout<<endl;
            curr = curr->next;
        }
        cout<<"------\n";
    }

};


#endif //UNTITLED1_STACK_H

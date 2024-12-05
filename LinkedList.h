/*
 * Name: Ahmed Abdulhakeem Salah Eldeen
 * Date: 5/30/2024
 */

#ifndef UNTITLED1_LINKEDLIST_H
#define UNTITLED1_LINKEDLIST_H
#include <iostream>
using namespace std;
template <typename t>
struct node{
    t info;
    node *link;
};
template <typename t>
class LinkedList {
    node<t>* head,*last;
    int size;
public:
    LinkedList():head(NULL),last(NULL),size(0){}
    bool found(t element){
        node<t>* curr = head;
        bool found = false;
        while (curr != NULL && !found){
            if (curr->info == element)
                found = true;
            else
                curr = curr->link;
        }
        return found;
    }
    void insertBack(t element){
        node<t>* curr= new node<t>;
        curr->info = element;
        curr->link = NULL;
        if (head == NULL){
            head = last = curr;
        } else {
            last->link = curr;
            last = curr;
        }
        ++size;
    }
    void insertAt(int index, t element){
        if (index >size|| index<0){cout<<"out of range\n";
            return;}
        else if(head == NULL){
            insertBack(element);
            return;
        } else if (index == 0){
            insertFirst(element);
            return;
        }
        node<t>* curr= head,*newNode = new node<t>;

        for (int i = 0; i < index-1; ++i) {
            curr = curr->link;
        }
        newNode->info = element;
        newNode->link = curr->link;
        curr->link = newNode;
        ++size;
    }


    void insertFirst(t element){
        node<t>* newNode = new node<t>;
        newNode->info = element;
        newNode->link = head;
        if (head == NULL){
            last = newNode;
        }
        head = newNode;
        ++size;
    }
    void remove(t element){
        if (head == NULL){cout<<"empty list\n";
        return;}
        node<t> * curr = head,*prev;
        if (element == head->info){
            head = head->link;
            if (head == NULL)
                last = NULL;
            delete curr;
            --size;
            return;
        }
        bool found = false;
        while (curr!=NULL && !found){
            if (curr->info == element){
                found = true;
            }
            else {
                prev = curr;
                curr = curr->link;
            }
        }
        if (found){
            prev->link = curr->link;
            if (curr == last)
                last = prev;
            delete curr;
            --size;
        }
        else
            cout<<"element not found\n";


    }

    void print(){
        node<t>*curr = head;
        while (curr!= NULL){
            cout<<curr->info<<' ';
            curr = curr->link;
        }
        cout<<endl;
    }
    int getSize(){
        return size;
    }

};


#endif //UNTITLED1_LINKEDLIST_H

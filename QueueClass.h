//
// Created by branden on 3/30/2024.
//

#ifndef ASSIGNMENT3_QUEUEIMPLEMENTATION_QUEUECLASS_H
#define ASSIGNMENT3_QUEUEIMPLEMENTATION_QUEUECLASS_H

#endif //ASSIGNMENT3_QUEUEIMPLEMENTATION_QUEUECLASS_H

#include <string>
#include <iomanip>
#include <vector>
#include <iostream>


using namespace std;


//need the add fucntion, the remove function and should be template

template <typename D> // this is going to allow our data to be anything

struct Qnode{
    D data;
    Qnode<D>* next;
    Qnode( D d){
      data = d;
      next = NULL;

    }
};

template <typename D>
class Queue {
private:
    Qnode<D>* front; // this is the front of the LL (First item that should be removed)

    Qnode<D>* rear; // this is the last element in LL (most recently added elem)

public:
    Queue(){
        front= NULL;
        rear = NULL;

    }


    void add(D d){
        //first case is when the q is empty, add the new node and have the head and tail both be that node
        Qnode<D>* temp = new Qnode<D>(d);
        if (rear == NULL){
            front = rear = temp; // if there are no elems make all point to new item
            return;
        }
        //else that means the queue is not empty so make the current rear point to temp then make the new rear temp
        rear->next = temp;
        rear  = temp;


    }


    void del(){
        //removing the head of the LL
        // if the LL is empty then the head will be null (nothing to remove)
        //if there is a head and its not the only item in the list (rear is not == head) remove it and set the new head
        //if the head is not null but its the only element

        if (front == NULL){
            return; // nothing to do so do nothing
        }
        Qnode<D>* temp = front;
        front = front->next; // this moves the current front to the one next in line
        if (front == NULL){ //checking if the next item is the end of the list or not
            //this case runs if the deleted item is hte only one left in the list so update rear
            rear = NULL;

        }
        //cout<<"Deleted: "<<temp->data<<endl;
        delete temp; //free space taken by first node




    }
    bool is_empty(){
        if (front ==  NULL){
            //cout<<"true"<<endl;
            return true;


        }
        else{
            //cout<<"False"<<endl;
            return false;

        }
    }
    D Front(){
        //returns the front of the queue
        if (is_empty()){
            cout<<"there is no front , the list is empty. "<<endl;

            return NULL;
        }
        //cout<<"Front of queue: "<<front->data<<endl;
        return front->data;

    }

    int size(){
        //returns size of queue
        int total_size = 0;

        Qnode<D>* temp = front;
        while(temp){
            total_size += 1;

            temp= temp->next;

        }
        cout<<"Total size: "<<total_size<<endl;
        return total_size;

    }
    void print(){
        Qnode<D>* temp = front;
        cout<<"Printing the Queue"<<endl;
        while(temp){
            cout<<"Data: "<<temp->data<<endl;
            temp= temp->next;

        }
    }
    // put the elem currently at the front of the queue to the rear of the queue.
    void move_to_rear(){
        Qnode<D>* temp = front; // holds real front
        //special cases: if there is only one element in the list do nothing same if its empty
        if (is_empty() ||   front == rear){
            cout<<"This list is either empty or the rear is already front"<<endl;
            return;
        }
        front = front->next;
        rear->next = temp;
        rear = temp;
        rear->next = NULL;
        cout<<"Moved "<<temp->data<<" To the rear and shifted"<<endl;

    }





};


template<typename D>
void insertion_sortQ(Queue<D>& q){
    vector<D> num;

    while(!q.is_empty()) {
        int temp = q.Front();
        num.push_back(temp);
        q.del();

    }

    int i,j,key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++) {
        key = num[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--){ // larger values move right
            if (key < num[i]) {
                num[i + 1] = num[i];
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded)
            num[i + 1] = key; //Put key into its proper location
    }
    for(int i = 0;i< num.size();i++){
        q.add(num[i]);

    }
    cout<<endl<<endl;

    cout<<"queue after sort is: "<<endl;

    q.print();

}

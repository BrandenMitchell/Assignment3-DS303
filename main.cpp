#include <iostream>
#include <vector>

using namespace std;
#include "QueueClass.h"
#include "functions.h"

int main() {
    //GRADER LOOK HERE- there are commented out sections in the functions and in the class that allow you to display to the console for your ease of use
    // just un comment them and youre good.

    //LEAVE COMMENT- BELOW HERE IS THE QUEUE CODE



    Queue<int> q;
    q.is_empty();
    q.Front();
    q.add(30);
    q.add(50);
    q.add(20);
    q.add(40);
    q.add(10);
    q.add(13);
    q.add(15);
    q.add(17);
    q.add(199);
    q.add(210);
    cout<<endl;
    q.print();
    cout<<endl;
    q.del();
    cout<<endl;
    q.del();
    cout<<endl;
    q.is_empty();
    q.size();
    cout<<endl;
    q.print();
    cout<<endl;
    q.Front();
    cout<<endl;
    q.move_to_rear();
    cout<<endl;
    q.print();
    cout<<endl;
    q.Front();
    cout<<endl;


//LEAVE COMMENT- BELOW HERE IS THE LINEAR SEARCH CODE

    vector<int> nums;
    vector<int> vec;

    nums.push_back(9);
    nums.push_back(10);
    nums.push_back(11);
    nums.push_back(12);
    nums.push_back(13);
    nums.push_back(14);
    nums.push_back(13);
    nums.push_back(15);
    int tar;
    cout<<"Enter the desired target: "<<endl;
    cin>>tar;

    linear_search_wrapper( nums,tar); //calling wrapper to make user life better


//LEAVE COMMENT- BELOW HERE IS THE INSERTION SORT CODE

    insertion_sortQ(q);
    cout<<endl<<endl<<endl;
    q.print();






    return 0;
}

//
// Created by branden on 4/1/2024.
// control + d is copy line down


#include "functions.h"





//find the last occurence of given target not the first occurence
//should be recursive
int linear_search(vector<int>& items, int& target, size_t pos_first, int& instance){

    if (pos_first == items.size()){
        if (instance != 0){
            cout<<"Target Found"<<endl;
            cout<<"target: "<<target<<" Index last seen: "<<instance<<endl;

        }
        else
            cout<<"Target not Found"<<endl;

            return -1;

    }
    if (target == items[pos_first]) {
        instance = pos_first;
        return linear_search(items, target, pos_first + 1,instance);
    }
    else{
        return linear_search(items, target, pos_first + 1, instance);
    }


}

int linear_search_wrapper(vector<int>& items,int& target){
    if (items.size() == 0){
        cout<<"list is empty stop trying to break my code "<<endl;
        return -1;

    }
    int instance = 0;

    return linear_search(items,target, 0,instance);

}



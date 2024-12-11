/*
 * Created by: Ahmed Abdulhakeem Salah Eldeen
 * Date: 12/11/2024
 *
 * Chaining Method
      * Chaining
      * Inserting
      * deleting
      * Searching
      * printing
*/

#ifndef UNTITLED1_CHAININGMETHOD_H
#define UNTITLED1_CHAININGMETHOD_H

#include <bits/stdc++.h>
using namespace std;


class ChainingMethod {
    function<int(int,int)> hashingMethod;
    int m;
    vector<vector<int>>hashTable;



    vector<vector<int>> chaining(vector<int>v){
        vector<vector<int>>table(m);
        for (int i = 0; i < v.size(); ++i) {
            int f = hashingMethod(v[i],m);
            table[f].push_back(v[i]);
        }
        return table;
    }



public:

    ChainingMethod(function<int(int,int)> h,int m,vector<int>v){
        this->hashingMethod = h;
        this->m = m;
        hashTable = chaining(v);
    }



    void insert(int element){
        int h = hashingMethod(element,m);
        hashTable[h].push_back(element);
    }



    void erase(int element){
        pair<int,int> exist = search(element);
        if (exist.second == -1){
            cout<<"Element Not Found\n";
        }
        else{
            hashTable[exist.first].erase(hashTable[exist.first].begin() + exist.second);
        }
    }

    pair<int,int> search(int element){
        int h = hashingMethod(element,m);
        for (int j = 0; j < hashTable[h].size(); ++j) {
            if (hashTable[h][j] == element)return {h,j};
        }
        return {h,-1};
    }



    void print(){
        for (int i = 0; i < hashTable.size(); ++i) {
            cout<<i<<": ";
            for (int j = 0; j < hashTable[i].size(); ++j){
                cout<<hashTable[i][j]<<' ';
            }
            cout<<endl;
        }
    }

};

#endif //UNTITLED1_CHAININGMETHOD_H

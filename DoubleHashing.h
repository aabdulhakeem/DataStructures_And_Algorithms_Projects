/*
 * Created by: Ahmed Abdulhakeem Salah Eldeen
 * Date: 12/11/2024
 *
 * Double Hashing
      * doubleHashing
      * Inserting
      * deleting
      * Searching
      * printing
*/

#ifndef UNTITLED1_DOUBLEHASHING_H
#define UNTITLED1_DOUBLEHASHING_H

#include <bits/stdc++.h>
using namespace std;


class DoubleHashing{

private:
    function<int(int,int)> hashingMethod;
    function<int(int)> hashingMethod2;
    int m;
    vector<pair<int,int>>hashingTable;

    vector<pair<int,int>> doubleHashing(vector<int>v){
        vector<pair<int,int>>table(m, {0,0});
        for (int j = 0; j < v.size(); ++j) {
            int h = hashingMethod(v[j],m);
            int h2 = hashingMethod2(v[j]);
            int i = 0;
            int a = h%m;
            while (table[a].second == 1 && i < m){
                ++i;
                a = (h+i*h2)%m;
            }
            if (i == m){
                cout<<"table overflow\n";
                table.clear();
                return table;
            }else
                table[a] = {v[j],1};
        }
        return table;
    }


public:


    DoubleHashing(function<int(int,int)> h, function<int(int)> h2,int m,vector<int>v){
        this->hashingMethod = h;
        this->hashingMethod2 = h2;
        this->m = m;
        hashingTable = doubleHashing(v);
    }


    void insert(int element){
        int h = hashingMethod(element,m);
        int h2 = hashingMethod2(element);
        int i = 0;
        int a = h%m;
        while (hashingTable[a].second == 1 && i < m){
            ++i;
            a = (h+i*h2)%m;
        }
        if (i == m){
            cout<<"table overflow\n";
            return;
        }else
            hashingTable[a] = {element,1};
    }



    void erase(int element){
        int exist = search(element);
        if (exist != -1)hashingTable[exist] = {0,2};
        else cout<<"Element Not Found\n";
        return;
    }



    int search(int element){
        int h = hashingMethod(element,m);
        int h2 = hashingMethod2(element);
        int i = 0;
        int a = h%m;
        while ((hashingTable[a].first != element || hashingTable[a].second == 2) && i < m && hashingTable[a].second != 0){
            ++i;
            a = (h+i*h2)%m;
        }
        if (i == m||!hashingTable[a].second){
            return -1;
        }else return a;
    }



    void print(){
        int j =0;
        for (auto i:hashingTable){
            cout<<j<<": ";
            ++j;
            if (i.second == 0)cout<<"NULL\n";
            else if (i.second == 2)cout<<"Deleted\n";
            else cout<<i.first<<'\n';
        }
    }
};



#endif //UNTITLED1_DOUBLEHASHING_H

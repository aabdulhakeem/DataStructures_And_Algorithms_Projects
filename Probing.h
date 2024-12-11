/*
 * Created by: Ahmed Abdulhakeem Salah Eldeen
 * Date: 12/11/2024
 *
 * Linear & Quadratic Probing Methods
      * probing
      * Inserting
      * deleting
      * Searching
      * printing
*/

#ifndef UNTITLED1_PROBING_H
#define UNTITLED1_PROBING_H


#include <bits/stdc++.h>
using namespace std;


class Probing{

private:
    function<int(int,int)> hashingMethod;
    int m;
    vector<pair<int,int>>hashingTable;
    bool linear;


    vector<pair<int,int>> probing(vector<int>v){
        vector<pair<int,int>>table(m, {0,0});
        for (int j = 0; j < v.size(); ++j) {
            int h = hashingMethod(v[j],m);
            int i = 0;
            int a = h%m;
            while (table[a].second == 1 && i < m){
                ++i;
                a = (h+i*linear+i*i*(!linear))%m;
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


    Probing(function<int(int,int)> h,int m,vector<int>v,bool linear = true){
        linear = linear;
        this->hashingMethod = h;
        this->m = m;
        hashingTable = probing(v);
    }


    void insert(int element){
        int h = hashingMethod(element,m);
        int i = 0;
        int a = h%m;
        while (hashingTable[a].second == 1 && i < m){
            ++i;
            a = (h+i*linear+i*i*(!linear))%m;
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
        int i = 0;
        int a = h%m;
        while ((hashingTable[a].first != element|| hashingTable[a].second == 2) && i < m && hashingTable[a].second != 0){
            ++i;
            a = (h+i*linear+i*i*(!linear))%m;
        }
        if (i == m||!hashingTable[a].second){
            return -1;
        } else if (hashingTable[a].second == 2) return -1;
        else return a;
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
#endif //UNTITLED1_PROBING_H

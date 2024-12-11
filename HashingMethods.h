/*
 * Created by: Ahmed Abdulhakeem Salah Eldeen
 * Date: 12/11/2024
 */

#ifndef UNTITLED1_HASHINGMETHODS_H
#define UNTITLED1_HASHINGMETHODS_H

#include <bits/stdc++.h>
using namespace std;


int divisionMethod(int k,int n){
    return k%n;
}
int hashing(int k){
    return (7-(k%7));
}
int multiplicationMethod(int k,int n,float A){
    int a = A * k;
    return n*(k*A-a);
}
int midSquareMethod(int k,int n){
    int r =0;
    if (n == 1)r = 1;
    int n2 = n;
    while (n2 > 1){
        r++;
        n2/=10;
    }
    k *= k;
    string s = to_string(k);
    if (s.size()%2 != r%2){
        if (r<s.size())++r;
        else --r;
    }
    int l = s.size()/2 - r/2;
    int ri = s.size()/2 + r/2;
    if (ri - l + 1 != r)--ri;
    string s2;
    for (int i = l; i <= ri; ++i) {
        s2+=s[i];
    }
    return stoi(s2)%n;
}
int foldingMethod(int k,int n,int a,bool boundary= false){
    int size = to_string(a).size();
    vector<string>v;
    string s = to_string(k);
    int counter = 0;
    string s2;
    for (int i = 0; i < s.size(); ++i) {
        if (counter == size){
            counter = 0;
            v.push_back(s2);
            s2 = "";
        }
        s2 += s[i];
        ++counter;
    }
    if (s2 != "")v.push_back(s2);
    if (boundary){
        reverse(v[0].begin(),v[0].end());
        if (v.size()>1)reverse(v.back().begin(),v.back().end());
    }
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += stoi(v[i]);
    }
    return sum%n;
}



#endif //UNTITLED1_HASHINGMETHODS_H

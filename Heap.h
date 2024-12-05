/*
 * Name: Ahmed Abdulhakeem Salah Eldeen
 * Date: 10/25/2024
 */


#ifndef UNTITLED1_HEAP_H
#define UNTITLED1_HEAP_H


#define ll long long
#include <vector>
using namespace std;
template<typename t>

class Heap {
    bool isMax;

    ll parent(ll index){
        return (index - 1)/2;
    }
    ll left(ll index){
        return 2 * index + 1;
    }
    ll right(ll index){
        return 2 * index + 2;
    }

    void maxHeapify(ll i,ll n){
        ll l = left(i);
        ll r = right(i);
        ll largest = i;
        if (l < n && v[l]>v[i])
            largest = l;
        if (r < n && v[r]>v[largest])
            largest = r;
        if (largest != i){
            swap(v[i],v[largest]);
            maxHeapify(largest,n);
        }
    }
    void minHeapify(ll i,ll n){
        ll l = left(i);
        ll r = right(i);
        ll smallest = i;
        if (l < n && v[l]<v[i])
            smallest = l;
        if (r < n && v[r]<v[smallest])
            smallest = r;
        if (smallest != i){
            swap(v[i],v[smallest]);
            minHeapify(smallest,n);
        }
    }

    void insertMax(t element){
        v.push_back(element);
        ll i = v.size()-1;
        while (i>0 && v[i]>v[parent(i)]){
            swap(v[i],v[parent(i)]);
            i = parent(i);
        }
    }
    void insertMin(t element){
        v.push_back(element);
        ll i = v.size()-1;
        while (i>0 && v[i]<v[parent(i)]){
            swap(v[i],v[parent(i)]);
            i = parent(i);
        }
    }
protected:

    vector<t>v;



    void heapify(ll i,ll n){
        if (isMax)
            maxHeapify(i,n);
        else
            minHeapify(i,n);
    }
    void buildHeap(){
        ll n=v.size();
        for (ll i = n/2; i >= 0; i--) {
            heapify(i,n);
        }
    }
public:
    Heap(bool max = true){
        vector<t>vec;
        v = vec;
        isMax = max;
        buildHeap();
    }
    explicit Heap(vector<t> vec,bool max= true){
        v = vec;
        isMax = max;
        buildHeap();
    }

    ll size(){
        return v.size();
    }

    void heapSort(){
        ll n =v.size();
        for (int i = n-1; i >= 0; --i) {
            swap(v[0],v[i]);
            heapify(0,i);
        }
    }
    void insert(t element){
        if (isMax)
            insertMax(element);
        else
            insertMin(element);
    }
    t extract(){
        t ret = v[0];
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        heapify(0,v.size());
        return ret;
    }
    void printHeap(){
        for (int i = 0; i < v.size(); ++i) {
            cout<<v[i]<<' ';
        }cout<<endl;
    }

};
template<typename t>
class PriorityQueue : public Heap<t>{
public:
    PriorityQueue(bool reversed = false):Heap<t>(!reversed){}
    explicit PriorityQueue(vector<t>vec,bool reversed = false):Heap<t>(vec,!reversed){}
    t top(){
        return this->v[0];
    }
    t extractTop(){
       return this->extract();
    }
    void push(t element){
        this->insert(element);
    }
    void printQueue(){
        while (this->v.size()>0){
            cout<<this->extractTop()<<' ';
        }
        cout<<endl;
    }
};


#endif //UNTITLED1_HEAP_H

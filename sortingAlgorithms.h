/*
 * Name: Ahmed Abdulhakeem Salah Eldeen
 * Date: 5/22/2024
 */


#include <algorithm>
using namespace std;
#ifndef UNTITLED1_SORTINGALGORITHMS_H
#define UNTITLED1_SORTINGALGORITHMS_H

template <typename t>
void insertionSort(t a[],int n){
    for (int i = 1; i < n; ++i) {
        int j;
        t temp = a[i];
        for (j = i-1; j > -1 && temp < a[j]; --j)
            a[j+1] = a[j];
        a[j+1] = temp;
    }
}


template <typename t>
void selectionSort(t a[],int n){
    for (int i = 0; i < n-1; ++i) {
        int min = i,j;
        for (j = i+1; j < n; ++j)
            if (a[j] < a[min])
                min = j;
        if (min != i)swap(a[i],a[min]);
    }
}

template <typename t>
void bubbleSort(t a[], int n){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n-1; j > i; --j) {
            if (a[j-1] > a[j])
                swap(a[j],a[j-1]);
        }
    }
}
template <typename t>
void shellSort(t a[], int n){
    for (int gap = n/2; gap > 0; gap/=2) {
        for (int i = gap,j; i < n; ++i) {
            t temp = a[i];
            for (j = i-gap; j > -1 && a[j] > temp; j-=gap)
                a[j+gap] = a[j];
            a[j+gap] = temp;
        }
    }
}
template <typename t>
void merge(t a[],int l,int mid,int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    t *left = new t[n1],*right = new t[n2];
    for (int i = 0; i < n1; ++i) {
        left[i] = a[l + i];
    }
    for (int i = 0; i < n2; ++i) {
        right[i] = a[mid + 1 + i];
    }

    int i,j,k;
    i=j=0;
    k = l;
    while (i < n1 && j < n2){
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < n1){
        a[k++] = left[i++];
    }
    while (j < n2){
        a[k++] = right[j++];
    }
}
template <typename t>
void mergeSort(t a[],int l,int r){
    if (l>=r)return;
    int mid = l+(r-l)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
    merge(a,l,mid,r);
}

template <typename t>
int partitioning(t a[],int left,int right){
    t pivotPosition = left + rand()%(right-left+1);
    swap(a[pivotPosition],a[left]);
    t pivot = a[left];
    int i = left;
    for (int j = left + 1; j <=  right; ++j) {
        if (a[j] < pivot)
            swap(a[j],a[++i]);
    }
    if (i != left) swap(a[i], a[left]);
    return i;
}
template <typename t>
void quickSort(t a[] ,int left ,int right){
    if (right <= left) return;
    int pivot = partitioning(a,left,right);
    quickSort(a ,left ,pivot-1);
    quickSort(a ,pivot+1 ,right);
}

#endif //UNTITLED1_SORTINGALGORITHMS_H

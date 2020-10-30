#include<bits/stdc++.h> 
using namespace std; 
  

void compAndSwap(int a[], int i, int j, int dir) 
{ 
    if (dir==(a[i]>a[j])) 
        swap(a[i],a[j]); 
} 
  

void bitonicMerge(int a[], int low, int cnt, int dir) 
{ 
    if (cnt>1) 
    { 
        int k = cnt/2; 
        for (int i=low; i<low+k; i++) 
            compAndSwap(a, i, i+k, dir); 
        bitonicMerge(a, low, k, dir); 
        bitonicMerge(a, low+k, k, dir); 
    } 
} 

void bitonicSort(int a[],int low, int cnt, int dir) 
{ 
    if (cnt>1) 
    { 
        int k = cnt/2; 
  
        // sort in ascending order since dir here is 1 
        bitonicSort(a, low, k, 1); 
  
        // sort in descending order since dir here is 0 
        bitonicSort(a, low+k, k, 0); 
  
        // Will merge wole sequence in ascending order 
        // since dir=1. 
        bitonicMerge(a,low, cnt, dir); 
    } 
} 
  

void sort(int a[], int N, int up) 
{ 
    bitonicSort(a,0, N, up); 
} 
  
int main() 
{ 
    int a[]= {3, 7, 4, 8, 6, 2, 1, 5}; 
    int N = sizeof(a)/sizeof(a[0]); 
  
    int up = 1;   // means sort in ascending order 
    sort(a, N, up); 
  
    printf("Sorted array: \n"); 
    for (int i=0; i<N; i++) 
        printf("%d ", a[i]); 
    return 0; 
} 

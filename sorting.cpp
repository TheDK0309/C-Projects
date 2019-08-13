#include <bits/stdc++.h> 
#include<stdlib.h> 
#include<stdio.h> 
#include <algorithm> 
#include <vector> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  

void bubbleSort(int a[], int size) {
   bool done = false; 
   int pass = 0;      
   int temp;          
 
   while (!done) {
      done = true;
      
      for (int i = 0; i < size - 1; ++i) {
         if (a[i] > a[i+1]) {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            done = false;   
            
         }
      }
   }
}

void insertionSort(int a[], int size) {
   int temp;   // sorting variable
   for (int i = 1; i < size; ++i) {
    for (int prev = 0; prev < i; ++prev) {
         if (a[i] < a[prev]) {
            // insert a[i] at prev, shift the elements down
            temp = a[i];
            for (int shift = i; shift > prev; --shift) {
               a[shift] = a[shift-1];
            }
            a[prev] = temp;
            break;
         }
      }
   }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
	}
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1+ j]; 
	}
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
   
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
       
        int m = l+(r-l)/2; 
  
        
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];   
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than or  
        // equal to pivot  
        if (arr[j] <= pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
         quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
} 

void bucketSort(float arr[], int n) 
{ 
    // 1) Create n empty buckets 
    vector<float> b[n]; 
     
    // 2) Put array elements in different buckets 
    for (int i=0; i<n; i++) 
    { 
       int bi = n*arr[i]; // Index in bucket 
       b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          arr[index++] = b[i][j]; 
}  
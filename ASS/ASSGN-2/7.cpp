// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an 
// inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to 
// count the number of inversions in an array



#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={5, 4, 3, 2, 1}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])count++;
        }
    }
    cout<<count;
}
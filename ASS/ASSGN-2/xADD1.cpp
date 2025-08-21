// Find two numbers in an array whose difference equals K. Given an array arr[] and a positive 
// integer k, the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j]) 
// is equal to k. 



#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1, 4, 1, 4, 5};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int i=0;
    int j=0;
    int count=0;
    while(j<n){
        if(abs(arr[j]-arr[i])<k){
            j++;
        }
        else if(abs(arr[j]-arr[i])==k){
            j++;
            count++;
        }
        else if(abs(arr[j]-arr[i])>k){
            i++;
            j=i+1;
        }
    }
    cout<<count;
}
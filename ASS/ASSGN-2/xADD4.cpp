// Sort an array of 0s, 1s and 2s - Dutch National Flag Problem 
// Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e., 
// put all 0s first, then all 1s and all 2s in last. 

#include<iostream>
using namespace std;
int main(){
    int arr[]={0,0,0,1,0,0,1,1,1,1,0,1,2,2,0,2,1};
    int noo=0;
    int noz=0;
    int notw=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==0) noz++;
        else if(arr[i]==1) noo++;
        else notw++;
    }

    for(int i=0; i<n; i++){
        if(i < noz) arr[i] = 0;
        else if(i < noz + noo) arr[i] = 1;
        else arr[i] = 2;
    }


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}
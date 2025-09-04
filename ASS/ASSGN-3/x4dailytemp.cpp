// Given an array of integers temperatures represents the daily temperatures, return an 
// array answer such that answer[i] is the number of days you have to wait after the ith day to get a 
// warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={73,74,75,71,69,72,76,73};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int ngi[n];
    stack<int> st;
    ngi[n-1]=0;
    st.push(n-1);
    
    for(int i=n-2;i>=0;i--){
        
        //pop
        while(st.size()>0 && arr[st.top()]<arr[i]){
            st.pop();
        }
        
        //ans
        if(st.size()==0) ngi[i]=0;
        else ngi[i]=st.top()-i;
        
        st.push(i);
        
    }
    
    for(int i=0;i<n;i++){
        cout<<ngi[i]<<" ";
    }
    
    
}
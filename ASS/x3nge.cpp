// Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the 
// array in order of their appearance in the array. Note: The Next Greater Element for an element x is 
// the first greater element on the right side of x in the array. Elements for which no greater element 
// exist, consider the next greater element as -1.  


#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<int> st;
int arr[]={ 6, 8, 0, 1, 3};
int n=sizeof(arr)/sizeof(arr[0]);
int nge[n];
nge[n-1]=-1;
st.push(arr[n-1]);
//pop ans push
for(int i=n-2;i>=0;i--){
    //popping all the smaller elements
    while(st.size()>0 && arr[i]>=st.top()){
        st.pop();
    }

    if(st.size()==0) nge[i]=-1;
    else nge[i]=st.top();

    st.push(arr[i]);
}
for(int i=0;i<n;i++){
    cout<<nge[i]<<" ";
}
}
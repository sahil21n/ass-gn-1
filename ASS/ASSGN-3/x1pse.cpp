#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={4,5,2,10,8};
    stack <int> st;
    int n =sizeof(arr)/sizeof(arr[0]);
    int pse[n];
    pse[0]=-1;
    st.push(arr[0]);

    for(int i=1;i<n;i++){
        //pop ans push
        while(st.size()>0 && arr[i]<=st.top()){
            st.pop();
        }

        if(st.size()==0) pse[i]=-1;
        else pse[i]=st.top();

        st.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<pse[i]<<" ";
    }
}
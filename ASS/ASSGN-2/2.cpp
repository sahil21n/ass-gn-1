//bubble sort
#include<iostream>
using namespace std;
int main(){
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        int flag=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){swap(arr[j+1],arr[j]);flag=false;}          
        }
        if(flag==true){break;}
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
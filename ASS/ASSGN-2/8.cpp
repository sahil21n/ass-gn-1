#include<iostream>
#include<algorithm>//no of unique elements
using namespace std;
int main(){
    int arr[]={1,2,3,4,12,1,2,3,4,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int i=0;
    int j=i+1;
    int count=1;
    while(j<n){
        if(i==0 || arr[i]!=arr[i-1]){
            count++;
            i++;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    cout<<count;
}

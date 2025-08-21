#include<iostream>//binary search
using namespace std;
int main(){
    int target=7;
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int hi=n-1;
    int lo=0;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target) {ans=mid;break;}
        if(arr[mid]<target) lo=mid+1;
        else hi=mid-1;
    }

    if(ans!=-1){cout<<ans;}
    else{cout<<"no such element";}
    
    

}
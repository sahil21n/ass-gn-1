//find missing number using binary search
#include<iostream>
using namespace std;
int main(){
   
    int arr[]={0,1,2,3,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int hi=n-1;
    int lo=0;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(mid !=arr[mid]){ans=mid;hi=mid-1;}
        else {lo=mid+1;}

        
        
    }
    cout<<ans;

}
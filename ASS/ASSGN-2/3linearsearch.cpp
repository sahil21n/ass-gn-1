//find missing number.
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    int n=size+1;
    int sums=(n*(n+1))/2;
    int sum=0;
    for(int i=0;i<size;i++){
        sum=sum+arr[i];
    }

    cout<<(sums-sum);

}
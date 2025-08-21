#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,1,23,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);  

    int newArr[n]; 
    int k = 0;     

    for(int i=0; i<n; i++) {
        
        if(i == 0 || arr[i] != arr[i-1]) {
            newArr[k++] = arr[i];
        }
    }

    
    for(int i=0; i<k; i++) {
        cout << newArr[i] << " ";
    }
}

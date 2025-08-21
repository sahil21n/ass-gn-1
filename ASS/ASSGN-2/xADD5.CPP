#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,0,2,3,0,4,5,0};  
    int n = arr.size();
    int z = 0;

    
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) z++;
    }

    
    for (int i = n - 1; i >= 0; i--) {
        int j = i + z; 

        if (j < n) arr[j] = arr[i];

        
        if (arr[i] == 0) {
            z--;
            if (i + z < n) arr[i + z] = 0;
        }
    }

    cout << "new array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;

    return 0;
}

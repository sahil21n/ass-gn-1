#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter rows and columns of matrix: ";
    cin >> n >> m;

    int A[n][m], T[m][n];

    cout << "Enter elements of matrix:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
      
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            T[j][i] = A[i][j];
        }
    }

    cout << "Transpose Matrix:" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

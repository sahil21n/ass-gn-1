#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    int A[n][m];

    cout << "Enter elements of matrix:" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }
       // Sum of each row
    cout << "\nSum of each row:" << endl;
    for(int i=0; i<n; i++){
        int rowSum = 0;
        for(int j=0; j<m; j++){
            rowSum += A[i][j];
        }
        cout << "Row " << i+1 << " = " << rowSum << endl;
    }
    // Sum of each column
    cout << "\nSum of each column:" << endl;
    for(int j=0; j<m; j++){
        int colSum = 0;
        for(int i=0; i<n; i++){
            colSum += A[i][j];
        }
        cout << "Column " << j+1 << " = " << colSum << endl;
    }

    return 0;
}

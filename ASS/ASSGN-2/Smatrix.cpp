#include <iostream>
using namespace std;

#define MAX 20  


void readSparse(int mat[MAX][3]) {
    cout << "Enter total rows, columns and non-zero values: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];

    cout << "Enter row, column and value for each non-zero element:" << endl;
    for (int i = 1; i <= mat[0][2]; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}


void displaySparse(int mat[MAX][3]) {
    cout << "Row\tCol\tVal" << endl;
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << endl;
    }
}


void transposeSparse(int mat[MAX][3], int trans[MAX][3]) {
    trans[0][0] = mat[0][1]; 
    trans[0][1] = mat[0][0]; 
    trans[0][2] = mat[0][2]; 

    int k = 1;
    
    for (int i = 0; i < mat[0][1]; i++) {
        for (int j = 1; j <= mat[0][2]; j++) {
            if (mat[j][1] == i) {  
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}


void addSparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible, dimensions differ!" << endl;
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
        else { 
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
    }
    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }
    C[0][2] = k - 1;
}


void multiplySparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible!" << endl;
        return;
    }

    int B_trans[MAX][3];
    transposeSparse(B, B_trans);

    int k = 1;
    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B_trans[0][2]; j++) {
            if (A[i][1] == B_trans[j][1]) {
                
                int row = A[i][0];
                int col = B_trans[j][0];
                int val = A[i][2] * B_trans[j][2];

                
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (C[x][0] == row && C[x][1] == col) {
                        C[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    C[k][0] = row;
                    C[k][1] = col;
                    C[k][2] = val;
                    k++;
                }
            }
        }
    }
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    C[0][2] = k - 1;
}

int main() {
    int A[MAX][3], B[MAX][3], T[MAX][3], SUM[MAX][3], PROD[MAX][3];

    cout << "Enter first sparse matrix:" << endl;
    readSparse(A);

    cout << "Sparse Matrix A:" << endl;
    displaySparse(A);

    cout << "\nTranspose of A:" << endl;
    transposeSparse(A, T);
    displaySparse(T);

    cout << "\nEnter second sparse matrix:" << endl;
    readSparse(B);

    cout << "Sparse Matrix B:" << endl;
    displaySparse(B);

    cout << "\nAddition (A + B):" << endl;
    addSparse(A, B, SUM);
    displaySparse(SUM);

    cout << "\nMultiplication (A x B):" << endl;
    multiplySparse(A, B, PROD);
    displaySparse(PROD);

    return 0;
}

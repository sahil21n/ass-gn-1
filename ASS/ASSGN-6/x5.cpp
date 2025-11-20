#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;

    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

void displayMatrix(int matrix[][100], int rows, int cols) {
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[100][100]; // static 2D array

    cout << "Enter matrix values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    displayMatrix(matrix, rows, cols);

    // Step 1: Create nodes
    Node* nodes[100][100];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = new Node(matrix[i][j]);
        }
    }

    // Step 2: Link nodes (next, prev, up, down)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // link right (next)
            if (j + 1 < cols)
                nodes[i][j]->next = nodes[i][j + 1];

            // link left (prev)
            if (j - 1 >= 0)
                nodes[i][j]->prev = nodes[i][j - 1];

            // link down
            if (i + 1 < rows)
                nodes[i][j]->down = nodes[i + 1][j];

            // link up
            if (i - 1 >= 0)
                nodes[i][j]->up = nodes[i - 1][j];
        }
    }

    cout << "\n2D Doubly Linked List Created & Linked Successfully!\n";

    // Top-left node is the head of 2D DLL
    Node* head = nodes[0][0];

    return 0;
}

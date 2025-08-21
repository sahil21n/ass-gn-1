#include<iostream>
using namespace std;

int arr[100];  // array
int n = 0;     // current size

void create() {
    cout << "enter number of elements: ";
    cin >> n;
    cout << "enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (n == 0) {
        cout << "array is empty\n";
        return;
    }
    cout << "array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "enter position (0-based): ";
    cin >> pos;
    cout << "enter value: ";
    cin >> val;

    if (pos < 0 || pos > n) {
        cout << "invalid position\n";
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}

void del() {
    int pos;
    cout << "enter position (0-based) to delete: ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "invalid position\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linearsearch() {
    int target, f = -1;
    cout << "enter element to search: ";
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "element found at index " << i << endl;
            f = 1;
            break;
        }
    }
    if (f == -1) cout << "element not found\n";
}

int main() {
    int ch;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "enter choice: ";
        cin >> ch;

        if (ch == 1) create();
        else if (ch == 2) display();
        else if (ch == 3) insert();
        else if (ch == 4) del();
        else if (ch == 5) linearsearch();
        else if (ch == 6) {
            cout << "exiting...\n";
            break;
        }
        else cout << "invalid choice\n";
    }

    return 0;
}

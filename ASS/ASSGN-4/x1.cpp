#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinary(int n) {
    if (n <= 0) return;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();

        cout << curr << endl;

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    generateBinary(n);
    return 0;
}

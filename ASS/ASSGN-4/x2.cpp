#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to get index of minimum element in first 'n' elements
    int getMinIndex(queue<int>& q, int n) {
        int minIndex = -1;
        int minValue = INT_MAX;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int curr = q.front();
            q.pop();

            if (i < n && curr <= minValue) {
                minValue = curr;
                minIndex = i;
            }

            q.push(curr);
        }

        return minIndex;
    }

    // Function to move the min element to rear
    void moveMinToRear(queue<int>& q, int minIndex) {
        int size = q.size();
        int minValue = 0;

        for (int i = 0; i < size; i++) {
            int curr = q.front();
            q.pop();

            if (i == minIndex)
                minValue = curr;
            else
                q.push(curr);
        }

        q.push(minValue);
    }

    // Main sorting function
    void sortQueue(queue<int>& q) {
        for (int i = 1; i <= q.size(); i++) {
            int minIndex = getMinIndex(q, q.size() - i + 1);
            moveMinToRear(q, minIndex);
        }
    }
};

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    Solution s;
    s.sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int countStudents(queue<int> students, stack<int> sandwiches) {
        int rotations = 0;

        while (!students.empty() && !sandwiches.empty()) {
            if (students.front() == sandwiches.top()) {
                students.pop();
                sandwiches.pop();
                rotations = 0; // reset since a sandwich was taken
            } else {
                int front = students.front();
                students.pop();
                students.push(front);
                rotations++;
            }

            // If full rotation without anyone eating, stop
            if (rotations == students.size())
                break;
        }

        return students.size(); // students left who couldn't eat
    }
};

int main() {
    queue<int> students;
    stack<int> sandwiches;

    // Example Input
    students.push(1);
    students.push(1);
    students.push(0);
    students.push(0);

    sandwiches.push(1);
    sandwiches.push(0);
    sandwiches.push(1);
    sandwiches.push(0); // top = 0

    Solution s;
    cout << s.countStudents(students, sandwiches);
    return 0;
}

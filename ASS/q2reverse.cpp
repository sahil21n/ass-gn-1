#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s = "DataStructure";
    stack<char> st;

    // push all characters into the stack
    for(int i=0; i<s.size(); i++) {
        st.push(s[i]);
    }

    // pop and print characters (reverses the string)
    while(st.size() != 0) {
        cout << st.top();
        st.pop();
    }

    return 0;
}



// String Split Challenge 
// You are given a string consisting of lowercase English alphabets. Your task is to determine if 
// it's possible to split this string into three non-empty parts (substrings) where one of these 
// parts is a substring of both remaining parts

#include <iostream>
#include <string>
using namespace std;

bool isSubstring( const string &a,  const string &b) {
    return b.find(a) != string::npos;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            string A = s.substr(0, i + 1);
            string B = s.substr(i + 1, j - i);
            string C = s.substr(j + 1);

            if ((isSubstring(A, B) && isSubstring(A, C)) ||
                (isSubstring(B, A) && isSubstring(B, C)) ||
                (isSubstring(C, A) && isSubstring(C, B))) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}

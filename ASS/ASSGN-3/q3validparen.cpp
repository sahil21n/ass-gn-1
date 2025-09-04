#include<iostream>
#include<stack>
using namespace std;
bool isbalanced(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')' && st.top()=='('){
            st.pop();
        }
        if(st.size()==0 && s[i]==')') return false;
    }

    if(st.size()==0) return true;
    else return false; 
}
int main(){
    string s="((()))((()))(";

    cout<<boolalpha<<isbalanced(s);
    
    
}
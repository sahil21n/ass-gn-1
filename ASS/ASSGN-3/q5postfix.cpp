#include<iostream>
#include<stack>
using namespace std;
int solve(int val1, int val2, char ch) {
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1 * val2;
    else if(ch == '/') return val1 / val2; // assume val2 != 0
    return 0;
}
int main(){
stack<int> val;
    string s="79+4*8/3-";
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            val.push(s[i]-48);
        }
        else{
            char ch=s[i];
            int val2=val.top();
            val.pop();
            int val1=val.top();
            val.pop();

            int ans=solve(val1,val2,ch);
            val.push(ans);
        }
        
    }
    cout<<val.top();
}
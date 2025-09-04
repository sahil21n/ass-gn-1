#include<iostream>
#include<stack>
using namespace std;
//in v1 op v2
//pre op v1 v2
//post v1 v2 op
int priority(char ch){
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/') return 2;
}

string solve(string val1,string val2,char ch){
    string s="";
    s.push_back(ch);
    s+=val1;
    s+=val2;
    return s;
}



int main(){
string s="(7+9)*4/8-3"; 
stack <string> val;
stack <char> op;

for(int i=0;i<s.length();i++){
    if(s[i]>=48 && s[i]<=57){
        val.push(to_string(s[i]-48));
    }

    else{
        if(op.size()==0) op.push(s[i]);

        else if(s[i]=='(') op.push(s[i]);
        else if(op.top()=='(') op.push(s[i]);

        else if(s[i]==')'){

        while(op.top()!='('){
        char ch=op.top();
        op.pop();
        string val2=val.top();
        val.pop();
        string val1=val.top();
        val.pop();
        string ans= solve(val1,val2,ch);
        val.push(ans);

        }
        op.pop();//opening barcket gone;
    }

        else if(priority(s[i])>priority(op.top())) op.push(s[i]);




        else{
            while(op.size()>0 && priority(s[i])<=priority(op.top())){
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=solve(val1,val2,ch);
                val.push(ans);

            }
            op.push(s[i]);
        }
        
    }
}

while(op.size()>0){

    char ch=op.top();
    string val2=val.top();
    val.pop();
    string val1=val.top();
    val.pop();
    string ans=solve(val1,val2,ch);
    val.push(ans);
    op.pop();


}

cout<<val.top();


}
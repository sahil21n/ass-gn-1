#include<iostream>
#include<climits>

using namespace std;
class stack{
    public:
    int arr[5];
    int minarr[5];
    int idx;

    stack(){   
        idx = -1;
        minarr[0] = INT_MAX;
    }



    void push(int val){
        idx++;
        if(idx>=0 && idx<=4){
            arr[idx]=val;
            if(idx == 0) minarr[idx] = val;
            minarr[idx]=min(arr[idx],minarr[idx-1]);
        }

        else cout<<"push not possibe";
    }

    void pop(){
        if(idx>=0 &&idx<=4){
            idx--;
        }
        else cout<<"not possible";

    }

    int getmin(){
        return minarr[idx];
    }

};
int main(){
    stack st;
    st.push(10);
    st.push(100);
    st.push(-45);
    st.push(-3);
    

   cout<< st.getmin();
    
}
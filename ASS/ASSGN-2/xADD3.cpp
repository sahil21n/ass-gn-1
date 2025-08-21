// String Anagrams  
// Given two strings str1 and str2, determine if they form an anagram pair.  
// Note: Two strings are considered anagrams if one string can be rearranged to form the other 
// string. 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



int main() {
    string s,a;
    cin >>s;
    cin >>a;
    
    sort(s.begin(),s.end());
    sort(a.begin(),a.end());

    if(s==a){
        cout<<"they are anagrams";
    }
    else{
        cout<<"they are not anagrams";
    }


    
    
}

// (a) Write a program to concatenate one string to another string. 
// (b) Write a program to reverse a string. 
// (c) Write a program to delete all the vowels from the string. 
// (d) Write a program to sort the strings in alphabetical order. 
// (e) Write a program to convert a character from uppercase to lowercase. 
#include<iostream>
using namespace std;
string concat(string str,string s){
    return str+s;
}
 string reverse(string str){
    int i=0;
    int j=str.size()-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
    return str;
}
string NoVowels(string s){
    string p= " ";
    for(int i=0;i<s.size();i++){
        if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
            p=p+s[i];
        }
        
    }
    return p;
}
void sorts(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
char toLowerCase(char ch) {
    
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32; 
    }
    return ch; 
}

int main(){
  cout<<  concat("sahil","avi")<<endl;
  cout<<  reverse("sahil");
  cout<<  NoVowels("sahil")<<endl;
  char arr[]={'a','b','c','d'};
  int n=sizeof(arr) / sizeof(arr[0]);
  sorts(arr,n);

 cout<< toLowerCase('A');





}
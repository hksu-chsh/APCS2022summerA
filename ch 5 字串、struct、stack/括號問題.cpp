#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> stk;
    int res = 0;
    for(auto i:s){
        if(i == '('){
            stk.push(i);
        }
        else{
            if(stk.empty()){
                res = 0;
                break;
            }
            stk.pop();
            res++;
        }
    }
    cout << (stk.empty() ? res : 0) << endl;
}
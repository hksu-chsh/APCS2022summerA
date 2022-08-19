#include<bits/stdc++.h>
using namespace std;
string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                  "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
unordered_map<string, char> code;
void words(string s){
    size_t alphabet = s.find("_");
    while(alphabet != string::npos){
        cout << code[s.substr(0, alphabet)];
        s = s.substr(alphabet + 1);
        alphabet = s.find("_");
    }
    cout << code[s.substr(0, alphabet)];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<26;i++){
        code[morse[i]] = (char)('A' + i);
    }
    string s;
    cin >> s;
    size_t space = s.find("__");
    while(space != string::npos){
        words(s.substr(0, space));
        s = s.substr(space + 2);
        space = s.find("__");
        cout << " ";
    }
    words(s);
}
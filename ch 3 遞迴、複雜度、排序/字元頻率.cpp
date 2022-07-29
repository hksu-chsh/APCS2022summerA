#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    string s;
    while(getline(cin, s)){
        map<int, int> m;
        vector<pair<int, int>> v;
        for(int i = 0;i<s.length();i++){
			m[s[i]]++;
        }
        for(auto i : m){
            v.push_back({i.first, i.second});
        }
        sort(v.begin(),v.end(),cmp);

        for(auto i : v){
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
    }
}
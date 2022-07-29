#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int step = 0;
void binary_search1(int L, int R, int target){
    while(L <= R){
        int M = (L + R) / 2;
        step++;
        if(v[M] == target){
            cout << M << " " << step << endl;
            return;
        }
        if(v[M] > target){
            R = M - 1;
        }
        else{
            L = M + 1;
        }
    }
    cout << "not found " << step;
}
void binary_search2(int L, int R, int target){
    if(L > R){
        cout << "not found " << step;
        return;
    }
    int M = (L + R) / 2;
    step++;
    if(v[M] == target){
        cout << M << " " << step << endl;
    }
    else if(v[M] > target){
        binary_search2(L, M - 1, target);
    }
    else{
        binary_search2(M + 1, R, target);
    }
}
int main(){
    int n;
    cin >> n;
    v.resize(n);
    for(auto &i:v){
        cin >> i;
    }
    int target;
    cin >> target;
    binary_search2(0, n - 1, target);
}
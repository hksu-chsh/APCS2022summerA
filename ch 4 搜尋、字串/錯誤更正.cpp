#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n && n != 0){
        int a[n][n] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
            }
        }
        int row[n] = {0};
        int col[n] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }
        int r = 0, c = 0;
        for(int i=0;i<n;i++){
            if(row[i] % 2 == 1){
                r++;
            }
        }
        for(int i=0;i<n;i++){
            if(col[i] % 2 == 1){
                c++;
            }
        }
        if(r == 0 && c == 0){
            cout << "OK" << endl;
        }
        else if(r != 1 || c != 1){
            cout << "Corrupt" << endl;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(row[i] % 2 == 1 && col[j] % 2 == 1){
                        cout << "Change bit (" << i+1 << "," << j+1 << ")" << endl;
                    }
                }
            }
        }
    }
}
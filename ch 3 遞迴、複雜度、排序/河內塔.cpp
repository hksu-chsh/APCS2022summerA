#include <bits/stdc++.h>
using namespace std;
void hanoi(int from, int buffer, int to, int disk, int ring){
    if(disk == 1) cout << "Ring " << ring << " from " << from << " to " << to << endl;
    else{
        hanoi(from, to, buffer, disk - 1, ring - 1);
        hanoi(from, buffer, to, 1, ring);
        hanoi(buffer, from, to, disk - 1, ring - 1);
    }
}
int main(){
    int n;
    cin >> n;
    hanoi(1, 2, 3, n, n);
}
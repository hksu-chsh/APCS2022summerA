#include<bits/stdc++.h>
using namespace std;
struct Player{
    string ID;
    string cards[13];
    int pos = 0;
};
int main(){
	Player p[4];
	for(int i=0;i<4;i++){
        string s;
        cin >> s;
        if(s == "A"){
            p[0].ID = s;
            for(int j=0;j<13;j++){
                cin >> p[0].cards[j];
            }
        }
        else if(s == "B"){
            p[1].ID = s;
            for(int j=0;j<13;j++){
                cin >> p[1].cards[j];
            }
        }
        else if(s == "C"){
            p[2].ID = s;
            for(int j=0;j<13;j++){
                cin >> p[2].cards[j];
            }
        }
        else{
            p[3].ID = s;
            for(int j=0;j<13;j++){
                cin >> p[3].cards[j];
            }
        }
	}
	int dealer = 0, current = 0, order = 1;
	while(true){
        int c = p[dealer].pos;
        string action = p[dealer].cards[c];
        if(action == "A"){
            current = 0;
        }
        else if(action == "2"){
            current += 2;
        }
        else if(action == "3"){
            current += 3;
        }
        else if(action == "4"){
            order = -order;
        }
        else if(action == "5"){}
        else if(action == "6"){
            current += 6;
        }
        else if(action == "7"){
            current += 7;
        }
        else if(action == "8"){
            current += 8;
        }
        else if(action == "9"){
            current += 9;
        }
        else if(action == "10"){
            if(current < 90){
                current += 10;
            }
            else{
                current -= 10;
            }
        }
        else if(action == "J"){}
        else if(action == "Q"){
            if(current < 80){
                current += 20;
            }
            else{
                current -= 20;
            }
        }
        else if(action == "K"){
            current = 99;
        }
        p[dealer].pos++;
        if(current > 99){
            cout << p[dealer].ID << endl << 13 - p[dealer].pos << endl;
            break;
        }
        else if(p[dealer].pos == 13){
            cout << p[dealer].ID << endl << current << endl;
            break;
        }
        dealer = (dealer + 4 + order) % 4;
	}
}
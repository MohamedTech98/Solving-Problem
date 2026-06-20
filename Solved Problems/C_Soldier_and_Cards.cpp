#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n; cin >> n;
    queue<int> player1;
    queue<int> player2;
    int k1; cin >> k1;
    for(int i = 0;i < k1;i++) {
        int val; cin >> val;
        player1.emplace(val);
    }
    int k2; cin >> k2;
    for(int i = 0;i < k2;i++) {
        int val; cin >> val;
        player2.emplace(val);
    }
    int fight = 0;
    int winner = -1;
    set<pair<queue<int>,queue<int>>> status;
    while(!player1.empty() && !player2.empty()) {
        status.emplace(make_pair(player1,player2));
        fight++;
        int card1 = player1.front();
        player1.pop();
        int card2 = player2.front();
        player2.pop();
        // cout << card1 << '-' << card2 << endl; 
        if(card1 > card2) {
            player1.emplace(card2);
            player1.emplace(card1);
        }
        if(card2 > card1) {
            player2.emplace(card1);
            player2.emplace(card2);
        }

        if(status.count({player1,player2})) {
            cout << -1 << endl;
            return 0;
        }

        if(player1.empty()) {
            winner = 2;
        } 

        if(player2.empty()) {
            winner = 1;
        }
    }
    cout << fight << " " << winner << endl;
    return 0;
}
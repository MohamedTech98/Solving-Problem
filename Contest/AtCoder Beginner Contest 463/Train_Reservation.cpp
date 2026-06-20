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
    char pos; cin >> pos;
    vector<string> seats(n);
    for(int i = 0;i < n;i++) {
        cin >> seats[i];
    }

    for(int i = 0;i < n;i++) {
        if(seats[i][pos - 'A'] == 'o') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
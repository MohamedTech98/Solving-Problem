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
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        int v = -1;
        for(int bit = 31; bit >= 1;bit--) {
            if(((x>>bit) & 1) == 1) {
                v = (1 << bit) - 1;
                break;
            }
        }
        // cout << v << endl;
        if(v == -1) {
            cout << -1 << endl;
        } else {
            int y = v ^ x;
            if(y + x > v && v + x > y && v + y > x) {
                cout <<  v << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
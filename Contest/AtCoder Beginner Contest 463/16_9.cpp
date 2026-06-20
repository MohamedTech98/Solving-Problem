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
    int x,y; cin >> x >> y;
    if(x < 16 || y < 9) {
        cout << "No" << endl;
    }
    else if(x % 16 != 0 || y % 9 != 0) {
        cout << "No" << endl;
    }
    else if(x / 16 == y / 9) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
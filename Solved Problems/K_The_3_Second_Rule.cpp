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
    int x,y; cin>>x>>y;
    int cost = x + y;
    if(y == 3) {
        cost -= y;
    }
    if(x == 3) {
        cost -= y;
    }
    cout<<cost<<endl;
    return 0;
}
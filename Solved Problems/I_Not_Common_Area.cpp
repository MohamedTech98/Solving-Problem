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
    ll h1,h2,w1,w2;
    cin>>h1>>w1>>h2>>w2;
    ll area1 = h1 * w1;
    ll area2 = h2 * w2;
    if(area1 > area2 && min(h1,w1) >= min(h2 , w2)&& max(h1,w1) >= max(h2 , w2)) {
        cout<<area1 - area2<<endl;
    } else if(area1 <= area2 &&  min(h1,w1) <= min(h2 , w2)&& max(h1,w1) <= max(h2 , w2)) {
        cout<<area2 - area1<<endl;
    }
    else {
        cout<<-1<<endl;
    }
    return 0;
}
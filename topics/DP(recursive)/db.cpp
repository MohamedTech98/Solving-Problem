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

const int N = 101,dw = 1e5 + 2;

int n,W;
vector<int> weights;
vector<int> values;
ll db[N][dw];
ll go(int ind,int sum) {
    if(sum > W) {
        return -1e9;
    }
    if(ind >= n) return 0;

    if(db[ind][sum] != -1) {
        return db[ind][sum];
    }
    ll ch1 = go(ind + 1,sum + weights[ind]) + values[ind]; // take
    ll ch2 = go(ind + 1,sum); // leave

    return db[ind][sum] = max(ch1,ch2);
}

int main() {
    ana_Yano;
    cin>>n>>W;
    weights.resize(n);
    values.resize(n);
    for(int i = 0;i<n;i++) {
        cin>>weights[i]>>values[i];
    }
    memset(db,-1,sizeof db);
    cout<<go(0,0)<<endl;
    return 0;
}
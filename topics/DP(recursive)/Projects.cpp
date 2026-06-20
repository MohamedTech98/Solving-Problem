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
 
int n; 
vector<int> start;
vector<int> finish;
vector<int> reward;

const int N = 4e5 + 7;
ll dp[N];
vector<vector<pair<int,int>>> days(N);
 
map<int,int> compress;
 
int max_day;
 
void coordinate_comparsion() {
    for(int i = 0 ; i < n ; i++) {
        compress[start[i]];
        compress[finish[i]];
    }
 
    int ind = 1;
 
    for(auto &[day,_] : compress) {
        compress[day] = ind++;
    }
    max_day = ind + 1;
 
    for(int i = 0 ; i < n ; i++) {
        int s = compress[start[i]];
        int f = compress[finish[i]];
        days[s].push_back({f , reward[i]});
    }
}
 
ll calc(int day) {
 
 
    if(day >= max_day) {
        return 0;
    }
 
    // if(!days[day].first) {
    //     return calc(day + 1); 
    // }
    if(~ dp[day]) {
        return dp[day];
    }
 
    ll attend = 0;
 
    attend = calc(day + 1);
    for(auto &vec : days[day]) {
        attend = max(attend,calc(vec.first + 1) + vec.second);
    }
    return dp[day]  = attend;
}
 
int main() {
    ana_Yano;
    cin>>n;
    start.assign(n,0);
    finish.assign(n,0);
    reward.assign(n,0);
    for(int i = 0;i<n;i++) {
        cin>>start[i]>>finish[i]>>reward[i];
    }
    memset(dp,-1,sizeof dp);
 
    coordinate_comparsion();
    cout << calc(1) << endl;
 
    return 0;
}
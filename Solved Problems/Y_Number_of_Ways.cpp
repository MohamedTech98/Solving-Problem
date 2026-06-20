// #include<iostream>
// #include<vector>
// #include<algorithm>
#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std; 
int ans = 0 ;
void solve(int cur,int end) {
    if(cur>=end) {
        if(cur==end) {ans++;}
        else {return ;}
    }
    solve(cur + 1,end);
    solve(cur + 2,end);
    solve(cur + 3,end);
}

int main() {
    ana_Yano;
    int start,end;
    cin>>start>>end;
    solve(start,end);
    cout<<ans;
    return 0 ;
}
// Link problem ->  [https://cses.fi/problemset/task/1068]
#include<iostream>
#include<vector>
#define ll long long
#define endl '\n'
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
// vector<int> ans;
void solve(ll n) {
    cout<<n<<" ";
    if(n==1) {
        return;
    }
    if(n%2==0) {
        solve(n/2);
    }
    else {
        solve(3*n+1);
    }
}
int main() {
    ana_Yano;
    int n; cin>>n;
    solve(n);
    return 0;
}

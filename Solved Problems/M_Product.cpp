#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
int n;ll x;
int ans=  0;
vector<vector<int>>balls;

void fun(int i ,ll product) {
    if(i==n) {
        if(product==x)
            ans++;
        return;
    }
    for(int j = 0;j<balls[i].size();j++) {
        if(product > x / balls[i][j]) {
            continue;
        }
        fun(i + 1,product * balls[i][j]);
    }
}
int main() {
    ana_Yano;
    cin>>n>>x;
    balls.resize(n);
    for(int i = 0;i<n;i++) {
        int l; cin>>l;
        while(l--) {
            int val; cin>>val;
            balls[i].push_back(val);
        }
    }
    fun(0,1);
    cout<<ans;
    return 0;
}
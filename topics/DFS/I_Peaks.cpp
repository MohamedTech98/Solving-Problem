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
    int n,m; cin>>n>>m;
    vector<vector<int>> nodes(n + 1);
    vector<int> val(n + 1);
    for(int i = 1;i<=n;i++) {
        cin>>val[i];
    }
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        bool good = true; 
        for(int j = 0;j<nodes[i].size();j++) {
            if(val[i] > val[nodes[i][j]]) {
                // cout<< i <<" "<< nodes[i][j]<<endl;
                // ans++;
                good = true;
                // break;
            }
            else {
                good =false;
                break;
            }
        }
        if(good) 
            ans++;
    }
    cout<< ans << endl;
    return 0;
}
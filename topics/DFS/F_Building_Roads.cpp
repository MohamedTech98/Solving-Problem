#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
int k = 0;
map<int,vector<int>> ans;
vector<vector<int>> nodes;
vector<bool> visit;

void DFS(int node) {
    visit[node] = 1;
    for(int i = 0;i<nodes[node].size();i++) {
        if(visit[nodes[node][i]] == 0) {
            ans[k].push_back(nodes[node][i]);
            DFS(nodes[node][i]);
        }
    }
}

int main() {
    int n,m; cin>>n>>m;
    nodes.resize(n + 1);
    visit.resize(n + 1 , 0);
    for(int i = 1,u,v;i<=m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) {
        // cout<< k << endl;
        if(visit[i]==0) {
            k++;
            ans[k].push_back(i);
            DFS(i);
        }
    }
    if(k - 1 == 0) {
        cout<<0<<endl;
    }
    else {
        cout<< k - 1 <<endl;
        // cout<< ans.size()<<endl;
        for(int i = 1;i<ans.size();i++) {
            cout<<ans[i].at(0)<<" "<<ans[i + 1].at(0)<<endl;
        }
    }
    return 0;
}
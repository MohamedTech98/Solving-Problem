#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
vector<vector<int>> nodes;
vector<bool> visited;
// int path = 1;
// map<int,vector<int>> ans;
vector<int> path;
vector<vector<int>> ans;
vector<bool> take;
void DFS(int node) {
    visited[node] = 1;
    bool is_leaf = true;
    if(take[node]==0) {
        take[node] = 1;
        path.push_back(node);
    }
    for(int i = 0;i<nodes[node].size();i++) {
        if(visited[nodes[node][i]]==0 ){ 
            is_leaf = false;
            DFS(nodes[node][i]);
        }
    }
    if(is_leaf) {
        ans.push_back(path);
        path.clear();
    }
}
int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        nodes.assign(n + 1,vector<int>());
        visited.assign(n + 1,0);
        take.assign(n + 1,0);
        int root;
        for(int i = 1,p;i<=n;i++) {
            cin>>p;
            if(p==i) {
                root = p;
                continue;
            }
            nodes[p].push_back(i);
            nodes[i].push_back(p);
        }
        DFS(root);
        cout<< ans.size() << endl;
        for(int i = 0;i<ans.size();i++) {
            cout<< ans[i].size() << endl;
            for(int j = 0;j < ans[i].size();j++) {
                cout<<ans[i][j]<< " ";
            }
            cout<< endl;
        }
        cout<< endl;
        ans.clear();
    }
    return 0;
}
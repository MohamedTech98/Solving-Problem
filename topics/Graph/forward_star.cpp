#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
int n,m; 
const int N = 1e6 + 1,M = 1e6 + 1;

// vector<int> head,to,nxt;
int head[N],to[M],nxt[M];
int ne = 0;
void add_edge(int u,int v) {
    to[ne] = v; // child of node u
    nxt[ne] = head[u]; // the next edge you visit (this edge connect anther child with node u)
    head[u] = ne++;
}

vector<bool> vis;

void dfs(int node) {
    vis[node] = 1;
    cout << node << " ";
    for(int e = head[node];e != -1;e = nxt[e]) {
        if(! vis[to[e]]) {
            dfs(to[e]);
        }
    }
}

int main() {
    ana_Yano;
    cin>>n>>m;
    memset(head,-1,n * sizeof(head[0]));
    // head.assign(n + 1,-1);
    // to.assign(2 * m + 1,0);
    // nxt.assign(2 * m + 1,0);
    vis.assign(n + 1,0);
    for(int i = 0,u,v;i < m;i++) {
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    // for(int e = head[1];e != -1;) {
    //     cout << to[e] << endl;
    //     e = nxt[e];
    // }
    dfs(1);
    return 0;
}
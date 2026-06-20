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

vector<vector<int>> nodes;
vector<int> levels;
vector<bool> visited;

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    levels[start] = 0;

    int color1 = 1, color2 = 0;
    int size = 1;

    bool is_bipartite = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int ch : nodes[cur]) {
            if(!visited[ch]) {
                visited[ch] = 1;
                levels[ch] = levels[cur] ^ 1; // 0/1 coloring

                if(levels[ch] == 0) color1++;
                else color2++;

                size++;
                q.push(ch);
            }
            else if(levels[ch] == levels[cur]) {
                is_bipartite = false;
            }
        }
    }

    if(is_bipartite)
        return max(color1, color2);
    else
        return 0;
}


int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int n,m; cin>>n>>m;
        nodes.assign(n + 1,vector<int>());
        levels.assign(n + 1,0);
        visited.assign(n + 1,0);
        for(int i = 0,u,v;i<m;i++) {
            cin>>u>>v;
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        int ans = 0;
        for(int i = 1;i<=n;i++) {
            if(visited[i] == 0) {
                ans += bfs(i);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
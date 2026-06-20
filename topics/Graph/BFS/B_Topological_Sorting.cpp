#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> nodes;
vector<int> indegree;
vector<int> ans;
int n,m;

void bfs() {
    priority_queue<int,vector<int>,greater<int>> done;
    for(int i = 1;i<=n;i++) {
        if(indegree[i] == 0) {
            done.emplace(i);
        }
    }
    while(! done.empty()) {
        int cur = done.top();
        ans.push_back(cur);
        done.pop();
        for(auto ch : nodes[cur]) {
            indegree[ch]--;
            if(indegree[ch] == 0) {
                done.emplace(ch);
            }
        }
    }
}

int main() {
    ana_Yano;
    cin>>n>>m;
    nodes.resize(n + 1,vector<int>());
    indegree.resize(n + 1,0);
    for(int i = 0,u,v;i<m;i++) {
        cin>>u>>v;
        nodes[u].push_back(v);
        indegree[v]++;
    }
    bfs();
    if(ans.size() < n) {
        cout<<"Sandro fails." << endl;
    }
    else { 
        for(int task : ans) {
            cout<< task << " ";
        }
    }
    return 0;
}
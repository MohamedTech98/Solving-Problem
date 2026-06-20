#include<iostream>
#include<vector>

using namespace std;

int n,m,ans = 0;
vector<vector<int>> nodes;
vector<int> is_cat;

void DFS(int node,int parent,int cats){

    if(is_cat[node])
        cats++;
    else
        cats = 0;

    if(cats > m)
        return;

    bool leaf = true;

    for(auto ch : nodes[node]){
        if(ch == parent) continue;

        leaf = false;
        DFS(ch,node,cats);
    }

    if(leaf)
        ans++;
}

int main(){

    cin>>n>>m;

    nodes.resize(n+1);
    is_cat.resize(n+1);

    for(int i=1;i<=n;i++)
        cin>>is_cat[i];

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    DFS(1,0,0);

    cout<<ans<<endl;
}
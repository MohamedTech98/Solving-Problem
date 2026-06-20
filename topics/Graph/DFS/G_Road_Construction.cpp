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
    ana_Yano;
    int n,m; cin>>n>>m;
    vector<bool> node(n + 1, 0);
    for(int i = 1,u,v;i<=m;i++) {
        cin>>u>>v;
        node[u] = 1;
        node[v] = 1;
    }
    int centre;
    for(int i = 1;i<=n;i++) {
        if(node[i]==0) {
            centre = i;
            break;
        }
    }
    cout<< n - 1<<endl;
    for(int i = 1;i<=n;i++) {
        if(i==centre) {
            continue;
        }
        cout<<centre<<" "<<i<<endl;
    }

    return 0;
}
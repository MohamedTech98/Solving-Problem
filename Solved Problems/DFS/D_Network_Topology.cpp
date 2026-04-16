#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    vector<int> nodes(n + 1);
    for(int i = 1,u,v;i<=m;i++) {
        cin>>u>>v;
        nodes[u]++;nodes[v]++;
    }
    // Bus
    for(int i = 1,check = 2;i<=n;i++) {
        if(nodes[i] > 2) {
            break;
        }
        if(nodes[i] ==1 && check !=0) {
            check--;
        }
        // cout<<check<<"***\n";
        if(i==n && check ==0) {
            cout<<"bus topology"<<endl;
            return 0;
        }
    }
    // ring 
    for(int i = 1;i<=n;i++) {
        if(nodes[i] !=2) {
            break;
        }
        if(i == n) {
            cout<<"ring topology"<<endl;
            return 0;
        }
    }
    // Star 
    for(int i = 1,check = n - 1;i<=n;i++) {
        if(nodes[i]==1 && check != 0) {
            check--;
        }
        if(i==n && check== 0) {
            cout<<"star topology"<<endl;
            return 0;
        }
    }
    cout<<"unknown topology"<<endl;

    return 0;
}
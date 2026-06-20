#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
const int N = 10;



struct DSU {
    vector<int> parent;
    int ncmp,sets[N],pos[N];
    int tail[N],nxt[N];
    DSU(int n) {
        parent.assign(n + 1,-1);
        iota(sets,sets + n,0);
        iota(pos,pos + n,0);
        iota(tail,tail + n,0);
        ncmp = n;
        memset(nxt,-1,n * sizeof(nxt[0]));
    }
    int find(int node) {
        if(parent[node] < 0) {
            return node;
        }
        return parent[node] = find(parent[node]); // Path comparsson
    }
    bool join(int x,int y) {
        int a = find(x),b = find(y);

        if(a == b) {
            return false; // the same root so the same set
        }

        if(-parent[a] < -parent[b]) {
            swap(a,b);
        }
        parent[a] += parent[b]; // new size after merge 
        parent[b] = a;
        ////////////////////
        int &t = tail[a]; // point to tail of big tree 
        nxt[t] = b; // connnect tail of big tree with small tree
        t = tail[b]; // After connect update tail of tree to tail small tree
        int p = pos[b];
        sets[p] = sets[--ncmp]; // remove tree small
        pos[sets[p]] = p;
        return true;
    }
    vector<int> getcmp(int node) {
        int root = find(node); // root of component
        vector<int> ret;
        ret.reserve(-parent[root]); // vector size of element in tree
        for(int e = root;e != -1;e = nxt[e]) {
            ret.push_back(e);
        }
        return ret;
    }
};

int main() {
    ana_Yano;
    return 0;
}
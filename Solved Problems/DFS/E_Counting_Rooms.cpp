// #include<bits\stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};
vector<vector<char>> grid;
vector<vector<bool>> visited;
int n,m;

void DFS(int i,int j) {
    visited[i][j] = 1;
    for(int d = 0;d<4;d++) {
        int a = i + di[d];
        int b = j + dj[d];
        if(a <  n && a >= 0 && b < m && b >=0 && visited[a][b]==0 && grid[a][b] == '.' ) {
            DFS(a , b);
        }
    }
    
    
}

int main() {
    ana_Yano;
     cin>>n>>m;
    grid.resize(n,vector<char>(m));
    visited.resize(n,vector<bool> (m));
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            cin>> grid[i][j];
        }
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(visited[i][j]==1) {
                continue;
            }
            if(grid[i][j]=='.') {
                DFS(i , j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
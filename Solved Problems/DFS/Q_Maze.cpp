#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
vector<string> maze;
vector<vector<bool>> visited;
int n,m,k;
int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};
void DFS(int x,int y,int min_val = 1000) {
    visited[x][y] = 1;
    int connect = 0;
    for(int d = 0;d<4;d++) {
        if((x + di[d] >= n || x + di[d] < 0) || (y + dj[d] >= m || y + dj[d] < 0) ) {
            continue;
        }
        if(maze[x + di[d]][y + dj[d]] == '.') {
            connect++;
        }
        if(maze[x + di[d]][y + dj[d]] == '.' && visited[x + di[d]][y + dj[d]] == 0) {
            DFS(x + di[d],y + dj[d],min(min_val,min_val));
        }
    }
    if(connect <= min_val && k != 0) {
        maze[x][y] = 'X';
        k--;
    }
}
int main() {
    ana_Yano;
    cin>>n>>m>>k;
    maze.resize(n);
    visited.assign(n,vector<bool>(m));
    for(int i = 0;i<n;i++) {
        cin>>maze[i];
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(maze[i][j] == '.') {
                DFS(i,j);
            }
        }
    }
    for(auto row : maze) {
        for(auto col : row) {
            cout<<col;
        }
        cout<< endl;
    }
    return 0;
}
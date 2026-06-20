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
// vector<vector<int>> nodes;
vector<vector<bool>> visited;
vector<vector<int>> levels;
int di[] = {-1,-2,-2,-1,1,2,2,1};
int dj[] = {2,1,-1,-2,-2,-1,1,2};
void bfs(int i,int j) {
    queue<pair<int,int>> q;
    visited[i][j] = 1;
    levels[i][j] = 0;
    q.push({i , j});
    while(! q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d = 0; d < 8 ;d++) {
            int xi = x + di[d];
            int yj = y + dj[d];
            if(xi >= 8 || xi < 0 ||yj >= 8 || yj < 0 ) {
                continue;
            }
            if(visited[xi][yj] == 0) {
                q.push({xi,yj});
                visited[xi][yj] = 1;
                levels[xi][yj] = levels[x][y] + 1;
            }
        }
    }
}

int main() {
    ana_Yano;
    string p1,p2;
    while(cin>>p1>>p2) {
        // nodes.assign(n + 1,vector<int>());
        int sx = p1[1] - '1';
        int sy = p1[0] - 'a';
        int tx = p2[1] - '1';
        int ty = p2[0] - 'a';

        visited.assign(8, vector<bool>(8,0));
        levels.assign(8, vector<int>(8,0));

        bfs(sx, sy);

        cout<<"To get from "<<p1<<" to "<<p2<<" takes "<<levels[tx][ty]<<" knight moves."<<endl;

    }
    return 0;
}
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<string>grid;
vector<bool> colvis(8,0);
vector<bool> main_vis(15,0);
vector<bool> off_vis(15,0);



int solve(int row) {
    if(row==8) {
        return 1; // Base Case
    }
    int ans = 0;
    for(int i = 0;i<8;i++) {
        if(grid[row][i]=='*'||main_vis[row - i+ 7]||off_vis[row + i]||colvis[i]) {
            continue;
        }
        
        grid[row][i] = 'Q';
        
        colvis[i] = 1;
        main_vis[row - i + 7] = 1;
        off_vis[row + i] = 1;
        
        ans+=solve(row+1);
        // Backtracing
        grid[row][i] = '.';
        colvis[i] = 0;
        main_vis[row - i + 7] = 0;
        off_vis[row + i] = 0;
        
    }
    return ans;
}

int main() {
    ana_Yano;
    grid.resize(8);
    for(int i = 0;i<8;i++) {
        cin>>grid[i];
    }
    cout<<solve(0);
    return 0;
}
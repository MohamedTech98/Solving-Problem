class Solution {
public:

    vector<string>grid;
    vector<vector<string>>ans;
    vector<bool> colvis;
    vector<bool> main_vis;
    vector<bool> off_vis;
    void solve(int n , int row = 0,bool first = true) {
        if(first) {
            colvis.resize(n);
            main_vis.resize(2*n-1);
            off_vis.resize(2*n-1);
            grid.resize(n);
            for(int i = 0;i<n;i++) {
            grid[i] = string(n,'.');
        }
        }
        if(row==n) {
            ans.push_back(grid);
            return;
        }

        for(int col = 0;col<n;col++) {
            if(colvis[col]||main_vis[row-col  + (n-1)]||off_vis[row + col]) {
                continue;
            }
                grid[row][col] = 'Q';
                colvis[col] = main_vis[row - col  + (n-1)] = off_vis[row + col] = 1;
                solve(n,row+1,false);
                grid[row][col] = '.';
                colvis[col] = main_vis[row - col +  (n-1)] = off_vis[row + col] = 0;


            }

        }
    vector<vector<string>> solveNQueens(int n/*Row*/) {
    // vector<vector<string>>res;
    solve(n);
    return ans;

    }
    // vector<bool>colvis(n,0);
    // vector<bool>main_dig(2*n-1,0);
    // vector<bool>off_dig(2*n-1,0);
        
    // }
};
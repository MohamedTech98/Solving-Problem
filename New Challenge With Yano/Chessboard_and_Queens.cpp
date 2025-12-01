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
vector<bool> colvisit(8,0);
vector<bool> mainvisit(15,0);
vector<bool> offvisit(15, 0);

int solve(int row) {
    if(row==8) {
        return 1 ; //Base case
    }
    int ans = 0;
    for(int col = 0;col<8;col++) {
        if(grid[row][col] == '*'||colvisit[col]||mainvisit[row - col + 7 ]||offvisit[row + col]) {
            continue;
        }
        grid[row][col] = 'Q';
        colvisit[col] = mainvisit[row - col+ 7] = offvisit [ row + col] = 1;
        ans += solve(row + 1); //trans
        //Backtracking
        grid[row][col] = '.';
        colvisit[col] = mainvisit[row - col + 7 ] = offvisit [ row + col] = 0;
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
    return 0 ;
}
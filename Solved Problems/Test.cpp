// #include<bits\stdc++.h>

// #define ll long long
// #define endl '\n'
// #define all x.begin(),x.end()
// #define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
// using namespace std; 

//  vector<vector<string>> solveNQueens(int n,bool check = true) {
//         vector<vector<string>>ans(n , vector<string>(1));
//         if(check) {
//             for(int i= 0 ;i<n;i++) {
//                 for(int j = 0;j<n;j++) {
//                 ans[i][0].insert(j,'#');

//                 }
//             }
//         }
//         if(n<=0) {return ans;} //Base case
        
//         for(int i = 0;i<n;i++) {
//             for(int j = 0;j<n;j++) {
//                 if(ans[i][0][j]=='#') {
//                     ans[i][0][j] = 'Q';
//                     for(int x = 0;x<n;x++) {
//                         if(x!=i) {
//                             ans[i][0][x]='.';
//                         }
//                     }
//                     for(int y = 0;y<n;y++) {
//                         if(y!=j) {
//                             ans[y][0][j]=='.';
//                         }
//                     }

//                 }
//             }
//         }
//         return solveNQueens(n-1,false);

        
//     }

// int main() {
//     vector<vector<string>>ans = solveNQueens(4);
    
//     for(int i = 0;i<4;i++) {
//         cout<<ans[i][0]<<endl;
//     }
    
// }
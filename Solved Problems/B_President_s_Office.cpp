#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    char c; cin>>c; 
    vector<string> colors(n);
    vector<bool> take(26 , 0);
    take[c - 'A'] = 1;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        cin>>colors[i];
    }
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(colors[i][j]==c) {
                int top = i - 1;
                int bottom = i + 1;
                int right = j + 1;
                int left = j  - 1;
                if(top >= 0 && colors[top][j] != c && colors[top][j] != '.'&&take[colors[top][j] - 'A'] == 0) {
                    ans++;
                    take[colors[top][j] - 'A'] = 1;
                }
                if(bottom < n && colors[bottom][j] != c && colors[bottom][j]!='.' &&take[colors[bottom][j] - 'A'] == 0) {
                    ans++;
                    take[colors[bottom][j] - 'A'] = 1;
                }
                if(right < m && colors[i][right] != c && colors[i][right]!='.' &&take[colors[i][right] - 'A'] == 0) {
                    ans++;
                    take[colors[i][right] - 'A'] = 1;
                }
                if(left >= 0 && colors[i][left] != c && colors[i][left]!='.' &&take[colors[i][left] - 'A'] == 0) {
                    ans++;
                    take[colors[i][left] - 'A'] = 1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
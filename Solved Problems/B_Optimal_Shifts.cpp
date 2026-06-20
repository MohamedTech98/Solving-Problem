#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        
        int d = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                int dist = n;
                
                for(int j = i + 1; j < n; j++) {
                    if(s[j] == '1') {
                        dist = j - i;
                        break;
                    }
                }
                
                if(dist == n) {
                    for(int j = 0; j < i; j++) {
                        if(s[j] == '1') {
                            dist = (j - i + n) % n;
                            break;
                        }
                    }
                }
                d = max(d, dist);
            }
        }
        cout << d << endl;
    }
    return 0;
}

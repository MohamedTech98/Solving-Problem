#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

bool check(string s) {
    for(int i = 0;i<s.size();i++) {
        if(s[i]=='1') {
            return true;
        }
    }
    return false;
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        vector<bool> take(n,0);
        vector<int> ans;
        int ones = 0,zeros = 0;
        for(int i = 0;i<n;i++) {
            if(s[i]=='1') {
                ones++;
            }
            else {
                zeros++;
            }
        }
        // cout<<ones<<" "<<zeros<<endl;
        if((ones %2 )==0) {
            for(int i =0;i<n;i++) {
                if(s[i]=='1') {
                    ans.push_back(i + 1);
                }
            }
        }
        else {
            cout<<-1<<endl;
            continue;;
        }
        cout<<ans.size()<<endl;
        for(int i = 0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
            if(i==ans.size() - 1) {
                cout<<endl;
            }
        }
    }
    return 0;
}
#include<bits\stdc++.h>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std; 

int main() {
    ana_Yano;
    
    int t; cin>>t;
    while(t--) {
        int a,b; cin>>a>>b;
        int x = a^b;
        vector<int>ans;
        while(x<=a&&a!=b) {
            a = a^x;
            ans.push_back(x);
            x = a^b;
        }
        int trycase = 0;
        while(a!=b) {
            // a = a^x;
            // ans.push_back(x);
            x = a^b;
            trycase++;
            if(x<=a) {
                while(x<=a&&a!=b) {
                    a = a^x;
                    ans.push_back(x);
                    x = a^b;
                }
            }
            else if (trycase==4){
                break;
            }
        }
        if(ans.size()==0) cout<<-1<<endl;
        else {
            cout<<ans.size()<<endl;
            for(int val : ans) {
                cout<<val<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
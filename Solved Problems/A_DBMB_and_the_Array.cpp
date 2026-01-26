#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n,s,x; cin>>n>>s>>x;
        int sum = 0;
        bool fail = true;
        for(int i = 0,in = 0;i<n;i++) {
            cin>>in;
            sum+=in;
        }
        while(sum<=s) {
            if(sum==s) {
                cout<<"YES\n";
                fail = false;
                break;
            }
            sum +=x;
        }
        if(fail)
        cout<<"NO"<<endl;
    }
    return 0;
}
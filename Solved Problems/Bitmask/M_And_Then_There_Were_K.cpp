#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;


int main() {
    ana_Yano;
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        int last_one = 0;
        for(int bit = 0;bit<32;bit++) {
            if((n>>bit & 1)==1) {
                last_one = bit;
            }
        }
        cout<<(1<<last_one) - 1<<endl;
    }
    return 0;
}
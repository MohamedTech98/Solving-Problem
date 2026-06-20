#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int convert(int num ,int base) {
    int ans = 0;
    while(num!=0) {
        if(num % base !=0) {
            ans+= (num % base);
        }
        num /= base;
    }
    return ans;
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {

        int num,base; cin>>num>>base;
        if(base ==1) {
            cout<<num<<endl;
            continue;
        }
        cout<<convert(num,base)<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all nums.begin(),nums.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int convert(int n) {
    int ans = 0;
    while(n!=0) {
        if(n % 2 ==1) {
            ans++;
        }
        n /=2;
    }
    return ans;
}

int main() {
    ana_Yano;
    int n; cin>>n;
    cout<<convert(n)<<endl;
    return 0;
}
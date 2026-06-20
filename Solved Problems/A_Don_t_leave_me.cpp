#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    int q,n; cin>>q>>n;
    while(q--) {
        int type,bit; cin>>type>>bit;
        if(type==1) {
            cout<<((n>>bit) & 1)<<endl;
            continue;
        }
        // int ans = 0;
        switch (type)
        {
        case 2:
            n = n | (1<<bit);
            break;
        case 3:
            n = n - (1<<bit);
            break;
        case 4:
            n = n ^ (1<<bit);
            break;
        }
        cout<<n<<endl;
    }
    return 0;
}
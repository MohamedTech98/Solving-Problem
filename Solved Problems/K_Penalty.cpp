#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
string s;
int penalty(int i,int sc1,int r1,int sc2,int r2) {
    if(i==10||sc1 + r1 < sc2||sc2 + r2  < sc1) {
        return i ;
    }
    bool first = 0;
    if(i%2==0) {
        first = 1;
    }
    else if(i%2!=0) {
        first = 0;
    }
    if(first==1&&s[i]!='?') {
        return penalty(i+1,sc1 + (s[i]-'0'),r1- 1 , sc2,r2);
    }
    else if(first==0&&s[i]!='?') {
        return penalty(i+1,sc1 ,r1 , sc2 + (s[i]-'0'),r2 - 1 );
    }
    else if(s[i]=='?') {
        if(first==1) {
            return min(penalty(i+1,sc1 + 1,r1- 1 , sc2,r2),penalty(i+1,sc1 + 0,r1- 1 , sc2,r2));
        }
        else {
            return min(penalty(i+1,sc1 ,r1 , sc2 + 1,r2 - 1 ),penalty(i+1,sc1 ,r1 , sc2 + 0,r2 - 1 ));
        }
    }
}

int main() {
    ana_Yano;
    int t; cin>>t;
    while(t--) {
        cin>>s;
        cout<<penalty(0,0,5,0,5)<<endl;
    }
    return 0 ;
}
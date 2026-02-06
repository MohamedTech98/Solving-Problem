#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    map<char,int> freq;
    freq['A'] = 0;
    freq['B'] = 0;
    freq['C'] = 0;

    for(int i = 0;i<3;i++) {
        char c1,sign,c2;
        cin>>c1>>sign>>c2;
        if(sign =='>') {
            freq[c1] ++;
        }
        else {
            freq[c2] ++;
        }
    }
    char ans[4];

    for(int i = 0;i<3;i++) {
        if(i<2&&freq[i + 'A']==freq[(i + 1) + 'A']) {
            cout<<"Impossible";
            return 0;
        }
        ans[freq[i + 'A']] = i + 'A';
    }
    
    cout<<ans<<endl;
    return 0;
}
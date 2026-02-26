#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<char> res(n);
    res[0] = 'R';
    res[1] = 'O';
    res[2] = 'Y';
    res[3] = 'G';
    res[4] = 'B';
    res[5] = 'I';
    res[6] = 'V';
    for (int i = 7; i < n; ++i) {
        res[i] = res[i - 4];
    }
    for(char c : res) {
        cout<<c;
    }
    
}
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int n; cin >> n;
    // if(n < 3) {
    //     cout << -1 << endl;
    //     return 0;
    // }
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0;i < n;i++) {
        a[i] = i;
    }
    for(int i = 0;i < n - 1;i++) {
        b[i] = a[i + 1];
    }
    b[n - 1] = a[0];
    vector<int> c(n);
    vector<bool> fre(n,0); 
    for(int i = 0;i < n;i++) {
        c[i] = (a[i] + b[i]) % n;
        if(fre[c[i]] == 1) {
            cout << -1 << endl;
            return 0;
        }
        fre[c[i]] = 1;
    }
    for(int i = 0;i < n;i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    for(int i = 0;i < n;i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
    for(int i = 0;i < n;i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;
}
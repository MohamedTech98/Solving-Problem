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
    string s1,s2; cin >> s1 >> s2;
    if(s1.size() != s2.size()) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0;i < s1.size();i++) {
        if(s1[i] != s2[i]) {
            swap(s1[i],s1[(i + 1 < s1.size()?i + 1:i - 1)]);

        }
    }

    if(s1 == s2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int count = 0;
        string student; cin>>student;
        for(char c: student) {
            count++;
            if(c == 'L') {
                break;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
set<string>ans;
int len;
char c;
void create(string s,string m) {
    if(s.size()==len) {
        ans.emplace(s); // Base case
    }
    for(int i = 0;i<m.size();i++) {
        c = m[i];
        create(s + c,m.substr(0,i) + m.substr(i+1,m.size()));
    }
}

int main() {
    ana_Yano;
    string origanl;
    cin>>origanl;
    len = origanl.length();
    create("",origanl);
    cout<<ans.size()<<endl;
    for(string v : ans) cout<<v<<endl;
    return 0;
} 

//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>



#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
const int mod = 1e9 + 7;

string evalpostfix(string s) {
    stack<int> st;
    for(int i = 0;i<s.size();i++) {
        if(s[i] != '+'&&s[i] != '-' && s[i] != '/' && s[i]!= '*') {
            st.push(s[i] - '0');
        }
        else if(s[i] == '+') {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(n1 + n2);
        }
        else if(s[i] == '-') {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(n1 - n2);
        }
        else if(s[i] == '*') {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(n1 * n2);
        }
        else if(s[i] == '/') {
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(n1 / n2);
        }
    }
    string ans = "";
    while(! st.empty()) {
        ans += to_string(st.top());
        // cout<<ans<<endl;
        st.pop();
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    ana_Yano;
    // string s; cin>>s;
    cout << evalpostfix("6523+8*+3+*") << endl;
    return 0;
}
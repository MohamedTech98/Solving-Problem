#include<bits/stdc++.h>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

int main() {
    ana_Yano;
    int t; cin >> t;
    vector<string> ends = {"00","25","50","75"};

    while(t--) {
        string s; cin >> s;
        string best = "-1";
        for(auto end : ends) {
            int pos1 = -1, pos2 = -1;
            for(int j = s.size() - 1; j >= 0; j--) {
                if(s[j] == end[1] && pos2 == -1) pos2 = j;
            }
            for(int j = s.size() - 1; j >= 0; j--) {
                if(j == pos2) continue;
                if(s[j] == end[0]) { pos1 = j; break; }
            }
            if(pos1 != -1 && pos2 != -1) {
                string digits;
                for(int j = 0; j < s.size(); j++) {
                    if(j != pos1 && j != pos2) digits += s[j];
                }
                digits += end[0];
                digits += end[1];
                sort(digits.begin(), digits.end() - 2, greater<char>());
                if(digits[0] != '0') best = max(best, digits);
            }
        }
        cout << best << "\n";
    }
    return 0;
}
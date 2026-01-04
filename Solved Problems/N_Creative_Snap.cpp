#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;
int n,k,a,b;
vector <int> av;
ll calc(int l,int r) {
    int start = lower_bound(av.begin(),av.end(),l) - av.begin();
    int end = upper_bound(av.begin(),av.end(),r) - av.begin();
    int mid = l + (r-l) / 2 ;
    ll cnt = end - start;
    int len = r - l + 1;
    if(cnt==0) {
        return a;
    }
    ll ch1 = len * cnt * b;
    if(l==r) {
        return ch1;
    }
    ll ch2 = calc(l,mid) + calc(mid + 1 ,r);
    return min(ch1,ch2);
}
int main() {
    cin>>n>>k>>a>>b;
    for(int i = 0,val;i<k;i++) {
        cin>>val;
        av.push_back(val);
    }
    sort(av.begin(),av.end());
    cout<<calc(1,(1<<n));
    return 0;
}
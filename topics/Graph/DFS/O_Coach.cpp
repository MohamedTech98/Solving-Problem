#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define all weights.begin(),weights.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

vector<vector<int>> teams;
vector<vector<int>> students;
vector<vector<int>> two;
vector<int> one;
vector<int> temp;
vector<bool> visited;
int a[2] = {0,0};
void DFS(int node) {
    visited[node] = 1;
    temp.push_back(node);
    for(auto child : students[node]) {
        if(visited[child]==0) {
            DFS(child);
        }
    }
}
int main() {
    ana_Yano;
    int n,m; cin>>n>>m;
    students.assign(n + 1,vector<int>());
    visited.assign(n + 1,0);
    for(int i = 1,u,v;i<=m;i++) {
        cin>>u>>v;
        students[u].push_back(v);
        students[v].push_back(u);
    }
    for(int i = 1;i<=n;i++) {
        if(visited[i]==0) {
            DFS(i);
            if(temp.size() > 3) {
                cout<< -1 << endl;
                return 0;
            }
            else if(temp.size() ==3) {
                teams.push_back(temp);
            }
            else if(temp.size() ==2) {
                a[1]++;
                two.push_back(temp);
            }
            else if(temp.size() ==1) {
                a[0]++;
                one.push_back(temp[0]);
            }
            temp.clear();
        }
    }
    if(a[0] > 0 || a[1] > 0) {
        if(a[1] <= a[0]) {
            for(int i = 0,j = one.size() - 1;i<two.size();i++) {
                two[i].push_back(one[j]);
                teams.push_back(two[i]);
                // one.pop_back();
                j--;
            }
            a[0] -= a[1];
            a[1] = 0;
            if(a[0] % 3 == 0) {
                for(int i = 0;i<a[0];i++) {
                    temp.push_back(one[i]);
                    if(temp.size() == 3) {
                        teams.push_back(temp);
                        temp.clear();
                    }
                }
            }
        }
        else {
            cout<< -1 <<endl;
            return 0;
        }
    }
    for(auto team : teams) {
        for(auto member : team) {
            cout<< member << " ";
        }
        cout<< endl;
    }
}
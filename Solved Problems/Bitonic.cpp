#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>


#define ll long long
#define endl '\n'
#define all x.begin(),x.end()
#define ana_Yano ios::sync_with_stdio(false),cin.tie(nullptr)
using namespace std;

class Bitonic {
    private:
    int target = 0;
    int size = -1;
    int n_swap = 0;
    int n_comp = 0;
    vector<int> data;
    public:

    Bitonic(vector<int> &numbers) {
        data = numbers;
        if(data.size() > 2) {
            n_comp++;
            for(int i = 0;i < data.size();i++) {
                target = (data[target] < data[i]? i : target);
            }
            // for(int i = 0;i < data.size();i++) {
                //     n_comp++;
                //     if(target == data[i]) {
                    //         n_comp++;
                    //         target = i; // if there is duplicate
                    //     }
                    // }
                    swap(data[target],data[data.size() / 2]);
                    target = data.size() / 2;
                    // if there are elements left greater than elements right
                    for(int l = 0;l < target;l++) {
                        for(int r = target + 1;r < data.size();r++) {
                            if(data[l] > data[r]) {
                                swap(data[l],data[r]);
                            }
                        }
                    }
                    bubble_sort(0,target);
                    if(data[target + 1])
                    selection_sort(target + 1,data.size());
                    numbers = data;
        }
    }
    void selection_sort(int l,int r) {
        for (int i = l, j, bigest; i < r-1; i++) {
            n_comp++;
            for (j = i+1, bigest = i; j < r; j++) {
                n_comp++;
                if (data [j] > data [bigest]) {
                    n_comp++;
                    bigest = j;
                }
            }
            swap (data [bigest], data [i]);
            n_swap++;
        }
    }
    int get_comparsion() {return n_comp;}
    int get_swap() {return n_swap;}
    int get_target() {return data[target];}
    void bubble_sort(int l,int r) {
        n_comp++;
        for(int i = l;i < r - 1;i++) {
            n_comp++;
            for(int j = l;j < r - 1;j++) {
                n_comp++;
                if(data[j] > data[j + 1]) {
                    n_comp++;
                    swap(data[j],data[j + 1]);
                    n_swap++;
                }
            }
        }
    }
};

int main() {
    ana_Yano;
    vector<int> nums = {5,7,8,1,75,2,9};
    Bitonic task(nums);
    cout << task.get_target() << endl;
    for(int val : nums) {
        cout << val << " ";
    }
    return 0;
}
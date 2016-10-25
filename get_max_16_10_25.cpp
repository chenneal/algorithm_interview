/* 这个题目给出了一个数组，sum值为每个位置上的数乘以位置的权重之和，给出m个交换对，
   可以使用任意个数的交换对，求出最大值并输出，暴力法直接对所有子集进行全排列，例子如下：
   input: 3 2
          3 2 1
          1 2
          2 3
    output:
          13
   */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <climits>
#include <cctype>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>

#define pb push_back
//#define FILE_JUDGE

using namespace std;

typedef long long ll;
typedef double D;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef map<int, int> MII;
typedef set<int> SI;

int max_sum;

void change(int index, vector<pair<int, int>>& col, vector<int>& nums) {
    int temp = nums[col[index].first-1];
    nums[col[index].first-1] = nums[col[index].second-1];
    nums[col[index].second-1] = temp;

}

int sum_total(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += nums[i]*(i+1);
    }
    return total;
}

void add_sub(int ap, vector<int>&nums, vector<vector<int>>& result) {
    // resize the result
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        if (ap%2 == 1)
            temp.push_back(nums[i]);
        ap /= 2;
    }
    result.push_back(temp);
}

void gen_subset(vector<int>&nums, vector<vector<int>>& result) {
    int n = nums.size();
    for (int i = 0; i < (1<<n); i++) {
        add_sub(i, nums, result);
    }
}

int main(int argc, char* argv[]) {
    #ifdef FILE_JUDGE
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    #endif
    int m, n;
    while (cin >> n >> m) {
        max_sum = 0;
        VI nums;
        VI co;
        VVI subset;
        vector<pair<int, int>> col;
        for (int i = 0; i < n; i++) {
        	int temp;
            cin >> temp;
            nums.pb(temp);
        }
        for (int i = 0; i < m; i++) {
        	int first_t, second_t;
            cin >> first_t;
            cin >> second_t;
            col.pb(make_pair(first_t, second_t));
        }
        for (int i = 0; i < m; i++) {
            co.pb(i);
        }
        gen_subset(co, subset);
        for (int i = 0; i < subset.size(); i++) {
            sort(subset[i].begin(), subset[i].end());
            do {
                VI help(nums);
                for (int j = 0; j < subset[i].size(); j++)
                    change(j, col, help);
                int max_t = sum_total(help);
                if (max_t > max_sum)
                    max_sum = max_t;
            } while(next_permutation(subset[i].begin(), subset[i].end()));
        }
        cout << max_sum << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ================= 你的原始代码，一字未改 =================
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptz = 0;
        int ptn = 0;

        while (ptz < nums.size()-1 && ptn < nums.size()-1) {
            while (ptz < nums.size()-1 && nums[ptz] != 0) {
                ptz++;
            }
            while (ptn < nums.size() &&nums[ptn] == 0 ) {
                ptn++;
            }
            if(ptz < nums.size()-1 && ptn < nums.size()&&ptz<ptn){
                nums[ptz] = nums[ptn];
                nums[ptn] = 0;
            }
            else if(ptz < nums.size()-1 && ptn < nums.size()&&ptz>ptn){
                ptn++;
            }
        }
    }
};
// =========================================================

void print(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]\n";
}

void run(vector<int> nums) {
    cout << "input : ";
    print(nums);
    Solution().moveZeroes(nums);
    cout << "output: ";
    print(nums);
    cout << "------------------------\n";
}

int main() {
    // 正常用例
    run({0, 1, 0, 3, 12});
    // 没有 0，最容易触发越界
    run({1, 2, 3});
    // 全是 0
    run({0, 0, 0});
    // 触发顺序错乱
    run({1, 0, 2});
    // 0 在末尾
    run({1, 2, 0});
    // 单个元素
    run({0});
    run({1});
    return 0;
}
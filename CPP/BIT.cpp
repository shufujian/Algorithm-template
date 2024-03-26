#include<bits/stdc++.h>
using namespace std;

/*
    树状数组 Binary Indexed Tree
    
    用于以 O(logn) 求取数组内任意的区间和
*/

class BIT{
private:
    vector<int> nums;
    vector<int> tree;

public:
    int lowbit(int i){
        return i&-i;
    }
    BIT(vector<int>& nums) : nums(nums.size()), tree(nums.size()+1){\
        for(int i=0;i<nums.size();i++){
            update(i, nums[i]);
        }
    }

    // 将nums[i]的值更新为nums
    void update(int index, int value){
        int delta = value - nums[index];
        nums[index]=value;
        for(int i=index+1;i<tree.size();i+=lowbit(i)){ // tree的下标是从 1 开始的
            tree[i]+=delta;
        }
    }

    int sumRange(int left, int right){
        int res=0;right++;
        for(;right>0;right&=right-1){
            res += tree[right];
        }
        for(;left>0;left&=left-1){
            res -= tree[left];
        }
        return res;
    }
}
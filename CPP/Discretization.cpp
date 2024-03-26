#include<bits/stdc++.h>
using namespace std;

/*
    离散化 Discretization Discipline
    只关心数据的 大小关系 ，使用 排名 代替原数据 来进行预处理
*/

vector<int> nums;
sort(nums.begin(), nums.end()); // 排序
nums.erase(unique(nums.begin(), nums.end()), nums.end()); // 去重

// 二分求出x对应的离散化的值
int find(int x){ // 找到第一个大于等于x的位置
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r)>>1;
        if (nums[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}

// 使用 常用接口
lower_bound(nums.begin(), nums.end(), x) - nums.begin(); // 第一个大于等于 x 的值的下标
upper_bound(nums.begin(), nums.end(), x) - nums.begin(); // 第一个大于 x 的值的下标

ranges::lower_bound(nums, x) - nums.begin(); // 第一个大于等于 x 的值的下标
ranges::upper_bound(nums, x) - nums.begin(); // 第一个大于 x 的值的下标
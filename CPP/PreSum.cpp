#include<bits/stdc++.h>
using namespace std;

/*
    前缀和 Pre Sum
    求数组内 [1...n] 所有值的和
    也可以求取数组内 [m...n] 的所有值的和
*/

// 一维前缀和
vector<int> v(n+1,0);

void init(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        v[i+1]=v[i]+nums[i];
    }
}

int sum(int left, int right){ // 默认传过来的下标是从 0 开始的
    return v[right+1] - v[left]
}

// 二维前缀和
vector<int> v(n+1,,vector<int>(m+1,0));

void init(vector<vector<int>>& nums){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            v[i+1][j+1] = v[i+1][j] + v[i][j+1] - v[i][j] + nums[i][j];
        }
    }
}

int sum(int x1,int y1, int x2, int y2){ // 默认传过来的下标是从 0 开始的 (x1, y1)为左上角的点，(x2, y2)为右下角的点
    return v[x2+1][y2+1] - v[x2+1][y1] - v[x1][y2+1] + v[x1][y1];
}

// 可以推广到更高维
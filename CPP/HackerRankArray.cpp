#include<bits/stdc++.h>
using namespace std;

/*
    差分数组 HackerRank Array
    用于对数组区间进行加减
*/

vector<int> HackerRank(n,0);

void init(vector<int>& nums){
    HackerRank[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        HackerRank[i]=nums[i] - nums[i-1];
    }
}

// val为负数时即为减
void add(int left, int right, int val){
    HackerRank[left]+=val;
    if(right < HackerRank.size()) HackerRank[right]-=val;
}

vector<int> result(){
    vector<int> res;
    int cnt=0;
    for(int i=0;i<HackerRank.size();i++){
        cnt+=HackerRank[i];
        res.push_back(cnt);
    }
    return res;
}

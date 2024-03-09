/*
    二分查找 Binary Search
    用于在已排序数组中快速查找符合要求的数

    注意二分有开区间、闭区间之分
    默认为闭区间
*/

bool check(){
    if(true) return true;
    return false;
}

// 非递归写法，
int BinarySearch(vector<int>& nums, int left, int right){
    int mid = (left+right)/2;
    while(left<right){
        if(check()) right = mid; // 需要判断是否为包含mid
        else left = mid+1; // left与right必须一个不包含mid，否则或出现死循环
    }
    return left;
}

// 递归写法，
int BinarySearch(vector<int>& nums, int left, int right){
    int mid = (left+right)/2;
    if(check()) return BinarySearch(nums, left, mid); // 需要判断是否为包含mid
    else return BinarySearch(nums, mid+1, right); // left与right必须一个不包含mid，否则或出现死循环
    return left;
}

// 使用 常用接口
lower_bound(nums.begin(), nums.end(), x) - nums.begin(); // 第一个大于等于 x 的值的下标
upper_bound(nums.begin(), nums.end(), x) - nums.begin(); // 第一个大于 x 的值的下标

ranges::lower_bound(nums, x) - nums.begin(); // 第一个大于等于 x 的值的下标
ranges::upper_bound(nums, x) - nums.begin(); // 第一个大于 x 的值的下标
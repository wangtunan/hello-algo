/**
 * File: bucket_sort.cpp
 * Created Time: 2023-03-30
 * Author: Krahets (krahets@163.com)
 */

#include "../include/include.hpp"

/* 桶排序 */
void bucketSort(vector<float> &nums) {
    // 初始化 k = n/2 个桶，预期向每个桶分配 2 个元素
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);
    // 1. 将数组元素分配到各个桶中
    for (float num : nums) {
        // 输入数据范围 [0, 1)，使用 num * k 映射到索引范围 [0, k-1]
        int i = num * k;
        // 将 num 添加进桶 bucket_idx
        buckets[i].push_back(num);
    }
    // 2. 对各个桶执行排序
    for (vector<float> &bucket : buckets) {
        // 使用内置排序函数，也可以替换成其它排序算法
        sort(bucket.begin(), bucket.end());
    }
    // 3. 遍历桶合并结果
    int i = 0;
    for (vector<float> &bucket : buckets) {
        for (float num : bucket) {
            nums[i++] = num;
        }
    }
}

/* Driver Code */
int main() {
    // 设输入数据为浮点数，范围为 [0, 1)
    vector<float> nums = {0.49f, 0.96f, 0.82f, 0.09f, 0.57f, 0.43f, 0.91f, 0.75f, 0.15f, 0.37f};
    bucketSort(nums);
    cout << "桶排序完成后 nums = ";
    PrintUtil::printVector(nums);

    return 0;
}
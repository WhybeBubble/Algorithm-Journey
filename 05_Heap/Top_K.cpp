
#include <iostream>
#include <vector>
#include <queue>
#include <functional> // 为了使用 greater

using namespace std;

vector<int> getTopK(const vector<int>& nums, int k) {
    // 小顶堆：greater<int> 保证堆顶最小
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else if (num > minHeap.top()) {
            // 只有比堆顶大，才踢掉旧的，放入新的
            minHeap.pop();
            minHeap.push(num);
        }
    }

    // 将堆中剩下的元素存入结果
    vector<int> result;
    result.reserve(k);  //提前分配内存

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}

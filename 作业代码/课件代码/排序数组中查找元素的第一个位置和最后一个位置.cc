#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int leftBorder = findLeftBoundary(nums, target);
        int rightBorder = findRightBoundary(nums, target);
        
        return {leftBorder, rightBorder};
    }

private:
    // 寻找左边界：第一个等于 target 的位置
    int findLeftBoundary(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 闭区间 [left, right]
        int leftBorder = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                // 即使相等，也继续向左收缩，试图找到更靠左的 target
                right = mid - 1; 
                if (nums[mid] == target) {
                    leftBorder = mid; // 记录当前找到的可能左边界
                }
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }

    // 寻找右边界：最后一个等于 target 的位置
    int findRightBoundary(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 闭区间 [left, right]
        int rightBorder = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                // 即使相等，也继续向右收缩，试图找到更靠右的 target
                left = mid + 1;
                if (nums[mid] == target) {
                    rightBorder = mid; // 记录当前找到的可能右边界
                }
            } else {
                right = mid - 1;
            }
        }
        return rightBorder;
    }
};
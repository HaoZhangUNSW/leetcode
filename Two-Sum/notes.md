#### Two Sum:

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

很容易想到的方案：

    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    int* twoSum(int* nums,int numsSize,int target){
            int* index = (int*)malloc(sizeof(int) * 2);
            int flag = false;
            for(int i = 0;i < numsSize;i++){
                for(int j = i + 1;j < numsSize;j++){
                    if(nums[i] + nums[j] == target){
                        index[0] = i;
                        index[1] = j;
                        flag = true;
                    }
                    
                }
                if(flag){
                    break;
                }
            }
            return index;
        }

上述方案的时间复杂度是\\(O(n^2)\\),关键点是C语言内存空间的申请, 和标志flag的使用。






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

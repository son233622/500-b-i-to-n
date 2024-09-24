/* Input: nums = [8, 7, 2, 5, 3, 1]
        target = 10 
Output: Pair found (8, 2) or Pair found (7, 3)  
Input: nums = [5, 2, 6, 8, 1, 9]    
       target = 12 
Output: Pair not found */
#include <stdio.h>

// tìm một cặp trong mảng có tổng cho tước 
void findPair(int nums[], int n, int target)
{
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            // Nếu thỏa mãn đk, in ra 
            if( nums[i] + nums[j] == target){
                printf("Pair found (%d, %d)\n", nums[i], nums[j]);
                return; 
            }
        }
        

    }
    // Không tìm thấy kết quả
    printf("Pair not found");
}


int main(void)
{
    int nums[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int n = sizeof(nums)/sizeof(nums[0]);
    findPair(nums, n, target);
}
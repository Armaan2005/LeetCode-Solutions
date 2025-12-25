class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Sort the array to make it easier to avoid duplicates and use two pointers
        sort(nums.begin(), nums.end());
        
        // Iterate over the array
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for 'i'
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Two-pointer approach to find the other two numbers
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements for 'left' and 'right'
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move the pointers
                    left++;
                    right--;
                } else if (sum < 0) {
                    // If the sum is less than 0, move the left pointer to increase the sum
                    left++;
                } else {
                    // If the sum is greater than 0, move the right pointer to decrease the sum
                    right--;
                }
            }
        }
        
        return ans;
    }
};

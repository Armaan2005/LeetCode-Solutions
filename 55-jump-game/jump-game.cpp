class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0) continue;
            else{
                int stp=i;
                int end=i+nums[i];
                while(stp<n && stp<=end){
                    if(dp[stp]==true){
                        dp[i]=true;
                        break;
                    }
                    stp++;
                }
            }
        }
        return dp[0];
    }
};
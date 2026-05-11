class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        while(true){
            bool flag=true;
            for(auto ele:nums) if(ele!=0) flag=false;
            if(flag==true) return ans;
            int mine=INT_MAX;
            for(auto ele:nums) if(ele<mine && ele!=0) mine=ele;
            cout<<mine<<" ";
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0) nums[i]-=mine;
            }
            ans++;
        }
        return -1;
    }
};
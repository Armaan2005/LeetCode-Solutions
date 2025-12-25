class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
       
        vector<int>s(n+m);
         int idx=s.size();
         cout<<idx;
        int i=0;
        for(;i<m;i++) s[i]=nums1[i];
        for(int j=0;j<n;j++) s[i+j]=nums2[j];
        sort(s.begin(),s.end());
        for(auto ele:s) cout<<ele;
        if(idx%2!=0) return s[idx/2];
        else{
            int a=idx/2;
            int b=(idx/2)-1;
            return float(s[a]+s[b])/2;
        } 
        return 0;
    }
};
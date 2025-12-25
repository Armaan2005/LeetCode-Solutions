class Solution {
public:
    int maxArea(vector<int>& v) {
        int length=v.size();
        int maxwater=0;
        int i=0;
        int j=length-1;
       
       while(i<j){
                
              int l=j-i;
              int w=min(v[i],v[j]);
              int a=l*w;
              maxwater=max(maxwater,a);
                if(v[i]<=v[j]) i++;
                else j--;
            } 

           
            return maxwater;
        }
    };

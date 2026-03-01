class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        if(s.size()==1) return ans+=s[0];
          ans = s.substr(0,1);  
        int max_len = 1;
        for(int i=0;i<s.size();i++){
            int prev=i;
            int forw=i+1;
            while(prev>=0 && forw<s.size()){
                if(s[prev]==s[forw]){
                    if(forw-prev+1>max_len){
                        max_len=forw-prev+1;
                        string temp="";
                        for(int k=prev;k<=forw;k++) temp+=s[k];
                        ans=temp;
                    }
                    prev--;
                    forw++;
                }
                else break;
            }
                 prev=i-1;
                 forw=i+1;
                     while(prev>=0 && forw<s.size()){
                if(s[prev]==s[forw]){
                    if(forw-prev+1>max_len){
                        max_len=forw-prev+1;
                        string temp="";
                        for(int k=prev;k<=forw;k++) temp+=s[k];
                        ans=temp;
                    }
                    prev--;
                    forw++;
                }
                else break;
            }
                
            }
        
        return ans;
    }
};
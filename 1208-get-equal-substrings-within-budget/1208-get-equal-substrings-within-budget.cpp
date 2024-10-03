class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
     
        int N = s.size();
        int currCost =0, maxLen=0;
        
        for(int lf=0, rt=0; rt<N; rt++){
            
            
            currCost += abs(s[rt]-t[rt]);
            
            while(currCost > maxCost){
                currCost -= abs(s[lf]-t[lf]);
                lf++;
            }
            
            
            maxLen = max(maxLen, rt-lf+1);
        }
        
        
        return maxLen;
    }
};
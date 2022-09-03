class Solution {
public:
    int characterReplacement(string s, int k) {
     
        
        unordered_map<char, int> mp;
        int ans = 0;
        int lf=0, maxFreq=0;
        for(int rt=0; rt<s.size(); rt++){
            
            mp[s[rt]]++;
            maxFreq = max(maxFreq, mp[s[rt]]);
            
            int len = rt-lf+1;
            if(len-maxFreq > k){    //len-freq -> no of charc you can change
                mp[s[lf]]--;
                lf++;
            }
            
            len = rt-lf+1;
            maxFreq = max(maxFreq, mp[s[rt]]);
            if(len-maxFreq <= k){
                ans = max(ans, len);
            }
            
        }//for
        
        return ans;
    }
};
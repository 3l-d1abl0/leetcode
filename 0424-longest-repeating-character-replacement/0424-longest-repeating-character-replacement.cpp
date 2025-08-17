class Solution {
public:
    
    int getMaxFrex(unordered_map<char, int> &mp){
        
        int maxx=0;
        for(auto pp: mp){
            maxx= max(pp.second, maxx);
        }
        
        return maxx;
    }
    
    int method1(string &s, int k){
        
        
        unordered_map<char, int> mp;
        
        int lf=0, rt=0, maxx=-1;
        for(rt=0; rt<s.size(); rt++){
            
            
            mp[s[rt]]++;
            
            int currLen = rt-lf+1;
            while((currLen - getMaxFrex(mp)) >k){
                
                mp[s[lf]]--;
                lf++;
                
                currLen = rt-lf+1;
            }
            
            //number of replacble chars <= k
            maxx = max(maxx, rt-lf+1);
        }//for
        
        return maxx;
    }
    
    int method2(string &s, int k){
        
        int maxLen = INT_MIN;
        int maxFreq = INT_MIN;
        unordered_map<int,int> mp;
        
        int rt=0, lf=0;
        for(rt=0; rt < s.size(); rt++){
            
            mp[s[rt]]++;
            
            //some char with max Frequency
            maxFreq = max(maxFreq, mp[s[rt]]);
            
            //char can be replaced = size - maxFreq
            int replaceLen = (rt-lf+1)-maxFreq;
            if(replaceLen > k){ //cant replace as > k, hence make window small
                mp[s[lf]]--;
                lf++;
                /*
                even if the character with max Frequency goes out of the window 
                it wont change the answer
                as the max the Freq is the can be th elength of the string as we can more 
                replacement chars
                */
            }
                maxLen = max(maxLen, rt-lf+1);
            
            
        }//for
        
        return maxLen;
        
    }
    
    int characterReplacement(string s, int k) {
        
        /*  TC: O(26.N)
          SC: O(N)
          9ms
          */
        //return method1(s, k);
        
        /*  TC: O(N)
            SC: O(N)
            5ms
        */
        return method2(s, k);
        
    }
};
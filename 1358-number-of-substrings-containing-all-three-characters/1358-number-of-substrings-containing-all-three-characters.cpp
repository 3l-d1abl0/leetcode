class Solution {
public:
    int numberOfSubstrings(string s) {
  
        unordered_map<char, int> map;
        
        int lf =0, count =0;
        for(int rt=0; rt<s.size(); rt++){
            
            map[s[rt]]++;
            while(map['a']>=1 && map['b']>=1 && map['c']>=1){
                
                count += (s.size()-rt);
                
                map[s[lf]]--;
                lf++;
            }
            
        }//for
        
        
        return count;
        
        /*
        
        If anty subarray has all three:
        1. Count the subarray with all the character ahead with it.
        (as the subarray will form valid subarray will all the ahead character)
        
        2. if all char are stisfied, shrink the subaaray with left
        */
        
    }
};
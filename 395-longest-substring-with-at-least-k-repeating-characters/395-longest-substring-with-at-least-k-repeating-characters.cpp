class Solution {
public:
    int longestSubstring(string s, int k) {
     
        //Only lowercase englis h alphabets - 26
        
        int maxx =0;
        for(int max_char=1; max_char<=26; max_char++){
            
            unordered_map<char, int> mp;
            int lf=0, ctr=0;
            
            for(int rt=0; rt<s.size(); rt++){
                
                mp[s[rt]]++;
                if(mp[s[rt]]==k) ctr++;//ctr- no of char having freq >=3
                
                while(mp.size()>max_char &&lf<=s.size()){
                    
                    if(mp[s[lf]]==k) ctr--;
                    
                    mp[s[lf]]--;
                    if(mp[s[lf]]==0)
                        mp.erase(s[lf]);
                    
                    lf++;
                }
                
                if(mp.size() == max_char && max_char==ctr){
                    maxx = max(maxx, rt-lf+1);
                    //cout<<maxx<<" :"<<lf<<" - "<<rt<<endl;
                }
                
            }//for
            
        }//for
        
        return maxx;
    }
};
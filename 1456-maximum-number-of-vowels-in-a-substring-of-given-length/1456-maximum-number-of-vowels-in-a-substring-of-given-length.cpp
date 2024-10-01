class Solution {
public:
    int maxVowels(string s, int k) {
        
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int vCount =0;
        int mxCount = -1;
        for(int lf=0, rt=0; rt<s.size(); rt++){
            
            if(vowels.find(s[rt])!=vowels.end())
                vCount++;    

            
            while(rt-lf+1 >k){
                if(vowels.find(s[lf])!=vowels.end())
                    vCount--;
                
                lf++;
            }
            
            if(rt-lf+1==k){
                //cout<<lf<<" "<<rt<<" = "<<vCount<<endl;
                mxCount = max(mxCount, vCount);
            }

        }//for
        
        
        
        return mxCount;
    }
};
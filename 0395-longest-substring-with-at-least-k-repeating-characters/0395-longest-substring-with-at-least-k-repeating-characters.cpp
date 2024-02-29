class Solution {
public:
    int method1(string &s, int k){

        unordered_map<char, int> map;
        
        int maxx =0;
        for(int lf=0; lf<s.size(); lf++){
            
            map.clear();
            int freqCount =0;
            for(int rt=lf; rt<s.size(); rt++){

                //if(map[s[rt]]==k)
                 //   freqCount--;
                   
                map[s[rt]]++;
                   
                if(map[s[rt]]==k)
                    freqCount++;
                   
                 if(map.size() == freqCount)    {
                     maxx = max(maxx, rt-lf+1);
                     //cout<<lf<<" "<<rt<<endl;
                 }
                 
            }//for rt
        }//for lf
        
        return maxx;
    }
    
    
    int method2(string &s, int k){
        
        /*
            check for string with max unique permitted character from 1 - max unique char in string
            i.e
            -> max unique char in string = 1
            -> max unique char in string = 2
            -> max unique char in string = 3
            .
            .
            -> max unique char in string = max
            
            for each of the case if each char can have at lest k freq.
        */
        
        unordered_map<char, int> map;
        for(char ch: s)
            map[ch]++;
        
        int maxUniqueChars = map.size();
        //cout<<"MxUnq ="<<maxUniqueChars<<endl;
        int maxLen =0;
        
        for(int uniqCharPermit=1; uniqCharPermit<= maxUniqueChars ; uniqCharPermit++){
        //for(int uniqCharPermit=2; uniqCharPermit<= 2 ; uniqCharPermit++){
            
            int kCount =0, uniqueChar=0, lf=0;
            map.clear();
            
            //process the string
            for(int rt=0; rt<s.size(); rt++){
                
                //process the incoming char
                char inChar = s[rt];
                
                //char does not exist in map
                if(map.find(inChar) == map.end())
                    uniqueChar++;
                
                
                map[inChar]++;
                
                //if freq becomes ka after processing
                if(map[inChar]==k)
                    kCount++;
                
                
                //Process outgoing character - if current window has more unique char than permitted
                while(lf<rt && uniqueChar > uniqCharPermit){
                    
                    char outChar = s[lf];
                    if(map[outChar]==k)
                        kCount--;
                    
                    map[outChar]--;
                    
                    if(map[outChar] ==0){
                        uniqueChar--;
                        map.erase(outChar);
                    }
                    
                    lf++;
                }//while
                
                //cout<<uniqueChar<<" "<<uniqCharPermit<<" kcnt="<<kCount<<" lf= "<<lf<<" rt= "<<rt<<endl;
                //If total number of unique Characters are same as permitted
                // and all of them have a count of k
                if(uniqueChar == uniqCharPermit && kCount == uniqCharPermit){
                    maxLen = max(maxLen, rt-lf+1);
                }
                
            }//for rt
            
            
        }//uniqCharPermit
        
        
        return maxLen;
    }
    
    int longestSubstring(string s, int k) {
        
        //TC: O(26*N*N) SC:O(26)
        //return method1(s, k);
        
        //
        return method2(s, k);
    }
    
};
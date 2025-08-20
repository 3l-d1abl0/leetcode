class Solution {
public:
    
    string method1(string &s, string &t) {
        
        /*
            A-Z -> 65 -90
            a-z -> 97-122
            
            57
        */
        
        vector<int> MP(58, 0);//map for the pattern
        vector<int> M(58, 0);
        
        
        //Create freq array and count number of unique characters
        int unq =0;
        for(char ch: t){
            if(MP[ch-'A']==0)
                unq++;
               MP[ch-'A']++;
        }
        
        //cout<<"unq= "<<unq<<endl;
        int lf =0, ctr=0;
        int r,l=0;
        int minn = INT_MAX, pos = -1;
        
        for(int rt=0; rt<s.size(); rt++){
            
            //process incoming element
            //cout<<unq<<" "<<ctr<<" "<<lf<<"-"<<rt<<endl;
            r = s[rt]-'A';
            //continue if doesnt exist in pattern
            if(MP[r] == 0) continue;
            
            
            M[r]++;
            //same number of occurance as pattern
            if(M[r]==MP[r]){
                ctr++;
            }
            
            //if we have same number of unique charactrs as the pattern, Shrink it
            while(ctr==unq && lf<=rt){
                //cout<<lf<<" "<<rt<<endl;
                if(minn>rt-lf+1){
                    minn = rt-lf+1;
                    pos= lf;
                }
                
                l = s[lf]-'A';
                if(MP[l]==0){
                    lf++;
                    continue;
                }
                
                if(M[l]==MP[l]){
                    ctr--;
                }
                M[l]--;
                
                lf++;
                
            }//while
           
             //cout<<unq<<" "<<ctr<<" "<<lf<<"-"<<rt<<endl;
        }
        
        if(pos ==-1)
            return "";
        else
            return s.substr(pos, minn);
    }
    
    
    string method2(string &str, string &pattern){
        
        /*to calculate freq of each char,

        map value +ive : window has deficit
        map value -ive : window has excess 
        */
        unordered_map<char, int> map;
        
        //calc freq
        for(char ch: pattern)
            map[ch]++;
        
        
        int minLen = INT_MAX, pos = -1, lf=0;
        int matched =0;
        
        for(int rt=0; rt<str.size(); rt++){
            
            //Process In coming
            char inChar = str[rt];
            if(map.find(inChar) != map.end()){

                //1 used by windows
                map[inChar]--;

                if(map[inChar]==0)
                    matched++;

                //cout<<rt<<" found: "<<inChar<<" "<<map[inChar]<<" matched: "<<matched<<endl;
            }
            
            //cout<<lf<<" "<<rt<<" "<<matched<<endl;
            //If the all characters are found in the current window, try to shrink it
            while(lf<=rt && matched== map.size()){
                
                if(minLen> rt-lf+1){
                    minLen = rt-lf+1;
                    pos = lf;

                    //cout<<pos<<": "<<str.substr(pos, minLen)<<endl;
                }
                
                //Process the outgoing elements
                char outChar = str[lf];
                if(map.find(outChar)!=map.end()){
                    

                    if(map[outChar]==0) //freq count will be positive now
                        matched--;

                    map[outChar]++;
                    
                }
                
                lf++;

            }//while
            
        }//for
        
        
        if(pos==-1)
            return "";
        else
            return str.substr(pos, minLen);
        
    }
    
    string minWindow(string s, string t) {
        
        /*
        TC: O(M+N)
        SC: O(58)
        
        3ms - 10MB
        
        
        return method1(s, t);
        */
        
        /* Implementation 2
        
        TC: O(M+N) SC: O(M)
        M- pattern len
        
        12ms 10.8MB
        */
        return method2(s, t);
    }
};
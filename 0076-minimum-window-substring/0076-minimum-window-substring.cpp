class Solution {
public:
    
    string m1(string &s, string &t) {
        
        vector<int> MP(58, 0);
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
            
            //if we have same number of unique charactrs as the pattern
            while(ctr==unq && lf<=rt){
                cout<<lf<<" "<<rt<<endl;
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
    
    string findSubstring(const string &str, const string &pattern) {
        int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : pattern) {
          charFrequencyMap[chr]++;
        }

        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
          char rightChar = str[windowEnd];
          if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
            charFrequencyMap[rightChar]--;
            if (charFrequencyMap[rightChar] >= 0) {  // count every matching of a character
              matched++;
            }
          }

          // shrink the window if we can, finish as soon as we remove a matched character
          while (matched == pattern.length()) {
            if (minLength > windowEnd - windowStart + 1) {
              minLength = windowEnd - windowStart + 1;
              subStrStart = windowStart;
            }

            char leftChar = str[windowStart++];
            if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
              // note that we could have redundant matching characters, therefore we'll decrement the
              // matched count only when a useful occurrence of a matched character is going out of the
              // window
              if (charFrequencyMap[leftChar] == 0) {
                matched--;
              }
              charFrequencyMap[leftChar]++;
            }
          }
        }

        return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
  }
    
    string minWindow(string s, string t) {
        
        //return m1(s, t);
        
        
        return findSubstring(s, t);
    }
};
class Solution {
public:
    
    void expandCorners(string &s, int i, int j, int &maxLen, int &beg){
        
        
        int N = s.size();
        
        while(i>=0 && j<N && s[i]==s[j]){
            
            
            if(j-i+1 > maxLen){
                maxLen = j-i+1;
                beg = i;
            }
            i--; j++;
        }
        
    }
    
    
    string longestPalindrome(string s) {
        
        int maxLen =0;
        int beg = 0;
        
        
        for(int i=0; i<s.size(); i++){
            
            expandCorners(s, i, i, maxLen, beg);
            
            expandCorners(s, i, i+1, maxLen, beg);
        }
        
        //cout<<beg<<" "<<maxLen<<endl;
        
        return s.substr(beg, maxLen);
        
    }
};
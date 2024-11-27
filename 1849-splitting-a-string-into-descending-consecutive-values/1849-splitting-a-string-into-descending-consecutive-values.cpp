class Solution {
public:
    
    long long MAXI = 999999999999;
    
    bool dfs(int idx, long long prev, string &s, int counter) {
        
        if(idx == s.size() && counter >1)
            return true;
        
        long long num = 0;
        
        for(int i = idx; i < s.size(); i++) {
        
            num = (num *  10l) + (s[i] - '0');
            
            if(num > MAXI)
                return false;
            
            if( prev != -1 && prev < num){
                //cout<<prev<<" "<<num<<endl;
                return false;
            }
            
            if(prev == -1 || prev-1 == num) {
                //cout<<"num ="<<prev<<" "<<num<<endl;
                if(dfs(i+1, num, s, counter+1))
                    return true;
            }
            

        }
        return false;
    }
    
    
    bool splitString(string s) {
        
        int idx =0;
        while(s[idx]=='0' && idx <s.size())
            idx++;
        
        if(idx-s.size() <= 1) return false;
        
        return dfs(idx, -1, s, 0);
    }
};
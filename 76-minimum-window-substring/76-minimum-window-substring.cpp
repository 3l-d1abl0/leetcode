class Solution {
public:
    
    string m1(string &s, string &t) {
        
        vector<int> MP(58, 0);
        vector<int> M(58, 0);
        
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
            //cout<<unq<<" "<<ctr<<" "<<lf<<"-"<<rt<<endl;
            r = s[rt]-'A';
            if(MP[r] == 0) continue;
            
            M[r]++;
            if(M[r]==MP[r]){
                ctr++;
            }
            
            while(ctr==unq && lf<=rt){
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
    
    string minWindow(string s, string t) {
        
        return m1(s, t);
    }
};
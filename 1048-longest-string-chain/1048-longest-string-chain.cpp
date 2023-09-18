class Solution {
public:
    
    bool compare(string &pre, string &wrd){
        
        int N = pre.size();
        int M = wrd.size();
        
        
        if(M != N+1)
            return false;
        
        int cnt = 0;
        int idx1 =0, idx2 =0;
        
        while(idx1<N && idx2<M){
            
            if(pre[idx1] == wrd[idx2]){
                idx1++;
                idx2++;
            }else{
                cnt++;
                if(cnt>1)
                    return false;
                
                idx2++;
                
            }
            
            
        }
        
        if (idx1 != N)
            return false;
        
        
        //cout<<pre<<" "<<wrd<<" "<<idx1<<""<<idx2<<endl;
        return true;
        
        
    }
    
    
    bool static cmp(string &a, string &b){
        return a.size() <b.size();
    }
    int longestStrChain(vector<string>& words) {
        
        
        auto myFunction = [&](string& s1, string& s2) {
            return s1.length() < s2.length();
        };
        
        
        
        sort(words.begin(), words.end(), myFunction);
        
        int N = words.size();
        vector<int> lis(N, 1);
        
        
        int maxx_lis = lis[0];
        for(int i=1; i<N; i++){
            
            for(int j=0; j<i; j++){
                
                if(compare(words[j], words[i])  && lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                }
                
            }//for j
            
            if(maxx_lis < lis[i]){
                maxx_lis = lis[i];
            }
            
        }//for i
        
        
        
        return maxx_lis;
    }
};
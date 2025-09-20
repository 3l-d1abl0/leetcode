class Solution {
public:
    
    bool angram(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2){
        
        
        if(mp1.size()!= mp2.size())  return false;
        
        for(auto it= mp1.begin(); it!= mp1.end(); it++){
            
            if(mp2[(*it).first] != (*it).second)
                return false;
        }
        
        return true;
    }
    
    bool method1(string s1, string s2){
        
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        int N = s1.size();//pattern
        int M = s2.size();
        
        if(N>M) return false;
        
        for(int i=0; i<N; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        
        
        for(int i=0; i<=M-N; i++){
            
            
            if(angram(mp1, mp2)){
                return true;
            }
            
            //cout<<"i ="<<i<<endl;
            if(i<M-N){
                mp2[s2[i]]--;   //remove the left most element
                if(mp2[s2[i]]==0)
                    mp2.erase(s2[i]);

                mp2[s2[i+N]]++; //add the rightmost element
            }
            
            
        }
        
        
        return false;
        
    }
    
    bool method2(string s1, string s2){
        //s1-  pattern
        
        //lower case, hence only 26 characters
        vector<short int> m1(26, 0);    
        vector<short int> m2(26, 0);
        
        int N = s1.size();
        int M = s2.size();
        
        if(N>M) return false;
        
        //first N charcters
        for(int i=0; i<N; i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        
        int count =0;
        for(int i=0; i<26; i++){
            if(m1[i]==m2[i])
                count++;
        }
        
        //if everything matches in first N charcters
        if(count ==26) return true;
        
        
        int lf =0;
        //Keep a constant window of Size N (len(pat))
        for(int rt=N; rt<M; rt++){
            
            if(count ==26) return true;
            
            //process incoming element
            int r= s2[rt]-'a';
            m2[r]++;
            
            if(m2[r]==m1[r]){
                count++;
            }else if(m2[r] == m1[r]+1){
                count--;
            }
            
            //process outgoing element
            int l=s2[rt-N]-'a';
            m2[l]--;
            if(m2[l]==m1[l]){
                count++;
            }else if(m2[l] == m1[l]-1){
                count--;
            }
            
        }
        
        return count ==26;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        /*s1 ="ab";
        s2="baeidooo";*/
        
        return method1(s1, s2);   //O(M*N)
        
        //return method2(s1, s2);
        
        
    }
};
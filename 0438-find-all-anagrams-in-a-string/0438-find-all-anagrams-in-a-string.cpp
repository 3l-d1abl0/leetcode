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
    
    
    vector<int> method2(string &s, string &p){
        
        vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int len = s.size();
        if(len < window)
        {
            return ans;
        }
        int left = 0,right = 0;
        while(right < window)
        {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -=1;
        
        while(right < len)
        {
            if(phash == hash)
            {
                ans.push_back(left);
            }
            right+=1;
            if(right != len)
            {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -=1 ;
            left += 1;
        }
        return ans;
    
        
        
    }
    
    vector<int> method1(string &s2, string &s1){
        
        vector<int> occ;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        int N = s1.size();
        int M = s2.size();
        
        if(N>M) return {};
        
        for(int i=0; i<N; i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        
        
        for(int i=0; i<=M-N; i++){
            
            
            if(angram(mp1, mp2)){
                occ.push_back(i);
            }
            
            //cout<<"i ="<<i<<endl;
            if(i<M-N){
                mp2[s2[i]]--;   //remove the left most element
                if(mp2[s2[i]]==0)
                    mp2.erase(s2[i]);

                mp2[s2[i+N]]++; //add the rightmost element
            }
            
            
        }
        
        
        return occ;
        
    }
    
    vector<int> method3(string s2, string s1){
        //s1-  pattern
        
        vector<int> occ;
        vector<short int> m1(26, 0);    
        vector<short int> m2(26, 0);
        
        int N = s1.size();
        int M = s2.size();
        
        if(N>M) return occ;
        
        for(int i=0; i<N; i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        
        int count =0;
        for(int i=0; i<26; i++){
            if(m1[i]==m2[i])
                count++;
        }
        
        
        
        
        for(int rt=N; rt<M; rt++){
            
            if(count ==26){
             //cout<<rt<<"\n";
                occ.push_back(rt-N);
            }
            
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
        
        if(count ==26){
             //cout<<M-N<<"\n";
                occ.push_back(M-N);
        }
        
        return occ;
    }
    
    vector<int> findAnagrams(string s2, string s1) {
        
        //return method1(s2, s1);
        //return method2(s2, s1);
        return method3(s2, s1);
        
    }
};
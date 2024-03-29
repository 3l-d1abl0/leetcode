class Solution {
public:
    
    
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
            
            //Whole vector Compare
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
    
    bool angram(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2){
        
        
        if(mp1.size()!= mp2.size())  return false;
        
        for(auto it= mp1.begin(); it!= mp1.end(); it++){
            
            if(mp2[(*it).first] != (*it).second)
                return false;
        }
        
        return true;
    }
    
    vector<int> method1(string &str, string &pattern){
        
        vector<int> occ;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        int N = pattern.size();
        int M = str.size();
        
        //If patttern length is Greater
        if(N>M) return {};
        
        //freq count of first N character
        for(int i=0; i<N; i++){
            mp1[pattern[i]]++;
            mp2[str[i]]++;
        }
        
        
        for(int i=0; i<=M-N; i++){
            
            //For every Window check if its freq count is same
            if(angram(mp1, mp2)){
                occ.push_back(i);
            }
            
            //cout<<"i ="<<i<<endl;
            if(i<M-N){
                mp2[str[i]]--;   //remove the left most element
                if(mp2[str[i]]==0)
                    mp2.erase(str[i]);

                mp2[str[i+N]]++; //add the rightmost element
            }
            
            
        }
        
        
        return occ;
        
    }
    
    vector<int> method3(string &str, string &pattern){
        //s1-  pattern
        
        vector<int> occ;
        vector<short int> m1(26, 0);    
        vector<short int> m2(26, 0);
        
        int N = pattern.size();
        int M = str.size();
        
        //If pattern length is greater than String
        if(N>M) return occ;
        
        
        
        //Process the pattern and first N elements
        for(int i=0; i<N; i++){
            m1[pattern[i]-'a']++;
            m2[str[i]-'a']++;
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
            int r= str[rt]-'a';
            m2[r]++;
            
            if(m2[r]==m1[r]){
                count++;
            }else if(m2[r] == m1[r]+1){
                count--;
            }
            
            //process outgoing element
            int l=str[rt-N]-'a';
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
    
    
    
    vector<int> method4(string &pattern, string &str){
        
        unordered_map<char, int> map;
        
        if(pattern.size() > str.size())
            return {};
        
        
        vector<int> ans;
        
        ///freq table for pattern
        for(char ch: pattern){
            map[ch]++;
        }
        
        int freqCount=0, lf=0;
        for(int rt=0; rt<str.size(); rt++){
            
            //process incoming character
            char inChar = str[rt];
            if(map.find(inChar) != map.end()){
                
                map[inChar]--;
                if(map[inChar]==0){
                    freqCount++;
                }
            }
            
            
            
            //process outgoing character
            if(rt>=pattern.size()){
                
                char outChar = str[lf];
                if(map.find(outChar) != map.end()){
                    
                    if(map[outChar]==0){
                        freqCount--;
                    }
                    
                    map[outChar]++;
                }
                
                lf++;
            }//if
            
            if(freqCount== map.size())
                ans.push_back(lf);
        }
        
        
        return ans;
    }
    vector<int> findAnagrams(string s2, string s1) {
        //TC: O(M-N * N) SC: O(M+N) //M - size of str, N - size of pattern - 41ms
        //return method1(s2, s1);
        
        //TC: O(M-N * N) SC: O(M+N) //M - size of str, N - size of pattern  - 14ms
        //return method2(s2, s1);
        
        //TC: O(N+M) SC: O(M+N) //
        //return method3(s2, s1);
        
        
        
        //TC: O(M+N)    SC: O(M)
        return method4(s1, s2);
        
    }
};
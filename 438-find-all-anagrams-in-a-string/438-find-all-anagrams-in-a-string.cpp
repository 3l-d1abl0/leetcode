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
    
    vector<int> findAnagrams(string s2, string s1) {
        
        
        return method2(s2, s1);
     
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
};
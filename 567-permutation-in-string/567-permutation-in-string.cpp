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
    
    bool checkInclusion(string s1, string s2) {
        
        /*s1 ="ab";
        s2="baeidooo";*/
        
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        
        int N = s1.size();
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
};
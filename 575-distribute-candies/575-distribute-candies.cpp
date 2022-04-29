class Solution {
public:
    int distributeCandies(vector<int>& ct) {
        
        unordered_set<int> can;
        
        int N = ct.size();
        
        for(int i=0; i<N; i++){
            
            if(can.find(ct[i]) == can.end())
                can.insert(ct[i]);
            
        }
        
        int ty = can.size();
        
        return min(ty, N/2);
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> vec;
        vec.push_back(0);
        
        for(int i=1; i<=n; i++){
            
            int ctr =0;
            int num = i;
            while(num){
                ctr++;
                
                num = num & (num-1);
            }
            
            vec.push_back(ctr);
        }
        
        return vec;
    }
};
class Solution {
public:
    
    
    
    void combRec(int idx, vector<vector<int>> &ans, vector<int> &combination, int target, int k){

        //cout<<"idx :: "<<idx<<" tar :: "<<target<<endl;
        if( k == combination.size()){
            
            if(target ==0){
                
                ans.push_back(combination);
                //cout<<"idx = "<<idx<<endl;
                return;
            }
            
            return;
        }

        if(idx>9) return;

        for(int i=idx; i<=9; i++ ){

            if(target >= i){
                combination.push_back(i);
                combRec(i+1, ans, combination, target - i, k);
                combination.pop_back();
            }

        }


    }
    
    
    vector<vector<int>> combinationSum3(int k, int target) {
        
        
        
        vector<vector<int>> ans;
        vector<int> combination;
        
        combRec(1, ans, combination, target, k);
        
     
        return ans;
        
        
    }
};
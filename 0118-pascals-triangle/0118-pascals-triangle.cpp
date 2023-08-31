class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        
        vector<vector<int>> vec(numRows, vector<int>(1,1));
        
        for(int row=1; row<numRows; row ++){
            
            
            for(int col =1; col<row; col++){
                vec[row].push_back(vec[row-1][col]+vec[row-1][col-1]);
            }
            
            vec[row].push_back(1);
        }//for
        
        
        return vec;
    }
};
class Solution {
public:
    
    int method1( vector<vector<int>> &matrix, int key){
            
        int R = matrix.size();
	int C = matrix[0].size();
	
	int x= 0, y=C-1;
	
	while(x<R && y>-1){
		
		if(matrix[x][y] == key){
			return true;
		}else if(key> matrix[x][y]){
			x++;
		}else{
			y--;
		}
		
	}
	
	return false;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
        
        
        //1. method1
        return method1(matrix, key);
    
	
    }
};
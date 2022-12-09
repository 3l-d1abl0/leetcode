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
    
    int method2(vector<vector<int>> &matrix, int key){
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        int total = N*M;
        int l = -1;
        int r= total;
        
        
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            
            //cout<<mid<<" "<<mid/total<<" "<<mid%total<<endl;
            //cout<<matrix[mid/M][mid%M]<<" "<<endl;
            if(matrix[mid/M][mid%M] < key){
                
                l = mid;
                
            }else{
                r=mid;
            }
            
        }
       
        //cout<<l<<" "<<r<<endl;
        if (r==total)
            return false;
        else
            return matrix[r/M][r%M] == key;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
        
        
        //1. method1
        //return method1(matrix, key);
    
        //2. method2 - Binary Search
        return method2(matrix, key);
	
    }
};
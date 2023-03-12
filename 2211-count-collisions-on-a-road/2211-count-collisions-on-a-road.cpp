class Solution {
public:
    int countCollisions(string dir) {
  
        int N = dir.size();
        int left =0;
        int right = N-1;
        
        while(left <N && dir[left]=='L'){
            left++;
        }
        
        while(right >=0 && dir[right]=='R'){
            right--;
        }
        
        
        int ctr=0;
        for(int i=left; i<=right; i++){
            if(dir[i]!='S')
                ctr++;
        }
        
        
        return ctr;
    }
};
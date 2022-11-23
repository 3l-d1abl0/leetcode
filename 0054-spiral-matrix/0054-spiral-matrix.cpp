class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        int r= matrix.size();
        int c = matrix[0].size();
        
        int N = r*c;
        
        int ctr=0;
        int lf=0, rt= c-1;
        int tp=0, dw=r-1;
        
        
        vector<int> ans (N, 0);
        //1 -> 2 ->3 -> 4
        
        int dir =1;
        while(ctr<N){
            
            
            if(dir==1){
                
                for(int col=lf; col<=rt; col++){
                    ans[ctr] = matrix[tp][col];
                    ctr++;
                }
                
                dir =2;
                tp++;
            }else if(dir==2){
                
                for(int row=tp; row<=dw; row++){
                    ans[ctr] = matrix[row][rt];
                    ctr++;
                }
                
                dir=3;
                rt--;
            }else if(dir==3){
                
                for(int col=rt; col>=lf; col--){
                    ans[ctr] = matrix[dw][col];
                    ctr++;
                }
                dir=4;
                dw--;
            }else if(dir==4){
                
                for(int row=dw; row>=tp; row--){
                    ans[ctr] = matrix[row][lf];
                    ctr++;
                }
                dir=1;
                lf++;
            }
        }//while
        
        
        return ans;
        
        
    }
};
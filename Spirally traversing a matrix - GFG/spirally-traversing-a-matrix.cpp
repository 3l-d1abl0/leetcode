//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
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

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
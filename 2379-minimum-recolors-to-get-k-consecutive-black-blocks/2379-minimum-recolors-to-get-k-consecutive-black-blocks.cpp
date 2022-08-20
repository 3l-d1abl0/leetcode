class Solution {
public:
    
    int minimumRecolors(string blocks, int k) {
        
        int N = blocks.size();
        vector<int> b(N, 0);
        //vector<int> w(N, 0);
        
        b[0] = blocks[0]=='B'?1:0;
        //w[0] = blocks[0]=='W'?1:0;
        for(int i=1;i<N; i++){
         
            b[i] = b[i-1] + (blocks[i]=='B'?1:0);
            //w[i] = w[i-1] + (blocks[i]=='W'?1:0);
        }
        
        
       /* for(auto ele: b){
            cout<<ele<<" ";
        }cout<<endl;
        
        
        for(auto ele: w){
            cout<<ele<<" ";
        }cout<<endl;
        
        
        
        
        for(int i=0; i<=N-k; i++){
            
            int b_count = b[i+k-1] - (i-1<=0?0:b[i-1]);
            cout<<b_count<<endl;
            minn = max(minn, b_count);
            
        }*/
        
        int minn=INT_MIN;
        int ctr=0;
        
         for(int i=0;i<=N-k;i++){
             
            ctr=0;
             
            for(int j=i;j<(k+i);j++){
                if(blocks[j]=='B'){
                    ctr++;
                }
            }
             
            minn=max(minn,ctr);
        }
        
        
        return k-minn;
    }
};
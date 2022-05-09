class Solution {
public:
    
    long long int calculateProducts(vector<int> &quantities, long long int k){

        long long int sum = 0;
        for(int ele: quantities){
            sum +=ceil((double)ele/k);
        }

        return sum;

    }
    
    
    int minimizedMaximum(int h, vector<int>& quantities) {
        
        
        long long int l = 1, r= *max_element(quantities.begin(), quantities.end());
        //cout<<l<<" "<<r<<endl;
        //cout<<calculateProducts(piles, 1)<<endl;
        l--; r++;
        while(r-l>1){
            
            long long int k = l+(r-l)/2;
            
            if(calculateProducts(quantities, k) <=h){ //try to get more less till the condition satifies
                r=k;
            }else{
                l=k;
            }
        
            //cout<<l<<" "<<r<<" -- "<<k<<endl;
        }
        
        
        return r;
    }
};
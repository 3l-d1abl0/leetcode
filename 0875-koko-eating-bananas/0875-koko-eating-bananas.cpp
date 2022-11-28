class Solution {
public:
    
    long long int calculateHrs(vector<int> &piles, int k){
        
        if(k==0)
            return INT_MAX;
        
        long long int sum = 0;
        for(int ele: piles){
            sum +=ceil((double)ele/k);
        }
        
        return sum;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r= *max_element(piles.begin(), piles.end());
        //cout<<l<<" "<<r<<endl;
        //cout<<calculateHrs(piles, 1)<<endl;
        l--; r++;
        
        //int l=-1, r= 1e4+1;
        while(r-l>1){
            
            long long int k = l+(r-l)/2;
            
            if(calculateHrs(piles, k) <=h){ //try to get more less till the condition satifies
                r=k;
            }else{
                l=k;
            }
        
            //cout<<l<<" "<<r<<" -- "<<k<<endl;
        }
        
        
        return r;
        
        
    }
};
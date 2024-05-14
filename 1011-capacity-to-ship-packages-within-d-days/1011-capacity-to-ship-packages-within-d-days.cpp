class Solution {
public:
    
    int daysTaken(vector<int> &weights, int cap){
        
        
        int ctr =1;
        int sum =weights[0];
        for(int ele = 1; ele< weights.size(); ele++){
            
            if(sum+weights[ele] > cap){
                ctr++;
                sum = weights[ele];
            }else{
                sum += weights[ele];
            }
            
        }
        
        
        return ctr;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        /*
            if days =1 =>> ccap = sum
            if days = weights.len ==>> cap = max(weights)
        */
        
        /*
            If capcity falls below the max height,
            the packages with max size wount to able to get 
            loaded ever.
        */
        int l = *max_element(weights.begin(), weights.end());
        
        int r = accumulate(weights.begin(), weights.end(), 0);
        
        l--; r++;
        //cout<<daysTaken(weights, 6)<<endl;
        
        while(r-l >1){
            
            int cap = l +(r-l)/2;
            
            if(daysTaken(weights, cap) <=days){
                r= cap; //try for more less
            }else{
                l = cap;
            }
            
        }
        
        //cout<<l<<" "<<r<<endl;
        
        return r;
    }
};
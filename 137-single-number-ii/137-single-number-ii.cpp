class Solution {
public:
    
    int method2(vector<int> &nums){
        
        long long int sum=0;
        unordered_set<int> st;
        for(int ele: nums){
            st.insert(ele);
            sum+=ele;
        }
        
        long long int usum =0;
        for(int ele: st){
            usum +=ele;
        }
        
        
        return (sum - 3*(sum-usum)/2);
        
        
    }
    int singleNumber(vector<int>& nums) {
        
        return method2(nums);
        
        int ans=0;
        //31 bit
        for(int i=0; i<=31; i++){
            
            int bitCount=0;
            for(int ele: nums){
                
                if( ((ele>>i) & 1) ==1) //check how many ele has ith bit set
                    bitCount++;
            }
            
            bitCount = bitCount%3;  //0 or 1
            //cout<<bitCount<<endl;
            if(bitCount==1){
                ans = ans| (bitCount<<i);  //set the ith bit;
            }
            
        }//for
        
        
        return ans;
    }
};
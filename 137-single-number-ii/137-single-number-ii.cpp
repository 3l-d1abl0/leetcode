class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
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
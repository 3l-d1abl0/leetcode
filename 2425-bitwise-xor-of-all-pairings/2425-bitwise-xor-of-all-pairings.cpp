class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int N1 = nums1.size();
        int N2 = nums2.size();
        
        if( N1%2==0 && N2%2==0 )
            return 0;
        
        int xor1 = 0;
        for(int ele: nums1) xor1^=ele;
        
        if(N1%2==0 && N2%2!=0)
            return xor1;
        
        int xor2 =0;
        for(int ele: nums2) xor2^=ele;
                
        if(N1%2!=0 && N2%2==0)
            return xor2;
        
        
        //if(N1%2!=0 && N2%2!=0)
            return (xor1^xor2);
    }
};
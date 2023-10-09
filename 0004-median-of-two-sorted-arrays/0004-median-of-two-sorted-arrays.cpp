class Solution {
public:
    
    double findMedian(vector<int>& nums1, vector<int>& nums2) {
        
        /*
            num1 is the smaller array
            arr1: [     L1] | [R1            ]
            [   L2]   | [R2       ]
            
            Pick L1 from the first element
            pick L2 after calculating the rest
            
            if sum is odd: 
            sum/2 lies in left half
            else
            sum/2 -1 lies in left half and sum/2 lies in First half
        */
        
        int N = nums1.size();
        int M = nums2.size();
        
        
        int l = 0, r = N;
        int medianPosition = (N + M + 1) / 2;
        
        while(l<=r){
            
            int L1 = l + (r-l)/2; //(elements)
            int L2 = medianPosition - L1;
            
            int minL1 = L1>0 ? nums1[L1-1]:INT_MIN;
            int maxR1 = L1<N ? nums1[L1]:INT_MAX;
            
            int minL2 = L2>0 ? nums2[L2-1]:INT_MIN;
            int maxR2 = L2<M ? nums2[L2]: INT_MAX;
            
            
            if(minL1 <= maxR2 && minL2 < maxR1){
                
                if((N+M)&1){
                    return max(minL1, minL2);
                }else{
                    return (max(minL1, minL2) + min(maxR1, maxR2))/2.0;
                }
                
            }else if (minL1 > maxR2){
                r = L1-1;
            }else{
                l = L1+1;
            }
            
        }//while
        
        
        return 0.0;
        
    }//double
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() < nums2.size())
            return findMedian(nums1, nums2);
        else
            return findMedian(nums2, nums1);
        
    }
};
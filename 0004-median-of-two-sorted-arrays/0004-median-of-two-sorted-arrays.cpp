class Solution {
public:
    
    double findMedian(vector<int>& nums1, vector<int>& nums2) {
        
        //Array1 is smaller in Length
        
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
        
        
        int l = 0, r = N;//Boundaries of 1st Array
        int medianPosition = (N + M + 1) / 2;
        
        while(l<=r){
            
            int N1 = l + (r-l)/2; //(elements)
            int N2 = medianPosition - N1;
            
            
            int L1 = N1>0 ? nums1[N1-1]:INT_MIN; int R1 = N1<N ? nums1[N1]:INT_MAX;
            
            int L2 = N2>0 ? nums2[N2-1]:INT_MIN; int R2 = N2<M ? nums2[N2]: INT_MAX;
            
            
            if(L1 <= R2 && L2 < R1){
                
                if((N+M)&1){
                    return max(L1, L2);
                }else{
                    return (max(L1, L2) + min(R1, R2))/2.0;
                }
                
            }else if (L1 > R2){
                r = N1-1;
            }else{
                l = N1+1;
            }
            
        }//while
        
        
        return 0.0;
        
    }//double
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //smaller array first
        
        if(nums1.size() < nums2.size())
            return findMedian(nums1, nums2);
        else
            return findMedian(nums2, nums1);
        
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
                int N = nums.size();
        int leftP =0, rightP = N-1;

        vector<int> ans(N, 0);
        int idx = N-1;
        while(leftP<=rightP){

            int leftSq = nums[leftP]*nums[leftP];
            int rightSq = nums[rightP]*nums[rightP];

            if(leftSq>=rightSq){
                    ans[idx] = leftSq;
                    idx--;
                    leftP++;
            }else{
                ans[idx] = rightSq;
                idx--;
                rightP--;
            }
        }//while


        return ans;
        
        
    }
};
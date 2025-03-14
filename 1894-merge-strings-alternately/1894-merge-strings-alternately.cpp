class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int N = word1.size();
        int M = word2.size();
        string ans (N+M, 'X');
        int ansIdx =0;


        int idx1=0, idx2=0;
        bool flag = true;

        while(idx1<N && idx2<M){
            
            if (flag)
                ans[ansIdx] = word1[idx1++];
            else
                ans[ansIdx] = word2[idx2++];

            ansIdx++;
            flag = !flag;
        }

        while(idx1<N)
            ans[ansIdx++] = word1[idx1++];
        
        while(idx2<M)
            ans[ansIdx++] = word2[idx2++];

        return ans;
    }
};
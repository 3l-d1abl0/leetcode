class Solution {
public:
    int hIndex(vector<int>& citations) {


        int N = citations.size();

        int l=-1, r=N;

        while(r-l>1){

            int mid = l+(r-l)/2;

            int h = N-mid;

            if(citations[mid]>=h){
                r=mid;//go left
            }else{
                l=mid;
            }
        }



        return N-r;
        
    }
};
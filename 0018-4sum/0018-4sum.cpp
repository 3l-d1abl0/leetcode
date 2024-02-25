class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {

        //TC: O(NlogN + N^3)
        
                int N = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        //              N-3  N-2  N-1
        for(int i=0; i<N-3; i++){

            if(i>0 && arr[i]==arr[i-1])
                continue;

            for(int j=i+1; j<N-2; j++){


                if(j>i+1 && arr[j]==arr[j-1])
                    continue;


                int lf = j+1;
                int rt = N-1;
                
                long long int remain = target -arr[i];
                remain += - arr[j];
                while(lf<rt){
                    
                    if(arr[lf] + arr[rt] == remain){

                        ans.push_back({arr[i], arr[j], arr[lf], arr[rt]});
                        lf++;
                        rt--;
                        
                        while( lf<N && arr[lf] == arr[lf-1]) lf++;
                        while( rt>=0 && arr[rt] == arr[rt+1]) rt--;

                    }else if (arr[lf] + arr[rt] < remain){
                        lf++;
                    }else{
                        rt--;
                    }
                }//while

            }//for

        }//for

      return ans;
    }
};
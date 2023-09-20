class Solution {
public:
    
    
    vector<int> getSubSeqSum(vector<int> &arr, int st, int ed, int offset){

        //cout<<st<<" "<<ed<<" "<<offset<<endl;

        int N = ed-st+1;
        vector<int> sums;
        for(int mask =0; mask < (1<<N); mask++){

            int sum =0;
            for(int i=0; i<N; i++){

                if(mask&(1<<i)){

                    sum+=arr[i+offset];
                }
            }

            sums.push_back(sum);
        }

        /*for(int ele: sums)
            cout<<ele<<" ";
        cout<<endl;*/

        return sums;
    }

    int minAbsDifference(vector<int> &arr, int goal){

        int N = arr.size();

        if(N==1)
            return min( abs(goal),  //when you avoid all and take 0 as sum
                        abs(goal-arr[0]));


        int mid = (N&1)? N/2: (N/2)-1;

        vector<int> subSeqSum1 = getSubSeqSum(arr, 0, mid, 0);
        vector<int> subSeqSum2 = getSubSeqSum(arr, mid+1, N-1, mid+1);

        sort(subSeqSum2.begin(), subSeqSum2.end());

        int minn = INT_MAX;
        for(int ele: subSeqSum1){

            int toFind = goal- ele;
            int foundNum = lower_bound(subSeqSum2.begin(), subSeqSum2.end(), toFind) - subSeqSum2.begin();

            /*
                Look for 2 elements:
                1) >= the num
                2) the one before
                after all we have to find the minimum difference
            */

            if(foundNum >0){
                int diff = abs(toFind-subSeqSum2[foundNum-1]);
                minn = min(minn, diff);
            }
            
            if(foundNum < subSeqSum2.size()){
                int diff = abs(toFind-subSeqSum2[foundNum]);
                minn = min(minn, diff);
            }

            //cout<<":: "<<ele<<" "<<toFind<<" "<<foundNum<<" "<<diff<<endl;
            
        }


        return minn;
    }
    
    
};
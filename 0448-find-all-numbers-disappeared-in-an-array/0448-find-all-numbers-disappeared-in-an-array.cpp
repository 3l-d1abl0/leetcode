class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        
        
            int N = arr.size();

    int i=0;
    while(i<N){

        int idx = arr[i]-1;

        if(arr[i]!= arr[idx]){
            swap(arr[i], arr[idx]);
        }else{
            i++;
        }
    }//while


    vector<int> ans;
    for(int i=0; i<N; i++){
        int idx = arr[i]-1;
        if(i!= idx)
        ans.push_back(i+1);
    }


    return ans;
        
        
    }
};
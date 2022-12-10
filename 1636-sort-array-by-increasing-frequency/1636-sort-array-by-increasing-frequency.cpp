//int freq[201] = {0};
vector<int> freq(201, 0);

/*struct CompareFn{
  
    bool operator()(int &a, int &b){
        
        if(freq[a+100]==freq[b+100])
            return a <b;
        
        return freq[a+100] > freq[b+100];
        
    }
    
};*/

    
bool compare(int &a, int &b){
        //cout<<freq[a+100]<<" "<<freq[b+100]<<endl;
    
        if(freq[a+100]==freq[b+100])
            return a >b;
        
        return freq[a+100] < freq[b+100];
        
}


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        fill(freq.begin(), freq.end(), 0);
        
        for(int ele: nums){
            freq[ele+100]++;
        }
        
        sort(nums.begin(), nums.end(), compare);
        
        return nums;
    }
};
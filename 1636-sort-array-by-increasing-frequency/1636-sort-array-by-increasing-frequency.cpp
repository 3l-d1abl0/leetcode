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
        //if frequency eaual
        if(freq[a+100]==freq[b+100])
            return a >b;    ///decreasing order
        
        return freq[a+100] < freq[b+100];   //increasing order
        
}


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int> freq(201, 0);
        //fill(freq.begin(), freq.end(), 0);
        
        for(int ele: nums){
            freq[ele+100]++;
        }
        
        //sort(nums.begin(), nums.end(), compare);
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return freq[a + 100] == freq[b + 100] ? a > b : freq[a + 100] < freq[b + 100];
        });
        
        return nums;
    }
};
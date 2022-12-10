//int freq[201] = {0};
vector<int> freq(201, 0);

struct Node{
    int freq;
    int num;
};

struct CompareFn{
    bool operator()(Node const &a, Node const &b){
        
        if(a.freq ==b.freq)
            return a.num <b.num; //bigger first, descending
        
        return a.freq > b.freq; //smaller freq first, ascending
        
    }
    
};

    
bool compare(int &a, int &b){
        //cout<<freq[a+100]<<" "<<freq[b+100]<<endl;
        //if frequency eaual
        if(freq[a+100]==freq[b+100])
            return a >b;    ///decreasing order
        
        return freq[a+100] < freq[b+100];   //increasing order
        
}


class Solution {
public:
    
    vector<int> useHeap(vector<int> &nums){
        
        unordered_map<int, int> freq;
        for(int ele: nums){
            freq[ele]++;
        }
        
        priority_queue<Node, vector<Node>, CompareFn> hp;
        
        for(auto [f, s]: freq)
            hp.push({s, f});
        
        vector<int> ans;
        while(!hp.empty()){
            int num = hp.top().num;
            int freq = hp.top().freq;
            //cout<<hp.top().num<<" "<<hp.top().freq<<endl;
            for(int i=0; i<freq; i++){
                ans.push_back(num);
            }
            hp.pop();
        }
        
        return ans;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        
        
        //1. method1 - use heap
        return useHeap(nums);
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
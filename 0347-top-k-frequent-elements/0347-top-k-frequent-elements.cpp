class Solution {
public:
    
    vector<int> method1(vector<int> &nums, int k){
        
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        
        
        for (auto num : nums) cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
        
    }
    
    
    vector<int> method2(vector<int> &nums, int k){
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        for (auto kv : cnt) {
            pq.push({kv.second, kv.first});
            while (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //1. method1
        //return method1(nums, k);
        
        //2. method2 - heap
        return method2(nums, k);
        
        //3. Method3 - QuickSelect
        vector<int> res;
        if (!nums.size()) return res;
        
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        
        vector<pair<int, int>> num_with_cnt;
        for (auto kv : cnt) {
            num_with_cnt.push_back({kv.first, kv.second});
        }
        kselection(num_with_cnt, 0, num_with_cnt.size()-1, k);
        for (int i = 0; i < k && i < num_with_cnt.size(); ++i) {
            res.push_back(num_with_cnt[i].first);
        }
        return res;
    }

    void kselection(vector<pair<int, int>>& data, int start, int end, int k) {

        if (start >= end) return;
        
        int rng = (rand() % (end-start+1) ) + start;
        swap(data[rng], data[end]);
        
        auto pv = data[end];
        int i = start;
        int j = start;
        while (i < end) {
            if (data[i].second > pv.second) {
                swap(data[i++], data[j++]);
            } else {
                ++i;
            }
        }
        swap(data[j], data[end]);
        int num = j - start + 1;
        if (num == k) return;
        else if (num < k) {
            kselection(data, j + 1, end, k - num);
        } else {
            kselection(data, start, j - 1, k);
        }
        
    }
};
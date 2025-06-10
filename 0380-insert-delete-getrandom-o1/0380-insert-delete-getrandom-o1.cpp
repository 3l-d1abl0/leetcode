class RandomizedSet {
    //unordered_set<int> st;
    unordered_map<int, int> mp;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // if(st.find(val)!= st.end()){
        //     return false;
        // }else{
        //     st.insert(val);
        //     return true;
        // }

        if(mp.find(val) != mp.end())
            return false;

        //put at the end
        nums.push_back(val);
        mp[val] = nums.size()-1;//[val] ==> index

        return true;
    }
    
    bool remove(int val) {
        // if(st.find(val)!= st.end()){
        //     st.erase(val);
        //     return true;
        // }else{
        //     return false;
        // }

        //replace with last element, then remove the last element
        if(mp.find(val) == mp.end())
            return false;

        int valIdx = mp[val];
        int lastIdx = nums.size()-1;

        //cout<<valIdx<<" "<<lastIdx<<endl;

        swap(nums[valIdx], nums[lastIdx]);
        mp[nums[valIdx]] = valIdx;
        mp.erase(val);
        nums.pop_back();
        // cout<<"removed ... "<<val<<endl;
        //         for(int ele: nums)
        //             cout<<mp[ele]<<" :"<<ele<<" ";
        // cout<<"========="<<endl;
        return true;

    }
    
    int getRandom() {
        // int lim = rand() % st.size();
        // unordered_set<int>::iterator it=st.begin();
        // int idx =0;
        // for (it = st.begin(); idx <lim && it != st.end(); ++it) {
        //     idx++;
        // }
        // return *it;
        // for(int ele: nums)
        //     cout<<ele<<" ";
        // cout<<endl;
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
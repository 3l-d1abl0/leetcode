class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> mp;
        
        for(int i=nums2.size()-1; i>=0; i-- ){
            
            while(!st.empty() && nums2[i]>= st.top())
                st.pop();
            
            if(st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();
            
            
            st.push(nums2[i]);
        }//for
        
        
        /*
        unordered_map<int, int>::iterator it;
        for(it= mp.begin(); it!= mp.end(); it++)
            cout<<it->first<<" "<<it->second<<endl;*/
        
        vector<int> res;
        for(int ele: nums1){
            res.push_back(mp[ele]);
        }
        
        
        return res;
    }
};
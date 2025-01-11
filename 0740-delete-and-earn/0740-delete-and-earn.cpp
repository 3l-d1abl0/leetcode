class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        map<int, int> mp;
        //compute frequency
        for(int &ele: nums){
            mp[ele]++;
        }
        // 3=>x, 6=> y , 7 => z
        vector<pair<int, int>> arr;
        for(auto obj: mp){
            arr.push_back(obj);
        }

        //Base case
        if(arr.size()==1)
            return arr[0].first*arr[0].second;

        // for(auto ele: arr){
        //     cout<<ele.first<<" "<<ele.second<<endl;
        // }


        vector<int> dp(arr.size(), -1);

        //Base case
        dp[0] = arr[0].first*arr[0].second;
        dp[1] = max(dp[0], (arr[0].first+1 == arr[1].first) ? arr[1].first*arr[1].second : (dp[0]+arr[1].first*arr[1].second));

        for(int i=2; i<arr.size(); i++){
            int include = (arr[i-1].first+1 == arr[i].first) ? (dp[i-2]+arr[i].first*arr[i].second) : (dp[i-1]+arr[i].first*arr[i].second);
            int exclude = dp[i-1];
            dp[i] = max(include, exclude);
        }


        // for(int ele: dp)
        //     cout<<ele<<" ";



        return dp[arr.size()-1];
    }
};
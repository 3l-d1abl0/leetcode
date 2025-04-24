class RangeFreqQuery
{


public:

        unordered_map<int, vector<int>> mp;
    
    /*int N;
    unordered_map<int, int> *seg;*/
    RangeFreqQuery(vector<int> &arr){
        //method0 - Array of Freq
        //method1 - for every number keep a array of indices it appear in
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].push_back(i);  //capture the index it appears in

        /*N = arr.size();
        seg = new unordered_map<int, int>[4 * N];

        buildSeg(0, 0, N - 1, arr);*/
    }

    // void buildSeg(int index, int low, int high, vector<int> &arr)
    // {

    //     if (low == high)
    //     {
    //         seg[index][arr[low]]++;
    //         return;
    //     }

    //     int mid = low + (high - low) / 2;

    //     buildSeg(2 * index + 1, low, mid, arr);
    //     buildSeg(2 * index + 2, mid + 1, high, arr);

        

    //     for (auto kv : seg[2 * index + 1])
    //     {
    //         seg[index][kv.first] += kv.second;
    //     }

    //     for (auto kv : seg[2 * index + 2])
    //     {
    //         seg[index][kv.first] += kv.second;
    //     }

    // }

    // int querySeg(int index, int low, int high, int left, int right, int value)
    // {

    //     //1. outside range
    //     if (high < left || low > right)
    //     { //	cout<<high<<" "<<left<<" "<<low<<" "<<right<<endl;
    //         return 0;
    //     }

    //     //2. tree range lies inside query range
    //     if (left <= low && right >= high)
    //     {
    //         //cout << seg[index][value] << " ";
    //         return seg[index][value];
    //     }

    //     //overlap
    //     int mid = low + (high - low) / 2;

    //     int leftTree = querySeg(2 * index + 1, low, mid, left, right, value);
    //     int rightTree = querySeg(2 * index + 2, mid + 1, high, left, right, value);

    //     //cout <<"op: "<<leftTree + rightTree << endl;

    //     return leftTree + rightTree;
    // }

    int query(int left, int right, int value){
        //ub : >, lb : >=
        //method1
        //cout<<upper_bound(mp[value].begin(), mp[value].end(), right) - mp[value].begin()<<endl;
        //cout<<lower_bound(mp[value].begin(), mp[value].end(), left) - mp[value].begin()<<endl;
        return upper_bound(mp[value].begin(), mp[value].end(), right) - lower_bound(mp[value].begin(), mp[value].end(), left);
        //return querySeg(0, 0, N - 1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
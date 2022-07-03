class RangeFreqQuery
{
public:
    int N;
    unordered_map<int, int> *seg;
    RangeFreqQuery(vector<int> &arr)
    {

        N = arr.size();
        seg = new unordered_map<int, int>[4 * N];

        buildSeg(0, 0, N - 1, arr);
    }

    void buildSeg(int index, int low, int high, vector<int> &arr)
    {

        if (low == high)
        {
            seg[index][arr[low]]++;
            return;
        }

        int mid = low + (high - low) / 2;

        buildSeg(2 * index + 1, low, mid, arr);
        buildSeg(2 * index + 2, mid + 1, high, arr);

        

        for (auto kv : seg[2 * index + 1])
        {
            seg[index][kv.first] += kv.second;
        }

        for (auto kv : seg[2 * index + 2])
        {
            seg[index][kv.first] += kv.second;
        }

    }

    int query(int left, int right, int value)
    {
        //cout << "calling " << endl;
        return querySeg(0, 0, N - 1, left, right, value);
    }

    int querySeg(int index, int low, int high, int left, int right, int value)
    {

        //1. outside range
        if (high < left || low > right)
        { //	cout<<high<<" "<<left<<" "<<low<<" "<<right<<endl;
            return 0;
        }

        //2. tree range lies inside query range
        if (left <= low && right >= high)
        {
            //cout << seg[index][value] << " ";
            return seg[index][value];
        }

        //overlap
        int mid = low + (high - low) / 2;

        int leftTree = querySeg(2 * index + 1, low, mid, left, right, value);
        int rightTree = querySeg(2 * index + 2, mid + 1, high, left, right, value);

        //cout <<"op: "<<leftTree + rightTree << endl;

        return leftTree + rightTree;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
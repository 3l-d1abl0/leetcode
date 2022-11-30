struct Endpoint {
    int val, load;
    bool isStart;
};
 
// custom comparator function which is used by the c++ sort stl
bool comp(const Endpoint& a, const Endpoint& b) {
    if (a.val != b.val)
        return a.val < b.val;
    //prioratize departing time
    return a.isStart == false && b.isStart == true;
}


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int N = trips.size();
        if(N==0)
            return 0;
        
        int count = 0; // count will contain the count of current loads
      int result = 0; // result will contain maximum of all counts
 
      // this data array will contain all the endpoints combined with their load values
      // and flags telling whether they are starting or ending point
    vector<Endpoint> data;
 
    for (int i = 0; i < N; i++) {
        data.emplace_back(Endpoint{ trips[i][1], trips[i][0], true});//from
        data.emplace_back(Endpoint{ trips[i][2], trips[i][0], false});//to
    }
 
    sort(data.begin(), data.end(), comp);
 
    for (int i = 0; i < data.size(); i++) {
        if (data[i].isStart == true) {
            count += data[i].load;
            result = max(result, count);
        }
        else
            count -= data[i].load;
 
        //cout<<"i= "<<i<<endl;
    }
 
    return result<=capacity;
        
        
    }
};
struct Node{
    int val, id;
};

struct CompareVal {
    bool operator()(Node const& n1, Node const& n2){
        //n1 ordered before n2
        return n1.val != n2.val ? n1.val > n2.val : n1.id >n2.id;
    }
};


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int N = intervals.size();
        if(N==1)
            return {-1};
        
        priority_queue<Node, vector<Node>, CompareVal > start;
        priority_queue<Node, vector<Node>, CompareVal > end;
        
        vector<int> ans (N, -1);
        
        for(int i=0; i<N ; i++){
            start.push({intervals[i][0], i});
            end.push({intervals[i][1], i});
        }
        
        while(!start.empty() && !end.empty()){
            if(start.top().val >= end.top().val){
                ans[end.top().id] = start.top().id;
                end.pop();
            }else{
                start.pop();
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    
    struct node{
        int diff, num;
        
        node(int d, int n){
            diff = d;
            num = n;
        }
    };
    
    
    bool static cmp(node a, node b){
        
        if(a.diff < b.diff) return true;
        
        if(a.diff == b.diff)
            if(a.num < b.num)   return true;
        
        
        return false;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        vector<node> vec;
        
        for(int i=0; i<arr.size(); i++){
            
            vec.push_back({abs(arr[i]-x), arr[i]});
            
            //cout<<vec[i].diff<<" "<<vec[i].num<<endl;
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        
        /*for(auto ele: vec){
            cout<<ele.diff<<" "<<ele.num<<endl;
        }*/
        
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].num);
        }
        
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
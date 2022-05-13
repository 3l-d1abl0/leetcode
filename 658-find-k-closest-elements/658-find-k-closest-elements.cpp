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
    
    
    vector<int> justSort(vector<int> &arr, int k, int x){
        
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
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        //1. Simple sorting
        //return justSort(arr, k, x);
        
        //2. 2 Pointer
        int l = 0, r= arr.size()-1;
        
        while(r-l>=k){
            
            if(abs(arr[l]-x) <= abs(arr[r]-x) )
                r--;
            else
                l++;
        }
        
        return vector<int> (arr.begin()+l, arr.begin()+r+1);
        //3. Bianry Search
        
        /*int N=arr.size();
        if(x<arr[0]){
            return vector<int> (arr.begin(), arr.begin()+k);
        }else if(x> arr[N-1]){
            return vector<int> (arr.begin()+(N-k), arr.end());
            
        }else{
            //find x
            
            long long int l = arr[0]-1;
            long long int r = arr[N-1]+1;
            
            
            while(r-l>1){
                
                if()
                
            }
            
        
        }*/
 
        
        return vector<int> {};
    }
};
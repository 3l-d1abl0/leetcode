class Solution {
public:
    multiset<long long>first,second;
    long long fs;
    void add(long long ele){
        if(first.size() == 0&&second.size() == 0) first.insert(ele);
        else if(second.size() == 0) first.insert(ele);
        else{
            if(first.size() != 0){
                auto it = first.end();
                it--;
                if(ele<=(*it)) first.insert(ele);
                else second.insert(ele);
            }
            else first.insert(ele);
        }
        
        while(first.size() > fs){
            auto it = first.end();
            it--;
            long long curr = *it;
            first.erase(it);
            second.insert(curr);
        }
        while(first.size()<fs){
            long long curr = *(second.begin());
            second.erase(second.begin());
            first.insert(curr);
            
        }
    }
    void rem(long long ele){

        if(first.find(ele) != first.end()) first.erase(first.find(ele));
        else second.erase(second.find(ele));
    }
    double getMedian(){
        //Even
        if(first.size() == second.size()){
            double a,b;
            auto it = first.end();
            it--;
            a = (double) *(it);
            b = (double) *(second.begin());
            return (a + b)/2.0;
        }
        else{
            auto it = first.end();
            it--;
            return (double)*(it);
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        fs = (k+1)/2;
        for(int i = 0;i<k;i++){
            if(i==k-1)
                add(nums[i]);
            else first.insert(nums[i]);
        }
        
        vector<double>res;
        res.push_back(getMedian());
        for(int i = k,l = 0;i<nums.size();i++,l++){
            rem(nums[l]);
            add(nums[i]);
            // print();
            res.push_back(getMedian());
            
        }
        return res;
    }
};
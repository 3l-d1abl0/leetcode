class Solution {
public:
    
    static int countBits(int a){
        int count = 0;
        while (a) {
            if (a & 1)
                count += 1;
            a = a >> 1;
        }
        return count;
    }
 
// custom comparator of std::sort
    static bool cmp(int a, int b){
        int count1 = countBits(a);
        int count2 = countBits(b);

        // this takes care of the stability of sorting algorithm too
        if (count1 < count2)
            return true;
        else if(count1==count2){
            return a<b;
        }
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        stable_sort(arr.begin(), arr.end(), cmp);
        
        return arr;
    }
};
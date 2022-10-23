class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
       #define ll long long
        long long res = 0;
        long long inter = 0,odd1=0,odd2=0;
        vector<ll> on,en,et,ot;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]&1){
                odd1 += nums[i];
                on.push_back(nums[i]);
            }   else en.push_back(nums[i]);
                if(target[i]&1){
                    odd2 += target[i];
                    ot.push_back(target[i]);
                }
                else    et.push_back(target[i]);
        }
    
        inter = odd2 - odd1;
        res += abs(inter)/2;
        sort(ot.begin(),ot.end());
        sort(en.begin(),en.end());
        sort(on.begin(),on.end());
        sort(et.begin(),et.end());
        
        ll crr = inter;
        for(int i = 0; i < ot.size();i++){
            if(ot[i] > on[i]){
                if(crr > 0){
                    int remove = min(crr,(ll)ot[i] - on[i]);
                    crr -= remove;
                    on[i] += remove;
                }
                res += (ot[i]-on[i])/2;
                crr -= ot[i]-on[i];
            }else{
                if(crr < 0){
                    int remove = min(abs(crr),on[i]-ot[i]);
                    crr += remove;
                    on[i] -= remove;
                }
                res += (on[i]-ot[i])/2;
                crr += on[i]-ot[i];
            }
        }
        
        inter *= -1;
        crr = inter;
        for(int i = 0; i < et.size();i++){
            if(et[i] > en[i]){
                if(crr > 0){
                    int remove = min(crr,(ll)et[i] - en[i]);
                    crr -= remove;
                    en[i] += remove;
                }
                res += (et[i]-en[i])/2;
                crr -= et[i]-en[i];
            }else{
                if(crr < 0){
                    int remove = min(abs(crr),en[i]-et[i]);
                    crr += remove;
                    en[i] -= remove;
                }
                res += (en[i]-et[i])/2;
                crr += en[i]-et[i];
            }
        }
        return res;
    }
};
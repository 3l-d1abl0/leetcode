class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        map<int, int> mp;
        
        for(int i=0; i<speed.size(); i++){
            mp[position[i]] = speed[i];
        }
        
        int cnt = 0;
        float time;
        for(map<int, int> ::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++){
            //cout<<target-(*it).first<<" / "<<(*it).second<<"= "<<(target-(*it).first)/(*it).second<<endl;
            
            if(cnt==0){
                cnt++;
                time= (float)(target- (*it).first)/(*it).second;
            }else{
                if((float)(target- (*it).first)/(*it).second > time){
                    cnt++;
                    time= (float)(target- (*it).first)/(*it).second;
                }
            }
        }//for
        
        return cnt;
    }
};
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        
        vector<double> ans;
        ans.push_back(celsius+ 273.15);
        ans.push_back((9.0/5.0) * celsius + 32);
        
        return ans;
    }
};
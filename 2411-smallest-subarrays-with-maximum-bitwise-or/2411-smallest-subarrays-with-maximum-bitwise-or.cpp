class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
              vector<int> ans;
int N=nums.size();
vector<int> nearest (32, -1);

for (int i = N-1; i >= 0; i--) { for (int j = 0; j < 32; j++) {

// Nearest index where jth
// bit is set 
    if (nums[i] & (1 << j))
        nearest[j] = i;

}

int last_set_bit_index = i;

// Finding Maximum index of all set bits
for (int j = 0; j < 32; j++)
last_set_bit_index = max(last_set_bit_index, nearest [j]);

ans.push_back(last_set_bit_index - i + 1);

}

// Reversing the answer vector 
        reverse (ans.begin(), ans.end()); return ans;

        
    }
};
class Solution {
public:
    int nextGreaterElement(int num) {
        string nums = to_string(num);

	int N = nums.size();

	int i ; 
	for(i= N-2; i >=0 ; i--){
		if( nums[i]<nums[i+1])
            break;
	}

    //cout<<"idx :: "<<i<<endl;
	if(i==-1)
		return -1;

	int idx1 = i; 

    for(i=N-1; i>idx1; i--){
        if(nums[i]>nums[idx1]){
            swap(nums[idx1], nums[i]);
            break;
        }
    }	

	sort(nums.begin()+idx1+1, nums.end());




	//num = stoi(nums);
    long num_long = stol(nums);
    
        if(num_long > INT_MAX)
            return -1;
        else
            return num_long;

	
    }
};
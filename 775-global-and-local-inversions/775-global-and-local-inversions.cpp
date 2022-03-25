class Solution {
public:
    
    void updateBIT(vector<int> &bit, int idx){
	while(idx < bit.size()){
		bit[idx] +=1;
		idx += idx & (-idx);
	}
}

int query(vector<int> &bit, int idx){

	int sum =0;
	while(idx>0){
		sum += bit[idx];
		idx -= idx & (-idx);
	}

	return sum;
}
    
    bool isIdealPermutation(vector<int>& a) {
        
        	if(a.size() == 0)
		return true;

	int local_inversion =0;
	for(int i=0; i<a.size()-1; i++)
		if(a[i]>a[i+1])
			local_inversion++;


	vector<int> bit(a.size()+1, 0);

	//1st element just update, no need to query
	//using element as index since arrayis in the range 0-N
	updateBIT(bit, a[0]+1);
	int max_range_limit = a[0]+1;

	long int global_inversion = 0;
	for(int i=1; i<a.size(); i++){

		updateBIT(bit, a[i]+1);
		max_range_limit = max(max_range_limit, a[i]+1);

		global_inversion += query(bit, max_range_limit) - query(bit, a[i]+1);
	}

	//cout<<local_inversion<<" * "<<global_inversion<<endl;
	return (local_inversion==global_inversion);
        
        
    }
};
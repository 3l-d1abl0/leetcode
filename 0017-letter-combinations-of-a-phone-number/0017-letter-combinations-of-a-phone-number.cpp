class Solution {
public:
    
    vector<string> letterCombinationBFS(unordered_map<char, string> &map, string digit){

	int n = digit.length();

	vector<string> list;
	queue<string> q;

	q.push("");


	while(!q.empty()){

		string str = q.front();	q.pop();

		if(str.length() == n){
			list.push_back(str);
            continue;
        }

		for(int i=0; i<map[digit[str.length()]].length(); i++){

		 //cout<<str+map[digit[str.length()]][i]<<endl;

			q.push(str+map[digit[str.length()]][i]);
		}

	}

	return list;

}
    
    vector<string> letterCombinations(string digits) {
     
        
        unordered_map<char, string> map =
		{ {'2',"abc"},
		  {'3',"def"},
		  {'4',"ghi"},
		  {'5',"jkl"},
		  {'6',"mno"},
		  {'7',"pqrs"},
		  {'8',"tuv"},
		  {'9',"wxyz"}
		}
	;
        
        
        vector<string> list;
        
        if(digits.length()==0)
            return list;
        
        
        list = letterCombinationBFS(map, digits);
        
        return list;
        
    }
};
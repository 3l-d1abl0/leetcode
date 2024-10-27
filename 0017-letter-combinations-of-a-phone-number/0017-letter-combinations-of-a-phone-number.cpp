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
    
    void backtrack(string combination, string next_digits, string phone_map[], vector<string>& output) {
        if (next_digits.empty()) {
            output.push_back(combination);
        } else {
            std::string letters = phone_map[next_digits[0] - '2'];
            for (char letter : letters) {
                backtrack(combination + letter, next_digits.substr(1), phone_map, output);
            }
        }
    }
    
    
    vector<string> method1(string digits) {
        if (digits.empty()) return {};

        std::string phone_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> output;
        backtrack("", digits, phone_map, output);
        return output;
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        
        //Method1 Recursion
        return method1(digits);
     
        
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
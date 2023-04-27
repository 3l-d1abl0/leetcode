class Solution {
public:
    
    bool findSubstring(string &s,int idx, vector<string> words, int ctr, unordered_map<string, int> mp){

	//cout<<"Starting: "<<idx<<endl;
	int wordLength = words[0].size();

	for(int i = idx; i<s.size(); i+=wordLength){

		//Matched all words
		if(ctr == words.size())
			return true;

		string sub = s.substr(i, wordLength);
		//cout<<"Matching ... "<<sub<<endl;

		if ( mp.find(sub) == mp.end() ){
			return false;
		}else{

			//exists

			//already matched
			if(mp[sub]==0)
				return false;

			//cout<<"matched ... "<<sub<<endl;
			mp[sub]--;
			ctr++;

		}

	}//for


	if(ctr == words.size())
		return true;

    return false;
}
    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        
        	int listLength = words.size();
	int wordLength = words[0].size();

	int totalSubstringlength = listLength*wordLength;

	if(s.size() < totalSubstringlength)
		return {};

	//Generate freq-map for each word
	unordered_map<string, int> mp;
	for(string wd: words){
		mp[wd]++;
	}


    //unordered_set<int> pos;
    vector<int> pos;
	for(int i=0; i<s.size()-(totalSubstringlength)+1; i++){

		//for(string wd: words){
        for(auto p: mp){
            
            string wd = p.first;
            
			if ( wd.compare( s.substr(i, wordLength) ) == 0 ){

				mp[wd]--;
				bool ans = findSubstring(s, i+wordLength, words, 1, mp);
				mp[wd]++;


				if(ans==true){

					//cout<<"Found: "<<i<<endl;
					//pos.insert(i);
                    pos.push_back(i);
				}


			}

		}
	} //for


	return pos;//vector<int> (pos.begin(), pos.end());
        
        
    }
};
class Solution {
public:
    struct compareStudent {
        bool operator()(pair<int,int> const & p1, pair<int,int> const & p2){
             if(p1.first == p2.first) //same scores
                return p1.second > p2.second; //lower id first
            
            //higher score first
            return p1.first < p2.first;
        }
    };

    /*static bool compareStudent(const pair<int, int> p1, const pair<int, int> p2){
        if(p1.first == p2.first) //same scores
            return p1.second < p2.second; //lower id first
        
        //higher score first
        return p1.first > p2.first;
    }*/

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    
    
        //vector<pair<int, int>> pointStudent;
    
        //min heap for topK
        priority_queue<pair<int, int>, vector<pair<int,int>>, compareStudent> pq;
        vector<int> topKStudents;

        //Create a Map Set of Words
        unordered_set<string> posSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negSet(negative_feedback.begin(), negative_feedback.end());

        int numStudents = report.size();
        for(int i = 0; i < numStudents; i++){
            string studentReport = report[i];
            
            //split report to words
            stringstream ss(studentReport);
            string word;
            
            int currentScore = 0;
            while(ss >> word){
                if(posSet.count(word)) currentScore += 3;
                else if(negSet.count(word)) currentScore -= 1;
            }

            pq.push({currentScore, student_id[i]});
            // if(pq.size() > k) pq.pop();
            // pointStudent.push_back({currentScore, student_id[i]});
        }

        // sort(pointStudent.begin(), pointStudent.end(), compareStudent);

        int count = 0;
        for(int i=0; i< k && !pq.empty(); i++){
            topKStudents.push_back(pq.top().second);
            pq.pop();
        }
        
        /*for(auto & scoreStudent : pointStudent){
            topKStudents.push_back(scoreStudent.second);
            count++;
            if(count == ansSize) break;
        }*/
        
        return topKStudents;
    }

};
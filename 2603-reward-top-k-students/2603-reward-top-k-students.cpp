class Solution {
public:
    struct compareStudent {
        bool operator()(pair<int,int> const & p1, pair<int,int> const & p2){
             if(p1.first == p2.first) //same scores
                return p1.second < p2.second; //greater id first
            
            //lower score first
            return p1.first > p2.first;
        }
    };

    //If the candidate is eligible for topK
    bool inTopK(pair<int, int> q, pair<int, int> candidate){

            if(q.first == candidate.first)  //score same , rank less
                return candidate.second < q.second;
            
            return candidate.first > q.first;
    }

    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    
    
        /*
            Instead of having a Max Heap of size N.

            We have a min Heap of size K, to store the top K Scores.
            Since it is a min heap, the top element will have
            the element with least Score, and if scores are equal, the greater id
        */

        //Min heap of Size K
        priority_queue<pair<int, int>, vector<pair<int,int>>, compareStudent> pq;

        //Create a Map Set of Words
        unordered_set<string> posSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negSet(negative_feedback.begin(), negative_feedback.end());

        for(int i = 0; i < report.size(); i++){
            string studentReport = report[i];
            
            //split report to words
            stringstream ss(studentReport);
            string word;
            
            int currentScore = 0;
            while(ss >> word){
                if(posSet.count(word)) currentScore += 3;
                else if(negSet.count(word)) currentScore -= 1;
            }

            
            if(pq.size()< k)
                pq.push({currentScore, student_id[i]});
            else{

                if(inTopK(pq.top(), {currentScore, student_id[i]} )){//if the current score eligible for topK score   
                    pq.pop();
                    pq.push({currentScore, student_id[i]});
                }

            }

        }//for


        int count = 0;
        vector<int> topKStudents((int)pq.size());
        while(!pq.empty()){
            topKStudents[(int)pq.size() -1] = pq.top().second;
            pq.pop();
        }

        return topKStudents;
    }

};
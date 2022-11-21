class Solution {
public:
    
        struct compare{
        bool operator()(const vector<int>&i,const vector<int>&j){
            return i[1] < j[1];
        }
    };
 
    
    
    int scheduleCourse(vector<vector<int>>& courses) {
        // sort the given courses on the basis of last day to finish
        sort(courses.begin(),courses.end(),compare());
 
        int total_duration = 0;
 
        // to store the courses duration
        // courses that are taken
        priority_queue<int> q;
 
        for(int i=0;i<courses.size();i++)
        {
            int current_duration = courses[i][0];
            int finish_time = courses[i][1];
 
            // increment total duration
 
            total_duration = total_duration + current_duration;
 
            q.push(current_duration);
 
            if(total_duration>finish_time){
                // we want to skip this course 
                // or try to skip that course(which is already taken) which has maximum duration
 
                total_duration-=q.top();
                q.pop();
            }
        }
 
        // size of the priority queue denotes the courses taken
 
        return q.size();
    }
};
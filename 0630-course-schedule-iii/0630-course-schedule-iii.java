class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a,b)-> a[1]==b[1] ? a[0]-b[0] : a[1]-b[1]);
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);
        int time = 0;
        
        for(int[] course : courses) {
            //Check if we consider current course : if duration <= lastday
            if(course[0] <= course[1]) {
                //current course can be completed with the lastday given
                if(course[0]+time <= course[1]) {
                    pq.offer(course[0]);
                    time+=course[0];
                }
                else {
                    //Check if we can swap
                    if(pq.peek() > course[0]) {
                        time-=pq.poll();
                        time+=course[0];
                        pq.offer(course[0]);
                    }
                }
            }
        }
        return pq.size();
    }
}
class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        N = len(tasks)
        available_tasks = [(task[0], task[1], i) for i, task in enumerate(tasks)]
        
        available_tasks.sort(key=lambda x: (x[0], x[1]))
        
        waiting = []
        ans = []
        current_time = 1
        i = 0
        
        while i < N or waiting:
            # Fetch available tasks and place them in the waiting queue
            while i < N and available_tasks[i][0] <= current_time:
                heapq.heappush(waiting, (available_tasks[i][1], available_tasks[i][2], available_tasks[i][0]))
                i += 1
            
            # Process task from waiting queue and update time
            if waiting:
                process_time, index, _ = heapq.heappop(waiting)
                ans.append(index)
                current_time += process_time
            else:
                current_time = available_tasks[i][0]
        
        return ans
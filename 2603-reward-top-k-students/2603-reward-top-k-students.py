import heapq
from typing import List

class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        # Min-heap of size K
        # Use (score, -id) to prioritize smaller scores and larger IDs
        pq = []

        # Create sets of positive and negative feedback words
        posSet = set(positive_feedback)
        negSet = set(negative_feedback)

        for i in range(len(report)):
            studentReport = report[i]

            # Split report into words
            words = studentReport.split()

            # Calculate the score for the current student
            currentScore = 0
            for word in words:
                if word in posSet:
                    currentScore += 3
                elif word in negSet:
                    currentScore -= 1

            # Push the current student into the heap
            if len(pq) < k:
                heapq.heappush(pq, (currentScore, -student_id[i]))  # Use -id to prioritize larger IDs
            else:
                # If the current student is better than the worst in the heap, replace it
                if currentScore > pq[0][0] or (currentScore == pq[0][0] and -student_id[i] > pq[0][1]):
                    heapq.heappop(pq)
                    heapq.heappush(pq, (currentScore, -student_id[i]))

        # Extract the top K students in order
        topKStudents = []
        while pq:
            score, neg_id = heapq.heappop(pq)
            topKStudents.append(-neg_id)  # Convert back to the original ID

        # Reverse to get the correct order (since it's a min-heap)
        topKStudents.reverse()

        return topKStudents
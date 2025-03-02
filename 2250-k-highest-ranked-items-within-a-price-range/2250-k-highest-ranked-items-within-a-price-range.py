import heapq
from collections import deque

class Solution:
    def highestRankedKItems(self, grid, pricing, start, k):
        R = len(grid)
        C = len(grid[0])
        
        # Initialize visited matrix with False
        visited = [[False for _ in range(C)] for _ in range(R)]
        
        # Priority queue to store (distance, price, row, col)
        pq = []
        
        # Directions for moving to neighboring cells
        dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        
        distance = 0
        q = deque()
        q.append((start[0], start[1]))
        
        while q:
            size = len(q)
            # Loop through all points at a certain distance
            for _ in range(size):
                r, c = q.popleft()
                
                if visited[r][c]:
                    continue
                
                visited[r][c] = True
                if grid[r][c] == 0:
                    continue
                
                # If grid is not an empty cell, consider it
                if grid[r][c] != 1:
                    # Check if the price is within the pricing range
                    if pricing[0] <= grid[r][c] <= pricing[1]:
                        heapq.heappush(pq, (distance, grid[r][c], r, c))
                
                # Loop through neighbors
                for dx, dy in dirs:
                    row, col = r + dx, c + dy
                    if 0 <= row < R and 0 <= col < C:  # Check if within bounds
                        q.append((row, col))
            
            distance += 1
        
        ans = []
        # Extract top k items from the priority queue
        while pq and len(ans) < k:
            dist, price, row, col = heapq.heappop(pq)
            ans.append([row, col])
        
        return ans
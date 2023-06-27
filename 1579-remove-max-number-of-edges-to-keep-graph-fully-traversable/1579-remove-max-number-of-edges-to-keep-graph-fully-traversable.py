class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        edges1 = self.prims(1, edges, n)
        edges2 = self.prims(2, edges, n)
        res, edgeTypes = 0, defaultdict(set)
        if edges1 is None or edges2 is None: return -1 
        for edge in edges1 + edges2:
            edgeTypes[tuple(sorted([edge[1], edge[2]]))] |= {edge[0]}
    
        for key, val in edgeTypes.items():
            if 3 in val: res += 1
            elif len(val) >= 2: res += 2
            else: res += 1
        return len(edges) - res
        
    
    def prims(self, type_, edges, n):
        edges = [edge for edge in edges if edge[0] == type_ or edge[0] == 3]
        mat = defaultdict(list)
        for edge in edges:
            mat[edge[1]] += [(-edge[0], edge[1], edge[2])]
            mat[edge[2]] += [(-edge[0], edge[2], edge[1])]   
        visited, res, q = set([1]), [], mat[1]
        heapq.heapify(q)
        
        while q:
            while q:
                edge = heapq.heappop(q)
                if edge[2] not in visited: break
            else:
                break # no unvisited edge found
            
            res.append((-edge[0], edge[1], edge[2]))
            visited.add(edge[2])
            
            for nei in mat[edge[2]]:
                heapq.heappush(q, nei)
        
        if len(visited) != n: return None  
        return res
        
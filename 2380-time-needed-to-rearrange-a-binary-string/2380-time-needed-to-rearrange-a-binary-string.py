class Solution:
    def secondsToRemoveOccurrences(self, s: str) -> int:

        ctr = 0
        
        while '01' in s:
            
            aux = list(s)
            idx = 0
            
            while idx <= len(aux) - 2:
                
                if s[idx]+s[idx+1] == '01':
                    aux[idx] = s[idx+1]; aux[idx+1] = s[idx]
                    idx += 2
                else:
                    idx += 1
            ctr += 1
            
            #recrearte s
            s = ''.join(aux)
            
        return ctr
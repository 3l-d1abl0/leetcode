class Solution:
    def reverseWords(self, s: str) -> str:
        #print(s.split()[::-1])
        return ' '.join([x for x in s.split()][::-1])
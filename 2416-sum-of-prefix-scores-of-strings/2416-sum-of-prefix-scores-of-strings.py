class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        mapp = dict()
        for w in words:
            n = len(w)
            for i in range(1, n + 1):
                s = w[0:i]
                mapp[s] = mapp.get(s, 0) + 1
        #print(mapp)
        ans = []
        for w in words:
            sc = 0
            for i in range(1, len(w) + 1):
                s = w[0:i]
                sc += mapp.get(s)
            ans.append(sc)
        return ans
mod = 10**9 + 7

def digitDP(s, minSum, maxSum):
	n = len(s)

	dp = [[[0]*(maxSum+20) for _ in range(2)] for _ in range(n+1)]

	# Empty prefix with sum=0
	dp[0][1][0] = 1

	for i in range(n):
		for tight in range(2):
			for sm in range(maxSum+1):
				up = int(s[i]) if tight else 9
				for digit in range(up + 1):
					dp[i+1][tight and (digit == up)][sm+digit] += dp[i][tight][sm]
					dp[i+1][tight and (digit == up)][sm+digit] %= mod

	res = 0
	for i in range(minSum, maxSum+1):
		res += (dp[n][1][i] + dp[n][0][i])
		res %= mod

	return res % mod


class Solution:
	def count(self, num1: str, num2: str, minSum: int, maxSum: int) -> int:
		res = digitDP(num2,minSum,maxSum) 
		res -= digitDP(str(int(num1)-1),minSum,maxSum)
		return res % mod


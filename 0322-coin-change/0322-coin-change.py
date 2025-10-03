class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0

        # dp[i] will store the minimum number of coins needed for amount i
        # amount + 1 serves as infinity, since max possible coins is 'amount'
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i:
                    # dp[i] = min(current dp[i], dp[i - coin] + 1)
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        # If dp[amount] is still 'infinity', the amount is unreachable
        return dp[amount] if dp[amount] <= amount else -1
        
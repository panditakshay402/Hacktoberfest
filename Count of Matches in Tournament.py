class Solution:
    def numberOfMatches(self, n: int) -> int:
        matches_played = 0
        
        while n > 1:
            matches_played += n // 2
            n = (n + 1) // 2  # Calculate the number of teams that advance to the next round
            
        return matches_played

# Example usage:
solution = Solution()
print(solution.numberOfMatches(7))  # Output: 6
print(solution.numberOfMatches(14))  # Output: 13

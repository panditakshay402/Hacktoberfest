def longest_common_subsequence(str1, str2):
    m, n = len(str1), len(str2)
    # Create a table to store the length of LCS for subproblems
    lcs = [[0] * (n + 1) for _ in range(m + 1)]

    # Build the LCS table in a bottom-up manner
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i - 1] == str2[j - 1]:
                lcs[i][j] = lcs[i - 1][j - 1] + 1
            else:
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1])

    # The length of LCS is stored in lcs[m][n]
    length = lcs[m][n]

    # Reconstruct the LCS from the table
    lcs_str = [""] * (length + 1)
    i, j = m, n
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            lcs_str[length - 1] = str1[i - 1]
            i -= 1
            j -= 1
            length -= 1
        elif lcs[i - 1][j] > lcs[i][j - 1]:
            i -= 1
        else:
            j -= 1

    return "".join(lcs_str)

# Example:--->

str1 = "ABCBDAB"
str2 = "BDCAB"
result = longest_common_subsequence(str1, str2)
print("Longest Common Subsequence:", result)

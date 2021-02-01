"""
1. Spiral Matrix 
Medium Accuracy: 100.0% Submissions: 231 Points: 4
Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.

Example 1:

Input: 
N = 3, M = 3, K = 4
A[] = {{1, 2, 3}, 
       {4, 5, 6}, 
       {7, 8, 9}}
Output: 
6
Explanation: Spiral traversal of matrix: 
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.
Example 2:

Input: 
N = 2, M = 2, K = 2 
A[] = {{1, 2},
       {3, 4}} 
Output: 
2
Explanation: Spiral traversal of matrix: 
{1, 2, 4, 3}. Second element is 2.
Your Task:  
You don't need to read input or print anything. Complete the function findK() which takes the matrix A[ ][ ], number of rows N, number of columns M, and integer K as input parameters and returns the Kth element in the spiral traversal of the matrix.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ K ≤ N*M ≤ 106

Topic Tags
 Matrix Constructive algo
Related Courses
 30 Days of Code
"""

#User function Template for python3

#You are required to complete this fucntion
#Function should return an integer
class Solution:
    def findK(self, a, n, m, k):
        if (n < 1 or m < 1):
            return -1

        if (k <= m):
            return a[0][k - 1]
        if (k <Ends= (m + n - 1)):
            return a[(k - m)] [m - 1]

        if (k <= (m + n - 1 + m - 1)):
            return a[n - 1][m - 1 - (k - (m + n - 1))]
        if (k <= (m + n - 1 + m - 1 + n - 2)):
            return a[n - 1 - (k-(m + n - 1 + m - 1))][0]

        a.pop(0)
        [j.pop(0) for j in a]
        return self.findK(a, n - 2, m - 2, k - (2 * n + 2 * m - 4))

#{
#Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        matrix = [[0 for i in range(n[1])]for j in range(n[0])]
        c=0
        for i in range(n[0]):
            for j in range(n[1]):
                matrix[i][j] = arr[c]
                c+=1
        obj = Solution()
        print(obj.findK(matrix, n[0], n[1], n[2]))

#} Driver Code
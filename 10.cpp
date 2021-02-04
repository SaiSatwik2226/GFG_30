/*
1. Repeated String Match 
Medium Accuracy: 100.0% Submissions: 414 Points: 4
Given two strings A and B, find the minimum number of times A has to be repeated such that B becomes a substring of the repeated A. If B cannot be a substring of A no matter how many times it is repeated, return -1.

Example 1:

Input: A = "abcd", B = "cdabcdab"
Output: 3
Explanation: After repeating A three times, 
we get "abcdabcdabcd".
Example 2:

Input: A = "aa", B = "a"
Output: 1
Explanation: B is already a substring of A.
Your Task:  
You don't need to read input or print anything. Complete the function repeatedStringMatch() which takes strings A and B as input parameters and returns the minimum number of operations to complete the task. If it is not possible then return -1.

Expected Time Complexity: O(|A| * |B|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |A|, |B| ≤ 103

Company Tags
 Google
Topic Tags
 Strings
*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool issubstring(string str2, string rep1)
{
    int M = str2.length();
    int N = rep1.length();

    // Check for substring from starting
    // from i'th index of main string
    for (int i = 0; i <= N - M; i++)
    {
        int j;

        // For current index i,
        // check for pattern match
        for (j = 0; j < M; j++)
            if (rep1[i + j] != str2[j])
                break;

        if (j == M) // pattern matched
            return true;
    }

    return false; // not a substring
}
class Solution
{

public:
    int repeatedStringMatch(string A, string B)
    {
        // Your code goes here
        /*int la = A.length();
        int lb = B.length();
        
        if(la>lb)
        {
            //cout<<"helloold"<<endl;
            if(A.find(B) != std::string::npos)
                return 1;
            else
                return -1;
        }
        
        if(la==lb)
        {
            if(A==B)
            return 1;
            else
            return -1;
        }
        
        if(la<lb)
        {
            int m = lb/la;
            if(lb%la!=0)
                m+=1;
            string A1;
            for (int i=0; i<m;i++) 
                A1 += A;
            //cout<<A1;
            if(A[0]!=B[0])
                {
                    A1 = A1+A;
                    if(lb%la==0)
                    m+=1;
                    //cout<<A1<<endl<<m;
                }
            if (A1.find(B) != std::string::npos)
                return m;
            else
                return -1;
        }*/

        // To store minimum number of repetations
        int ans = 1;

        // To store repeated string
        string S = A;

        // Untill size of S is less than B
        while (S.size() < B.size())
        {
            S += A;
            ans++;
        }

        // ans times repetation makes required answer
        if (issubstring(B, S))
            return ans;

        // Add one more string of A
        if (issubstring(B, S + A))
            return ans + 1;

        // If no such solution exits
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends
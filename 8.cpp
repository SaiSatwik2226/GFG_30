/*
1. Dam of Candies 
Medium Accuracy: 100.0% Submissions: 108 Points: 4
Geek wants to make a special space for candies on his bookshelf. Currently, it has N books of different heights and unit width. Help him select 2 books such that he can store maximum candies between them by removing all the other books from between the selected books. The task is to find out the area between 2 books that can hold the maximum candies without changing the original position of selected books. 

Example 1:

Input: N = 3, height[] = {1, 3, 4}
Output: 1
Explanation:
1. Area between book of height 1 and book of 
height 3 is 0 as there is no space between 
them.
2. Area between book of height 1 and book of 
height 4 is 1 by removing book of height 3.
3. Area between book of height 3 and book of 
height 4 is 0 as there is no space between them.

Example 2:

Input: N = 6, height[] = {2, 1, 3, 4, 6, 5}
Output: 8
Explanation: We remove the 4 books in the middle 
creating length = 4 for the candy dam. Height 
for dam will be min(2,5) = 2. Area between book 
of height 2 and book of height 5 is 2 x 4 = 8.
Your Task:  
You don't need to read input or print anything. Complete the function maxCandy() which takes the array height[] and size of array N as input parameters and returns the maximum candies geek can store

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105

Topic Tags
 Two-pointer-algorithm
Related Courses
 30 Days of Code

 similar problem::
 https://www.geeksforgeeks.org/maximum-water-that-can-be-stored-between-two-buildings/

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <cstdlib>

bool compareTo(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

class Solution
{

public:
    int maxCandy(int height[], int n)
    {
        /*// Your code goes here
        int max=0;
        int i = 0;
        int j = n-1;
        while (i < j) {
            int min_height = (a[i]<a[j]?a[i]:a[j]);
            int length = abs(i-j)-1;
            cout<<min_height<<"->"<<length<<endl;
            if (length*min_height>max)
                max = length*min_height;
                //(a[i]<a[j]?a[i]:a[j])*(abs(i-j)-1)<(a[i+1]<a[j]?a[i+1]:a[j])*(abs(i+1-j)-1)
            else if ()
                i++;
            else
                j--;
        }
        return max;*/

        // Make pairs with indices
        pair<int, int> pairs[n];
        for (int i = 0; i < n; i++)
            pairs[i] = make_pair(i, height[i]);

        // Sort array based on heights
        sort(pairs, pairs + n, compareTo);

        // To store the min and max index so far
        // from the right
        int minIndSoFar = pairs[n - 1].first;
        int maxIndSoFar = pairs[n - 1].first;
        int maxi = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            // Current books paired with
            // the books greater in height
            // and on the extreme left
            int left = 0;
            if (minIndSoFar < pairs[i].first)
            {
                left = (pairs[i].second * (pairs[i].first - minIndSoFar - 1));
            }

            // Current books paired with
            // the books greater in height
            // and on the extreme right
            int right = 0;
            if (maxIndSoFar > pairs[i].first)
            {
                right = (pairs[i].second * (maxIndSoFar - pairs[i].first - 1));
            }

            // Maximum so far max(right, maxi)
            maxi = max(left, max(right, maxi));
            //cout<<maxi<<endl;

            // Update the maximum and minimum so far
            minIndSoFar = min(minIndSoFar, pairs[i].first);
            maxIndSoFar = max(maxIndSoFar, pairs[i].first);
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int height[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> height[i];
        }

        Solution obj;

        cout << obj.maxCandy(height, n) << "\n";
    }
    return 0;
} // } Driver Code Ends
/*
Given a positive integer N. You have to find Nth natural number after removing all the numbers containing digit 9 .


Example 1:
 

Input:
N = 8
Output:
8
Explanation:
After removing natural numbers which contains
digit 9, first 8 numbers are 1,2,3,4,5,6,7,8
and 8th number is 8.
 

Example 2:
 

Input:
N = 9
Output:
10
Explanation:
After removing natural numbers which contains
digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10
and 9th number is 10.
 

Your Task:
You don't need to read input or print anything. Complete the function findNth() which accepts an integer N as input parameter and return the Nth number after removing all the numbers containing digit 9.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 1012

Topic Tags
Mathematical
 */


#include<bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++

class Solution{
	public:
    // function to change N
    // from base10 to base9
    long long findNth(long long N)
    {
        long long base10num = N;
        long long base9num = 0;
        long long pos = 1;
        while( base10num>0 )
        {
            // taking remainder with 9
            base9num += pos * (base10num%9);
            // dividing number with 9
            base10num /= 9;
            // multiplying position with 10
            pos *= 10;
        }
       
       return base9num; 
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}

  // } Driver Code Ends
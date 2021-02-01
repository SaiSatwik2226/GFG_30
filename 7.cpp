/*
1. Valid Pair Sum 
Medium Accuracy: 100.0% Submissions: 236 Points: 4
Given an array of size N, find the number of distinct pairs {a[i], a[j]} (i != j) in the array with their sum greater than 0.

Example 1:

Input: N = 3, a[] = {3, -2, 1}
Output: 2
Explanation: {3, -2}, {3, 1} are two 
possible pairs.
Example 2:

Input: N = 4, a[] = {-1, -1, -1, 0}
Output: 0
Explanation: There are no possible pairs.
Your Task:  
You don't need to read input or print anything. Complete the function ValidPair() which takes the array a[ ] and size of array N as input parameters and returns the count of such pairs.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105 
-104  ≤ a[i] ≤ 104

Topic Tags
 Arrays Sorting Searching Greedy
Related Courses
 30 Days of Code

*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
    	// Your code goes here 
    	sort(a,a+n);
    	//for(int i = 0;i<n;i++)
    	//cout<<a[i]<<endl;
    	/*int i =0;
    	int count=0;
    	while(a[i]<0){
    	    for(int j = i+1;j<n;j++){
    	        if(a[i]+a[j]>0)
    	            count++;
    	    }
    	    i++;
    	}
    	count+=(n-i)*(n-i-1)/2;
    	return count;*/
    	
    	//O(N*logN)
    	/*long long int ans = 0; 
        for (int i = 0; i < n; ++i) { 
            if (a[i] <= 0) 
                continue; 
  
            long long int j = lower_bound(a, a + n,-a[i] + 1)-a; 
            ans += i - j; 
        } */
    	
    	//O(N*logN)
    	long long int count=0;
    	long long int i=0;
    	long long int j=n-1;
    	while(i<j)
    	{
    	    if(a[i]+a[j]>0)
    	    {
    	        count+=j-i;
    	        j--;
    	    }
    	    else{
    	        i++;
    	    }
    	}
    	return count;
    }   
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends
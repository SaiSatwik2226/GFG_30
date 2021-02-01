// A O(n^2) function to the maximum sum sub- 
// squares of size k x k in a given square 
// matrix of size n x n 
void printMaxSumSub(int mat[][N], int k) 
{ 
    // k must be smaller than or equal to n 
    if (k > N) return; 
  
    // 1: PREPROCESSING 
    // To store sums of all strips of size k x 1 
    int stripSum[N][N]; 
  
    // Go column by column 
    for (int j=0; j<N; j++) 
    { 
        // Calculate sum of first k x 1 rectangle 
        // in this column 
        int sum = 0; 
        for (int i=0; i<k; i++) 
            sum += mat[i][j]; 
        stripSum[0][j] = sum; 
  
        // Calculate sum of remaining rectangles 
        for (int i=1; i<N-k+1; i++) 
        { 
            sum += (mat[i+k-1][j] - mat[i-1][j]); 
            stripSum[i][j] = sum; 
        } 
    } 
  
    // max_sum stores maximum sum and its 
    // position in matrix 
    int max_sum = INT_MIN, *pos = NULL; 
  
    // 2: CALCULATE SUM of Sub-Squares using stripSum[][] 
    for (int i=0; i<N-k+1; i++) 
    { 
        // Calculate and print sum of first subsquare 
        // in this row 
        int sum = 0; 
        for (int j = 0; j<k; j++) 
            sum += stripSum[i][j]; 
  
        // Update max_sum and position of result 
        if (sum > max_sum) 
        { 
            max_sum = sum; 
            pos = &(mat[i][0]); 
        } 
  
        // Calculate sum of remaining squares in 
        // current row by removing the leftmost 
        // strip of previous sub-square and adding 
        // a new strip 
        for (int j=1; j<N-k+1; j++) 
        { 
            sum += (stripSum[i][j+k-1] - stripSum[i][j-1]); 
  
            // Update max_sum and position of result 
            if (sum > max_sum) 
            { 
                max_sum = sum; 
                pos = &(mat[i][j]); 
            } 
        } 
    } 
  
    // Print the result matrix 
    for (int i=0; i<k; i++) 
    { 
        for (int j=0; j<k; j++) 
            cout << *(pos + i*N + j) << " "; 
        cout << endl; 
    } 
}

        /*int sum[n-k+1][n];
        int i=0, j=0;
        for (j=0; j<n;j++){
            for (i=0; i<k; i++)
            {
                sum[0][j] += mat[i][j];
            }
        }
        for (j=0; j<n; j++)
        {
            for (i=1; i<=n-k; i++)
            {
                sum[i][j] = sum[i-1][j] - mat[i-1][j] + mat[i+k-1][j];
            }
        }
        int currSUM = 0;

        int max = 0;
        for (i=0; i<n-k+1; i++)
        {
            currSUM = 0;
            for (j=0; j<k; j++)
            {
                currSUM += sum[i][j];
            }
            max = std::max(max,currSUM);

            for (j=1; j<n-k+1; j++)
            {
                currSUM = currSUM - sum[i][j-1] + sum[i][j+k-1];
                max = std::max(max,currSUM);
            }
        }
        return max;
        
        /*{// Your code goes here
        /*int max=0;
        int sum = 0;
        for(int i = 0; i<n-k+1;i++){
            for(int j = 0;j<n-k+1;j++){
                
                for(int a = i;a<i+k;a++){
                    for(int b = j;b<j+k;b++){
                        sum+=mat[a][b];
                    }
                }
                
                if(max<sum)
                    max = sum;
                sum=0;
            }
        }
        return max;
        
        int a1[k][n];
        int a[k*k];
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n-k+1;j++)
            {
                int sum = 0;
                for(int k = j;k<j+k;k++)
                {
                    sum+=mat[i][k];
                }
                a1[i][j] = sum;
            }
        }
        for(int i = 0;i<n-k+1;i++)
        {
            for(int j = 0;j<k;j++)
            {
                int sum = 0;
                for(int k = i;k<i+k;k++)
                {
                    sum+=a1[k][j];
                }
                a[(k-i-1)*3+j] = sum;
            }
        }
        //sort(a,a+k*k, greater<int>());
        return a[0];
    }*/
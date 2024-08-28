***DSA Templates*** <a id="SECTION-ID-TOP"></a>

1. [Boyer-Moore Majority Voting Algorithm](#SECTION-ID-1)
2. [Largest Sum Contiguous Subarray (Kadane’s Algorithm)](#SECTION-ID-2)
3. [SIEVE OF ERATOSTHENES ALGORITHM](#SECTION-ID-3)
4. [Binary Search-1D](#SECTION-ID-4)
5. [Binary Search-2D](#SECTION-ID-5)
6. [Binary Search(Contidions bases)](#SECTION-ID-6)
7. [Linked list-1 (Reverse a LinkedList [Iterative])](#SECTION-ID-7)
8. [Fast and Slow pointer (Linked List Cycle)](#SECTION-ID-8)
9. [Sliding Window](#SECTION-ID-9)
10. [Prefix Sum](#SECTION-ID-10)
11. [Two Pointer](#SECTION-ID-11)
12. [Monotonic Stack](#SECTION-ID-18)
13. [Interval](#SECTION-ID-12)
14. [Knapsack problem](#SECTION-ID-13)
15. [Unbounded Knapsack](#SECTION-ID-14)
16. [LCS](#SECTION-ID-15)
17. [LPS](#SECTION-ID-16)
18. [DP on Stock](#SECTION-ID-17)
19. [Subset Sum](#SECTION-ID-19)
20. [Longest Increasing Subsequence (LIS)](#SECTION-ID-20)
21. [DP on square](#SECTION-ID-21)
22. [Backtracking](#SECTION-ID-22)
23. [Depth-First Search (DFS) && Breadth-First Search (BFS)](#SECTION-ID-23)
24. [Topo Sort](#SECTION-ID-24)
25. Shortest path
26. Disjoint Set
27. Top ‘K’ Elements
28. Tries
29. Powerset
30. DP on Tree + Re-rooting


<!-- <details>
  <summary>Template list</summary>

    1. Boyer-Moore Majority Voting Algorithm
    2. Largest Sum Contiguous Subarray (Kadane’s Algorithm)
    3. SIEVE OF ERATOSTHENES ALGORITHM
    4. Binary Search-1D
    5. Binary Search-2D
    6. Binary Search(Contidions bases)
    7. Linked list-1 (Reverse a LinkedList [Iterative])
    8. Fast and Slow pointer (Linked List Cycle)
    9. 
</details> -->
 
***Code snippets***

* Boyer-Moore Majority Voting Algorithm <a id="SECTION-ID-1"></a> [Problem](https://leetcode.com/problems/majority-element/solutions/5564527/simple-solutions/)
  ```
  int majorityElement(vector<int>& nums) {
        int majorValue = 0;
        int majorValueCounter = 0;

        for(int i=0;i<nums.size(); i++){
                
                if(majorValueCounter == 0){
                    majorValue = nums[i];
                }
                
                if(nums[i] == majorValue) majorValueCounter++;
                else{
                    majorValueCounter--;
                }
        }

        return majorValue;
    }
  ```
  [Top](#SECTION-ID-TOP)


* Largest Sum Contiguous Subarray (Kadane’s Algorithm)<a id="SECTION-ID-2"></a> [Problem](https://leetcode.com/problems/maximum-subarray/solutions/5564535/simple-solution/)
  
  ```
    int maxSubArray(vector<int>& nums) {
        long long curr_sum =0;
        long long maximum_sum = INT_MIN;

        for(int i=0;i<nums.size(); i++){
            curr_sum += nums[i];

            if(maximum_sum < curr_sum ){
                maximum_sum = curr_sum;
            }

            if( curr_sum < 0){
                curr_sum = 0;
            }
        }

        return maximum_sum;
    }
  ```
  [Top](#SECTION-ID-TOP)


* SIEVE OF ERATOSTHENES ALGORITHM <a id="SECTION-ID-3"></a> [Problem](https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/solutions/5564545/sieve-of-eratosthenes/)

  ```
  void SieveOfEratosthenes(int n)
  {

      bool prime[n + 1];
      memset(prime, true, sizeof(prime));
  
      for (int p = 2; p * p <= n; p++) {
          if (prime[p] == true) {
              for (int i = p * p; i <= n; i += p)
                  prime[i] = false;
          }
      }
  
      // Print all prime numbers
      for (int p = 2; p <= n; p++)
          if (prime[p])
              cout << p << " ";
  }
  ``` 
  [Top](#SECTION-ID-TOP)


* Binary Search-1D <a id="SECTION-ID-4"></a> [Problem](https://leetcode.com/problems/binary-search/solutions/423162/binary-search-101/)
  
  ```
  int helper(int low, int high, int target, vector<int>& nums){

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }

    return -1;
  }
  ```
  [Top](#SECTION-ID-TOP)


* Binary Search-2D <a id="SECTION-ID-5"></a> [Problem](https://leetcode.com/problems/search-a-2d-matrix/solutions/5564557/easy-solution/)
  
  ```
  bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size();
    int m = matrix[0].size();

    int l=0, r = n * m - 1;
    int mid = (l+r)/2;

    while(l<=r){
        mid = (l+r)/2;
        int row = mid / m;
        int col = mid % m;
        if(matrix[row][col] == target) return true;

        if(matrix[row][col] < target) l = mid + 1;
        else r = mid - 1;
    }

    return false;
  }
  ```
  [Top](#SECTION-ID-TOP)


* Binary Search(Contidions bases) <a id="SECTION-ID-6"></a> 
    * Minimum Number of Days to Make m Bouquets [Problem](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/solutions/686529/java-binary-search-with-detailed-explanation-runtime-o-nlog-maxdays-100/)

  ```
  class Solution {
    public:
    long long numberOfBouquets(vector<int>& bloomDay, int day, int k){
        long long bouquets = 0;
        long long counter = 0;
        if(k == 0 || day == 0) return 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(day >= bloomDay[i]){
                counter++;
            }else{
                bouquets += counter/k;
                counter = 0;
            }
        }

        bouquets += counter/k;

        return bouquets;
    }

    pair<int, int> getMinAndMax(vector<int>& bloomDay){
        int minVal = bloomDay[0];
        int maxVal = bloomDay[0];
        for(int i=0; i<bloomDay.size(); i++){
            minVal = min(minVal, bloomDay[i]);
            maxVal = max(maxVal, bloomDay[i]);
        }
        return {minVal, maxVal};
    }

    int helperBS(int low, int high, int m, int k, vector<int>& bloomDay){
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            long long bouquets = numberOfBouquets( bloomDay, mid, k);
            if(bouquets >= m){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k *1LL;
        if(val > bloomDay.size()) return -1;
        std::pair<int, int> values = getMinAndMax(bloomDay);
        return helperBS(values.first, values.second, m, k, bloomDay);
    }
  };
  ```
  [Top](#SECTION-ID-TOP)


*  Linked list-1 (Reverse a LinkedList [Iterative]) <a id="SECTION-ID-7"></a> [Problem](https://leetcode.com/problems/reverse-linked-list/solutions/58125/in-place-iterative-and-recursive-java-solution/)
  
    ```
    ListNode* reverseList(ListNode* head) {
      if(head == NULL || head ->next == NULL) return head;
      ListNode* curr = head, *Next = NULL, *prev = NULL;
      while(curr != NULL){
          Next = curr->next;
          curr->next = prev;

          prev = curr;
          curr = Next;
      }

      return prev;

    }
    ```
    [Top](#SECTION-ID-TOP)


* Fast and Slow pointer (Linked List Cycle) <a id="SECTION-ID-8"></a> [Problem](https://leetcode.com/problems/linked-list-cycle/solutions/44489/o-1-space-solution/)
  
  ```
  bool hasCycle(ListNode *head) {

      ListNode* fast = head;
      ListNode* slow = head;

      while(fast != NULL){
          fast = fast->next;

          if(fast != NULL){
              fast = fast->next;
              slow = slow->next;
          }

          if(fast == slow) return true;
      }

      return false;
  }
  ```
  [Top](#SECTION-ID-TOP)

* Sliding Window  <a id="SECTION-ID-9"></a> 
  - Longest Repeating Character Replacement [Problem](https://leetcode.com/problems/longest-repeating-character-replacement/)
  
  ```
  class Solution {
    public:
      int characterReplacement(string s, int k) {
          int n = s.size();
          unordered_map<char,int> mp;
          int maxLength = 0;
          int l=0;
          int maxFreq = 0;

          for(int i=0; i<n; i++){
              mp[s[i]] += 1;
              maxFreq = max(maxFreq, mp[s[i]]);

              if((i-l+1 - maxFreq) <= k) maxLength = max(maxLength, i-l+1);
              if((i-l+1 - maxFreq) > k){
                  mp[s[l]] -= 1;
                  l++;

                  // maxFreq = 0;
                  // for(auto &[k,v]: mp){
                  //     maxFreq = max(maxFreq, v);
                  // }
                  if(mp[s[l]] == 0) mp.erase(s[l]);
              }
              if((i-l+1 - maxFreq) <= k) maxLength = max(maxLength, i-l+1);

          }

          return maxLength;
      }
  };
  ```
    [Top](#SECTION-ID-TOP)

* Prefix Sum <a id="SECTION-ID-10"></a> [Problem](https://leetcode.com/problems/subarray-sum-equals-k/)
  - Subarray Sum Equals K
  
  ```
  class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
                std::map<long long, int> m;
                long long sum = 0;
                int ans = 0;

                for(int i=0;i<nums.size(); i++){
                    sum += nums[i];
                    
                    if(sum == k) ans++;

                    if(m.find(sum - k) != m.end()){
                        ans+= m[sum- k];
                    }
                    m[sum]++;
                }
                return ans;

        }
  };
  ```
  [Top](#SECTION-ID-TOP)

* Two Pointer <a id="SECTION-ID-11"></a>
    - Three Sum [Problem](https://leetcode.com/problems/3sum/)
  
  ```
  vector<vector<int>> optimalSolution(vector<int>& nums){

      std::sort(nums.begin(), nums.end());
      std::set<vector<int>> res;
      for(int i=0; i< nums.size(); i++){
          if( i > 0 && nums[i] == nums[i-1]) continue;

          int j = i+ 1;
          int k = nums.size() - 1;

          while(j < k){
              long long  sum = nums[i] + nums[j] + nums[k];
              if(sum == 0){
                  res.insert({nums[i] , nums[j] , nums[k]});
                  j++;
                  k--;
              }

              else if(sum > 0) k--;
              else if(sum < 0) j++;
          }
      }

      vector<vector<int>> finalResult;
      for(auto v: res){
          finalResult.push_back(v);
      }
      return finalResult; 
  }

  vector<vector<int>> threeSum(vector<int>& nums) {
      // return betterSolution(nums);
      return optimalSolution(nums);
  }
  ```
    [Top](#SECTION-ID-TOP)

* Monotonic Stack  <a id="SECTION-ID-18"></a> [Problem](https://leetcode.com/problems/largest-rectangle-in-histogram/)
  - Largest Rectangle in Histogram

  ```
  class Solution {
  public:
    int maxHitogram(vector<int> &row){
            int n = row.size();
            std::stack<int> st;
            int leftSmallest[n];
            int rightSmallest[n];

            //find left smallest
            for(int i=0; i<n;i++ ){
                while(!st.empty() && row[st.top()] >= row[i] ){
                    st.pop();
                }

                if(st.empty()) leftSmallest[i] = 0;
                else leftSmallest[i] = st.top() +1;
                st.push(i);
            }


            while(!st.empty()) st.pop();

            //find right smallest
            for(int i=n-1; i>=0;i-- ){
                while(!st.empty() && row[st.top()] >= row[i]){
                    st.pop();
                }

                if(st.empty()) rightSmallest[i] = n-1;
                else rightSmallest[i] = st.top() -1;
                st.push(i);
            }

            int maxArea = 0;
            for(int i=0; i<n; i++){
                maxArea = max(maxArea, (row[i] * (rightSmallest[i] - leftSmallest[i] + 1)));
            }
            return maxArea;
        }
        
    int largestRectangleArea(vector<int>& heights) {
        return maxHitogram(heights);
    }
  } ;
  ```

* Interval <a id="SECTION-ID-12"></a>
    - Insert [Problem](https://leetcode.com/problems/insert-interval/)
  
  ```
  class Solution {
    public:
      vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          vector<vector<int>> res;
          int n = intervals.size();

          int i = 0;
          //Non overlapping
          while(i < n && intervals[i][1] < newInterval[0]){
              res.push_back(intervals[i]);
              i++;
          }

          //overlapping
          while(i < n && intervals[i][0] <= newInterval[1]){
              newInterval[0] = min(newInterval[0], intervals[i][0]);
              newInterval[1] = max(newInterval[1], intervals[i][1]);
              i++;
          }
          res.push_back(newInterval);

          while(i < n){
              res.push_back(intervals[i]);
              i++;
          }
          return res;
      }
  };
  ```
  [Top](#SECTION-ID-TOP)

* Knapsack problem <a id="SECTION-ID-13"></a>
  - Target Sum [Problem](https://leetcode.com/problems/target-sum/description/)

  ```
  class Solution {
    public:
    int helperTopDown(int i, int target, int currSum, vector<int>& nums, vector<unordered_map<int, int>> &dp){

        if(i==0){
            if(target == currSum && nums[0] == 0) return 2;
            else if(target == currSum+nums[0] || target == currSum-nums[0]){
                return 1;
            }else return 0;
        }

        if(dp[i].find(currSum) != dp[i].end()) return dp[i][currSum];

        int pick1 = helperTopDown(i-1, target, currSum + nums[i] , nums, dp);
        int pick2 = helperTopDown(i-1, target, currSum + (-nums[i]), nums, dp);

        return dp[i][currSum] = (pick1 + pick2);

    }

    int helperTopDownCountWays(int i, vector<int>& nums, int sum, vector<vector<int>> &dp){
        if(i == 0){
            if(sum == 0 && nums[0] == 0) return 2;
            if(sum == 0 || sum == nums[0]) return 1;
            else return 0;
        }

        if(dp[i][sum] != -1) return dp[i][sum];

        int notTake = helperTopDownCountWays(i-1, nums, sum, dp);
        int take = 0;
        if(sum >= nums[i])
            take = helperTopDownCountWays(i-1, nums, sum-nums[i], dp);

        return dp[i][sum] = (take + notTake);
    }

    int helperBottomUpCountWays(int n, vector<int>& nums, int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        //Base case
        for(int i=0; i<n ; i++){
            dp[i][0] = 1;
            if(nums[i] <= sum)
                dp[i][nums[i]] = 1;
        }

        if(nums[0] == 0) dp[0][0] = 2;

        for(int i=1; i<n; i++){
            for(int s=0; s<=sum; s++){

                int notTake = dp[i-1][s];
                int take = 0;
                if(s >= nums[i])
                    take = dp[i-1][s-nums[i]];

                dp[i][s] = (take + notTake);
            }
        }

        return dp[n-1][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        /*
            s1 - s2 = target --- (i)
            s1 + s2 = totalSum --(ii)

            s1 = totalSum - s2
            so, to plugin to (i) formula
            totalSum - s2 - s2 = target
            totalSum - 2s2 = target
            totalSum - target = 2s2
            s2 = (totalSum - target)/2
         */


        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += nums[i];

        if((totalSum - target)  >= 0 && (totalSum - target) % 2 == 0){
            int s2 = (totalSum - target)/2;
            return helperBottomUpCountWays(n, nums, s2);


            vector<vector<int>> dp(n+1, vector<int>(s2+1, -1));
            return helperTopDownCountWays(n-1, nums, s2, dp);
        }
        else return 0;



        vector<unordered_map<int, int>> dp(n+1, unordered_map<int, int>());
        return helperTopDown(n-1, target, 0, nums, dp);
    }
  };
  ```
  [Top](#SECTION-ID-TOP)

* Unbounded Knapsack <a id="SECTION-ID-14"></a>
    - Knapsack with Duplicate Items [Problem](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items)
 
  ```
  class Solution{
  public:
      int helperTopDown(int i, int cw, int val[], int wt[], vector<vector<int>> &dp){
          if(cw == 0) return 0;
          
          if(i==0){
              return val[0] * (int)(cw / wt[0]);
          }
          
          if(dp[i][cw] != -1) return dp[i][cw];
          
          int notPickItem = 0 + helperTopDown(i-1, cw, val, wt, dp);
          int pickItem = 0;
          if(wt[i] <= cw)
              pickItem = val[i] + helperTopDown(i, cw-wt[i], val, wt, dp);
          
          return dp[i][cw] = max(notPickItem, pickItem);
      }

      int helperBottomUp(int n, int cw, int val[], int wt[]){
          vector<vector<int>> dp(n+1, vector<int>(cw+1, 0));

          for(int i=1; i<=cw; i++) dp[0][i] = val[0] * (int)(i / wt[0]);
          dp[0][0] = 0;
          
          for(int i=1; i<n; i++){
              for(int c = 0; c<= cw; c++){

                  int notPickItem = 0 + dp[i-1][c];
                  int pickItem = 0;
                  if(wt[i] <= c)
                      pickItem = val[i] + dp[i][c-wt[i]];
                  
                  dp[i][c] = max(notPickItem, pickItem);
              }
          }
          return dp[n-1][cw];
      }
    
      int helperBottomUpSpaceOptimization(int n, int cw, int val[], int wt[]){
          vector<int> prev(cw+1, 0);

          for(int i=1; i<=cw; i++) prev[i] = val[0] * (int)(i / wt[0]);
          prev[0] = 0;
          
          for(int i=1; i<n; i++){
              vector<int> curr(cw+1, 0);
              for(int c = 0; c<= cw; c++){

                  int notPickItem = 0 + prev[c];
                  int pickItem = 0;
                  if(wt[i] <= c)
                      pickItem = val[i] + curr[c-wt[i]];
                  
                  curr[c] = max(notPickItem, pickItem);
              }
              prev = curr;
          }
          return prev[cw];
      }
    
      int knapSack(int N, int W, int val[], int wt[])
      {
          return helperBottomUpSpaceOptimization(N, W, val, wt);

          return helperBottomUp(N, W, val, wt);

          vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
          return helperTopDown(N-1, W, val, wt, dp);
      }
  };

  ```
  [Top](#SECTION-ID-TOP)

* LCS <a id="SECTION-ID-15"></a> [Problem](https://leetcode.com/problems/longest-common-subsequence/)

  ```
    class Solution {
    public:
      int helperTopDown(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
          //Basecase
          if(i < 0  || j < 0) return 0;

          if(dp[i][j] != -1) return dp[i][j];

          //Eplore
          if(text1[i] == text2[j])
              return  dp[i][j] = 1 + helperTopDown(i-1, j-1, text1, text2, dp);
          else{
              int v2 = 0 + helperTopDown(i-1, j, text1, text2, dp);
              int v3 = 0 + helperTopDown(i, j-1, text1, text2, dp);
              return dp[i][j] = max(v2,  v3);
          }

          //Return
          return 0;
      }

      int helperBottomUp(int n, int m, string &text1, string &text2){
          //Shift the index by 1 to right
          vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

          //Basecase
          for(int j=0; j<m; j++) dp[0][j] = 0;
          for(int i=0; i<n; i++) dp[i][0] = 0;

          for(int i=1; i<=n; i++){
              for(int j=1; j<=m; j++){
                  //Eplore
                  if(text1[i-1] == text2[j-1])
                      dp[i][j] = 1 + dp[i-1][j-1];
                  else{
                      int v2 = 0 + dp[i-1][j];
                      int v3 = 0 + dp[i][j-1];
                      dp[i][j] = max(v2,  v3);
                  }
              }
          }
          return dp[n][m];
      }

      int helperBottomUpSpaceOptimization(int n, int m, string &text1, string &text2){
          //Shift the index by 1 to right

          vector<int> prev(m+1, 0);
          // vector<int> curr(m+1, 0);

          //Basecase
          for(int j=0; j<m; j++) prev[j] = 0; //This doesn't require , Since vector is initialize with 0 for all.
          // for(int i=0; i<n; i++) curr[0] = 0;

          for(int i=1; i<=n; i++){
              vector<int> curr(m+1, 0);
              for(int j=1; j<=m; j++){
                  //Eplore
                  if(text1[i-1] == text2[j-1])
                      curr[j] = 1 + prev[j-1];
                  else{
                      int v2 = 0 + prev[j];
                      int v3 = 0 + curr[j-1];
                      curr[j] = max(v2,  v3);
                  }
              }
              prev = curr;
          }
          return prev[m];
      }

      int longestCommonSubsequence(string text1, string text2) {
          int n = text1.size();
          int m = text2.size();
          
          return helperBottomUpSpaceOptimization(n, m, text1, text2);

          return helperBottomUp(n, m, text1, text2);

          vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
          return helperTopDown(n-1, m-1, text1, text2, dp);
      }
  };
  ```
  [Top](#SECTION-ID-TOP)

* LPS <a id="SECTION-ID-16"></a> [Problem](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

  ```
    class Solution {
    public:
      int topDown(int i, int j, string &s, string &t, vector<vector<int>> &dp){
          if(i < 0 || j < 0 ) return 0;

          if(dp[i][j] != -1) return dp[i][j];

          if(s[i] == t[j])
              return 1 + topDown(i-1, j-1, s,t, dp);
          else{
              int l1 = 0 + topDown(i-1, j, s,t, dp);
              int l2 = 0 + topDown(i, j-1, s,t, dp);
              return dp[i][j] = max(l1, l2);
          }
      }


      int helperBottomUp(int n, int m, string &text1, string &text2){
          //Shift the index by 1 to right
          vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

          //Basecase
          for(int j=0; j<m; j++) dp[0][j] = 0;
          for(int i=0; i<n; i++) dp[i][0] = 0;

          for(int i=1; i<=n; i++){
              for(int j=1; j<=m; j++){
                  //Eplore
                  if(text1[i-1] == text2[j-1])
                      dp[i][j] = 1 + dp[i-1][j-1];
                  else{
                      int v2 = 0 + dp[i-1][j];
                      int v3 = 0 + dp[i][j-1];
                      dp[i][j] = max(v2,  v3);
                  }
              }
          }
          return dp[n][m];
      }

      int helperBottomUpSpaceOptimization(int n, int m, string &text1, string &text2){
          //Shift the index by 1 to right

          vector<int> prev(m+1, 0);
          // vector<int> curr(m+1, 0);

          //Basecase
          for(int j=0; j<m; j++) prev[j] = 0; //This doesn't require , Since vector is initialize with 0 for all.
          // for(int i=0; i<n; i++) curr[0] = 0;

          for(int i=1; i<=n; i++){
              vector<int> curr(m+1, 0);
              for(int j=1; j<=m; j++){
                  //Eplore
                  if(text1[i-1] == text2[j-1])
                      curr[j] = 1 + prev[j-1];
                  else{
                      int v2 = 0 + prev[j];
                      int v3 = 0 + curr[j-1];
                      curr[j] = max(v2,  v3);
                  }
              }
              prev = curr;
          }
          return prev[m];
      }

      int longestPalindromeSubseq(string s) {
          int n = s.size();
          string t(s.rbegin(), s.rend());

          return helperBottomUpSpaceOptimization(n, n, s, t);

          vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
          return topDown(n-1, n-1, s,t, dp);
      }
    };
  ```

* DP on Stock <a id="SECTION-ID-17"></a> [Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)
  - Best Time to Buy and Sell Stock II
  
  ```
  class Solution {
    public:

    int helperTopDown(int i, int buy, int n,  vector<int>& prices, vector<vector<int>> &dp){
        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        //Eplore
        if(buy){
            // choice-1, i can buy current day stock
            //choice -2, I can skip current day stock
            int currDate = -prices[i] + helperTopDown(i+1, 0,n,prices, dp) ;
            int skipCurrDate = helperTopDown(i+1, 1, n, prices, dp);
            return dp[i][buy] = max(currDate, skipCurrDate);
        }else{
            // choice-1, i can sell current day stock
            //choice -2, I can skip current day stock
            int currDate = prices[i] + helperTopDown(i+1, 1, n, prices, dp);
            int skipCurrDate = 0 + helperTopDown(i+1, 0, n, prices, dp);
            return dp[i][buy] = max(currDate, skipCurrDate);
        }
    }

    int helperBottomUp(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                //Eplore
                if(buy){
                    // choice-1, i can buy current day stock
                    //choice -2, I can skip current day stock
                    int currDate = -prices[i] + dp[i+1][0];
                    int skipCurrDate = dp[i+1][1];
                    dp[i][buy] = max(currDate, skipCurrDate);
                }else{
                    // choice-1, i can sell current day stock
                    //choice -2, I can skip current day stock
                    int currDate = prices[i] + dp[i+1][1];
                    int skipCurrDate = 0 + dp[i+1][0];
                    dp[i][buy] = max(currDate, skipCurrDate);
                }
            }
        }

        return dp[0][1];

    }

    int helperBottomUpSpaceOptimization(vector<int>& prices){
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0);

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                //Eplore
                if(buy){
                    // choice-1, i can buy current day stock
                    //choice -2, I can skip current day stock
                    int currDate = -prices[i] + prev[0];
                    int skipCurrDate = prev[1];
                    curr[buy] = max(currDate, skipCurrDate);
                }else{
                    // choice-1, i can sell current day stock
                    //choice -2, I can skip current day stock
                    int currDate = prices[i] + prev[1];
                    int skipCurrDate = 0 + prev[0];
                    curr[buy] = max(currDate, skipCurrDate);
                }
            }
            prev = curr;
        }

        return prev[1];

    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helperBottomUpSpaceOptimization(prices);
        return helperBottomUp(prices);

        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return helperTopDown(0, 1, n, prices, dp);
    }
  };
  ```
  [Top](#SECTION-ID-TOP)

* Subset Sum <a id="SECTION-ID-19"></a> [Problem](https://leetcode.com/problems/partition-equal-subset-sum/)
    - Partition Equal Subset Sum

  ```
  class Solution {
    public:
    //Server loads problem also same
    bool helperTopDown(int i, vector<int> &arr, int sum,  vector<vector<int>> &dp){
        if(sum == 0) return true;
        if( i == 0) return arr[0] == sum;
        
        
        if(dp[i][sum] != -1) return (bool)dp[i][sum];
        
        bool notTake = (bool)helperTopDown(i-1, arr, sum, dp);
        bool take = false;
        if(sum >= arr[i])
            take = (bool)helperTopDown(i-1, arr, sum-arr[i], dp);

        return dp[i][sum] = (int)(take | notTake);
        
    }
    
    bool helperBottomUp(vector<int> &arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i=0; i<n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++){
            for(int target = 0; target <= sum; target++ ){
                        
                bool notTake = dp[i-1][target];
                
                bool take = false;
                if(target >= arr[i])
                    take = dp[i-1][target-arr[i]];
                
                dp[i][target] = (int)(take | notTake);
            }
        }
        
        return dp[n-1][sum];
    }
    
    
    bool helperBottomUpSpaceOptimization(vector<int> &arr, int sum){
        int n = arr.size();
        vector<bool> prev(sum+1, false);
        
        prev[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        
        for(int i=1; i<n; i++){
            vector<bool> curr(sum+1, false);
            curr[0] = true;

            for(int target = 0; target <= sum; target++ ){
                
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[i])
                    take = prev[target-arr[i]];
                
                curr[target] = (take | notTake);
            }
            prev = curr;
        }
        
        return prev[sum];
    }


    bool canPartition(vector<int>& nums) {
        int total=0;
        int n = nums.size();
        for(int i=0;i<n;i++) total += nums[i];
        std::cout<<"total&1: "<<(total&1)<<std::endl;
        if(total&1) return false; //Odd number never be segregated

        int target = total/2;
        return helperBottomUpSpaceOptimization(nums, target);


        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(n - 1, target, nums,dp );;
    }
  };
  ```
  [Top](#SECTION-ID-TOP)

* Longest Increasing Subsequence (LIS) <a id="SECTION-ID-20"></a> [Problem](https://leetcode.com/problems/longest-increasing-subsequence/)
    - Longest Increasing Subsequence (Length)

    ```
    int helperTopDown(int i, int prevIdx, vector<int>& nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];

        //Explore
        int notTake = 0 + helperTopDown(i+1, prevIdx, nums, dp);
        int take = 0;
        if(prevIdx == -1 || nums[i] > nums[prevIdx])
            take = 1 + helperTopDown(i+1, i, nums, dp);
        
        return dp[i][prevIdx+1] = max(take, notTake);
    }

    return helperTopDown(0, -1, nums, dp);

    ```

    - Longest Increasing Subsequence (Using BS)(Length)
  
    ```
    int binarySearch(vector<int>& nums){
        vector<int> st;
        for(int v: nums){
            if(st.empty() || v > st[st.size() - 1])
                st.push_back(v);
            else{
                //Find index of the first elemt of >= v
                auto indx = lower_bound(st.begin(), st.end(), v);
                *indx = v; //Overwrite the value, it doesn't means st store LIS. Just to save the space rewrite on same space.
            }
        }
        return st.size(); //st doesn't contain LIS, it hust use space to store Length
    }

    return binarySearch(nums);
    ```

  - Longest Increasing Subsequence (Using Different Tabulation)(for Print and LDS)
  
  ```
  
    vector<int> LISDifferentWayWithTabulationPrintLDS(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1, 1);
        int maxLen = 0;

        vector<int> hash(n+1, 0);
        int lastIndex = 0;

        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                // if(nums[i] > nums[prev] && dp[prev] + 1 > dp[prev]){ // This is for LIS condition
                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]){ //This is For LDS
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            // maxLen = max(maxLen, dp[i]);
            if(dp[i] > maxLen){
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> res;
        res.push_back(nums[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }

        reverse(res.begin(), res.end());

        return res;
    }


    //Driver code

    int n = nums.size();
    sort(nums.begin(), nums.end()); //After the sort this problem will be same is LIS only divisibility part need to be care
    return LISDifferentWayWithTabulationPrintLDS(nums);
  ```

    [Top](#SECTION-ID-TOP)

* DP on square <a id="SECTION-ID-21"></a> 
  - Largest Rectangle in Histogram [Problem](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)
  
  ```
    class Solution {
    public:
        int maxHitogram(vector<int> &row){
                int n = row.size();
                std::stack<int> st;
                int leftSmallest[n];
                int rightSmallest[n];

                //find left smallest
                for(int i=0; i<n;i++ ){
                    while(!st.empty() && row[st.top()] >= row[i] ){
                        st.pop();
                    }

                    if(st.empty()) leftSmallest[i] = 0;
                    else leftSmallest[i] = st.top() +1;
                    st.push(i);
                }


                while(!st.empty()) st.pop();

                //find right smallest
                for(int i=n-1; i>=0;i-- ){
                    while(!st.empty() && row[st.top()] >= row[i]){
                        st.pop();
                    }

                    if(st.empty()) rightSmallest[i] = n-1;
                    else rightSmallest[i] = st.top() -1;
                    st.push(i);
                }

                int maxArea = 0;
                for(int i=0; i<n; i++){
                    maxArea = max(maxArea, (row[i] * (rightSmallest[i] - leftSmallest[i] + 1)));
                }
                return maxArea;
            }
            
        int largestRectangleArea(vector<int>& heights) {
            return maxHitogram(heights);
        }
    };
  ```
  [Top](#SECTION-ID-TOP)

* Backtracking <a id="SECTION-ID-22"></a> 
  - Combination Sum II  [Problem](https://leetcode.com/problems/combination-sum-ii/description/)

  ```
    class Solution {
        public:
        void solve(int idx, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& res){
            
            if(target == 0){
                res.push_back(ds);
                return;
            }

            for(int i=idx; i<candidates.size(); i++){
                if(i > idx && candidates[i] == candidates[i-1]) continue;
                
                if(candidates[i] > target) break;
                
                ds.push_back(candidates[i]);
                solve(i+1, target - candidates[i], candidates, ds, res);
                ds.pop_back();
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> ds;
            sort(candidates.begin(), candidates.end());
            solve(0, target, candidates, ds, res);
            return res;
        }
    };
  ```
  [Top](#SECTION-ID-TOP)

* Depth-First Search (DFS) && Breadth-First Search (BFS) <a id="SECTION-ID-23"></a> 
  - Is Graph Bipartite?  [Problem](https://leetcode.com/problems/is-graph-bipartite/description/)

  ```
    class Solution {
        public:
        bool checkComponentBFS(int start, vector<vector<int>>& graph, vector<int>& color){

            std::queue<int> q;
            q.push(start);
            color[start]= 0;


            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int a: graph[node]){
                    if(color[a] == -1){
                        color[a] = !color[node]; //opposite color
                        q.push(a);
                    }
                    else if(color[a] == color[node]) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool checkComponentDFS(int start, int col, vector<vector<int>>& graph, vector<int>& color){
            color[start] = col;

            for(int a: graph[start]){
                if(color[a] == -1){
                    if(checkComponentDFS(a, !col, graph, color) == false) return false;
                }
                else if(color[a] == col) return false;
            }

            return true;
        }

        bool isBipartite(vector<vector<int>>& graph) {
            std::vector<int> color(graph.size(), -1);
            for(int i=0;i<graph.size(); i++){
                if(color[i] == -1)
                    // if(!checkComponentBFS(i, graph, color)) return false;
                    if(checkComponentDFS(i, 0, graph, color) == false) return false;
            }
            return true;
        }
    };
  ```
  [Top](#SECTION-ID-TOP)

* Toposort <a id="SECTION-ID-24"></a> 
  - Toposort BFS (KAHN'S Algorithm)?  [Problem](https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort)

  ```
    vector<int> topoSortBFS(int V, vector<int> adj[]){
        
        vector<int> indegree(V, 0);
		for (int i = 0; i < V; i++) {
			for (int it : adj[i]) {
				indegree[it]++;
			}
		}

        std::queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int n: adj[node]){
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        
        return topo;
    }
  ```

  - Toposort DFS?  [Problem](https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort)

  ```
    void dfs(int src, vector<int> adj[], vector<bool> &visited, stack<int> &st){
        visited[src] = true;
        for(int u:adj[src]){
            if(!visited[u]){
                dfs(u, adj, visited, st);
            }
        }
        st.push(src);
    }

    vector<int> topoSortDFS(int V, vector<int> adj[]){
	    vector<int> res;
	    vector<bool> visited(V, false);
	    stack<int> st;

	    for(int i=0;i<V; i++){
	        if(!visited[i]){
	            dfs(i, adj, visited, st);
	        }
	    }
	    
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
  ```
  [Top](#SECTION-ID-TOP)
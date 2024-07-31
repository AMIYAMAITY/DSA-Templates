***DSA Templates*** <a id="SECTION-ID-TOP"></a>

1. [Boyer-Moore Majority Voting Algorithm](#SECTION-ID-1)
2. [Largest Sum Contiguous Subarray (Kadane’s Algorithm)](#SECTION-ID-2)
3. [SIEVE OF ERATOSTHENES ALGORITHM](#SECTION-ID-3)
4. [Binary Search-1D](#SECTION-ID-4)
5. [Binary Search-2D](#SECTION-ID-5)
6. [Binary Search(Contidions bases)](#SECTION-ID-6)
7. [Linked list-1 (Reverse a LinkedList [Iterative])](#SECTION-ID-7)
8. [Fast and Slow pointer (Linked List Cycle)](#SECTION-ID-8)


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

* Boyer-Moore Majority Voting Algorithm <a id="SECTION-ID-1"></a>
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
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/majority-element/solutions/5564527/simple-solutions/)


* Largest Sum Contiguous Subarray (Kadane’s Algorithm)<a id="SECTION-ID-2"></a>
  
  ```
  int maxSubArraySum(int a[], int size)
  {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
      max_ending_here = max_ending_here + a[i];
      if (max_so_far < max_ending_here)
        max_so_far = max_ending_here;

      if (max_ending_here < 0)
        max_ending_here = 0;
    }

    return max_so_far;
  }
  ```
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/maximum-subarray/solutions/5564535/simple-solution/)


* SIEVE OF ERATOSTHENES ALGORITHM <a id="SECTION-ID-3"></a>

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
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/solutions/5564545/sieve-of-eratosthenes/)


* Binary Search-1D <a id="SECTION-ID-4"></a>
  
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
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/binary-search/solutions/423162/binary-search-101/)


* Binary Search-2D <a id="SECTION-ID-5"></a>
  
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
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/search-a-2d-matrix/solutions/5564557/easy-solution/)


* Binary Search(Contidions bases) <a id="SECTION-ID-6"></a>
    * Minimum Number of Days to Make m Bouquets

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
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/solutions/686529/java-binary-search-with-detailed-explanation-runtime-o-nlog-maxdays-100/)


*  Linked list-1 (Reverse a LinkedList [Iterative]) <a id="SECTION-ID-7"></a>
  
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
    [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/reverse-linked-list/solutions/58125/in-place-iterative-and-recursive-java-solution/)


* Fast and Slow pointer (Linked List Cycle) <a id="SECTION-ID-8"></a>
  
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
  [Top](#SECTION-ID-TOP) | [Problem](https://leetcode.com/problems/linked-list-cycle/solutions/44489/o-1-space-solution/)

# 🧠 Subarray / Substring – Sliding Window Cheat Sheet

## 1. Identify Problem

* Subarray / Substring (contiguous)?

  * Yes → Think:

    * Sliding Window
    * Prefix Sum

---

## 2. Core Question (MOST IMPORTANT)

* Can I expand window and fix it by shrinking?

  * YES → Sliding Window ✅
  * NO  → Prefix Sum + HashMap ✅

---

## 3. Monotonic Condition (KEY INSIGHT)

A condition is **monotonic** if:

* Expanding window may break it
* Shrinking window can fix it

👉 Required for Sliding Window

### Examples:

* odd_count ≤ k ✅
* distinct_count ≤ k ✅
* sum ≤ k (only positives) ✅

### Not Monotonic:

* sum == k ❌
* negative numbers affecting sum ❌
* dependency on full history ❌

---

## 4. Sliding Window Types

### 🔹 Fixed Size Window

* Window size = k
* Move both pointers together

```cpp
sum += nums[right];
sum -= nums[left];
left++, right++;
```

👉 Used in:

* Max sum of size k
* First negative in window

---

### 🔹 Variable Size Window

* Expand right, shrink left when needed

```cpp
while (condition breaks) {
    shrink from left;
}
```

👉 Used in:

* Longest substring
* At most K problems

---

## 5. “Exactly K” Trick

If problem says **exactly k**:

```cpp
exactly(k) = atMost(k) - atMost(k-1);
```

👉 Works because "at most k" is monotonic

---

## 6. AtMost Pattern (IMPORTANT)

```cpp
for (right = 0 → n) {
    expand window;

    while (condition > k) {
        shrink window;
    }

    count += (right - left + 1);
}
```

---

## 7. Count vs Length

* Count subarrays:

```cpp
count += (right - left + 1);
```

* Max length:

```cpp
maxLen = max(maxLen, right - left + 1);
```

---

## 8. When Sliding Window Works

* At most K elements
* K distinct / K odd / K zeros
* Longest / shortest valid window
* Only local window condition needed

---

## 9. When Sliding Window Fails

* Sum == K (with negatives)
* Non-monotonic condition
* Need exact prefix relation

→ Use Prefix Sum

---

## 10. Prefix Sum Pattern

```cpp
mp[0] = 1;

for (...) {
    sum += ...;
    count += mp[sum - k];
    mp[sum]++;
}
```

---

## 11. Prefix Sum Logic

```cpp
sum[j] - sum[i] = k;
=> sum[i] = sum[j] - k;
```

---

## 12. Transform Tricks

* odd → 1, even → 0
* binary → sum
* characters → frequency map

---

## 13. Common Sliding Window Patterns

* Longest substring without repeating
* Longest substring with K distinct
* Minimum window substring
* Count subarrays with K odds
* Max consecutive ones with K flips

---

## 14. Edge Cases

* k = 0?
* empty input?
* all same elements?
* large constraints (O(n) needed?)

---

## 15. Final Decision Flow

```text
Subarray?
    ↓
Monotonic condition?
    ↓ YES → Sliding Window
            ↓
        Exactly K? → atMost(k) - atMost(k-1)

    ↓ NO → Prefix Sum
```

---

## 🆕 16. Ends Picking Trick (VERY IMPORTANT)

### 🚨 Recognition Signal

* Pick elements from **either end**
* Must pick **exactly k elements**

---

### 💡 Core Idea

```text
Pick k from ends  ⇄  Remove (n - k) from middle
```

👉 Removing from ends always leaves a **contiguous subarray**

---

### 🎯 Transformation

```cpp
maxScore = totalSum - minSubarraySum(size = n - k);
```

---

### 🧠 When to Use

* Picking from left/right only
* Exactly k picks required
* Maximizing or minimizing score

---

### ⚡ Template

```cpp
total = sum(arr);
windowSize = n - k;

find minimum sum subarray of size windowSize;

answer = total - minSum;
```

---

### 🔁 Alternative Thinking

```text
take x from left + (k - x) from right
```

👉 Try all splits using prefix/suffix

---

### ❌ When NOT to Use

* Can pick from anywhere
* Not exactly k elements
* Dependencies between picks

---

### 🔥 One-line Memory Hook

```text
Ends problem → Think middle window
```

---

## 🔥 Core Takeaway

* Monotonic condition → Sliding Window
* Exactly K → atMost trick
* Non-monotonic → Prefix Sum
* Ends + K picks → Flip to middle window

---

This will now render perfectly in Markdown 👍

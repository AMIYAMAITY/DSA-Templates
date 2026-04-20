# DP + Monotonic Deque Pattern (Cheat Sheet)

## 🔹 Core Idea

When you see problems like:

* Maximize / minimize something
* Subsequence or sequence-based decisions
* Constraint on indices (like distance ≤ k)

👉 Think **Dynamic Programming (DP)** first.

---

## 🔹 Step-by-Step Thinking Process

### 1. Start with DP

Define:

```
dp[i] = best answer ending at index i
```

---

### 2. Identify Transition

Usually becomes:

```
dp[i] = nums[i] + best(dp[j]) where j ∈ [i-k, i-1]
```

👉 Meaning:

* You need the **maximum (or minimum)** value in a range

---

### 3. Spot the Bottleneck

Naive approach:

```
For each i → scan last k elements → O(n * k)
```

❌ Too slow

---

## 🔹 Key Pattern Recognition

If you see:

```
dp[i] depends on max/min of a sliding range
```

👉 You need **fast range query**

---

## 🔹 Tool Selection

| Situation            | Tool              |
| -------------------- | ----------------- |
| Static range queries | Segment Tree      |
| Sliding window range | Monotonic Deque ⭐ |
| Occasional max/min   | Heap              |

---

## 🔹 When to Use Deque

Use **Monotonic Deque** when:

* Range is sliding (like last k elements)
* Need max/min repeatedly
* Want O(n) solution

---

## 🔹 Deque Rules

Maintain deque such that:

1. **Front = maximum value index**
2. Remove indices out of window:

   ```
   while dq.front() < i-k → pop_front
   ```
3. Maintain decreasing order:

   ```
   while dp[i] >= dp[dq.back()] → pop_back
   ```

---

## 🔹 Final DP Formula

```
dp[i] = nums[i] + max(0, dp[dq.front()])
```

---

## 🔹 Mental Model

👉 "At each step, take the best from last k elements"

---

## 🔹 One-Line Trigger

If you see:

```
"best value in last k elements"
```

👉 Immediately think:

```
DP + Monotonic Deque
```

---

## 🔹 Related Problems

Practice these to master pattern:

* Constrained Subsequence Sum
* Jump Game VI
* Sliding Window Maximum

---

## 🔹 Interview Answer (Important)

If asked approach:

> "This is a DP problem where each state depends on the maximum of last k states. We optimize it using a monotonic deque to achieve O(n) time complexity."

---

## 🔹 Final Reminder

Don’t memorize code.

Train your thinking:

1. Write DP
2. Identify range dependency
3. Optimize with deque

---
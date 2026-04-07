# 🧠 HashMap Problems – Key Thinking Cheat Sheet

---

## 1. When to Think HashMap
- Need **fast lookup (O(1))**
- Tracking **frequency / count**
- Need to check **if something seen before**

---

## 2. Core Use Cases

### 🔹 Frequency Counting
- Count occurrences of elements

    mp[x]++

👉 Used in:
- duplicates
- majority element
- anagrams

---

### 🔹 Prefix + HashMap
- Store prefix states

    count += mp[current - target]

👉 Used in:
- subarray sum problems
- cumulative conditions

---

### 🔹 Seen Before (Lookup)
- Check existence

    if (mp.count(x)) { ... }

👉 Used in:
- Two Sum
- duplicates
- complement problems

---

## 3. Common Patterns

### 🔹 Complement Pattern
Find pair such that:

    a + b = target

→ Store:
    mp[target - x]

---

### 🔹 Count Pattern
Count number of valid pairs/subarrays

    count += mp[required]

---

### 🔹 Index Mapping
Store index instead of value

    mp[value] = index

---

## 4. Key Problem Signals

- “Find pair”
- “Count occurrences”
- “Subarray with condition”
- “Check duplicate”
- “Group elements”

👉 Think HashMap immediately

---

## 5. Sliding Window + HashMap
Used when:
- Need frequency inside window

    mp[s[right]]++

    while (invalid) {
        mp[s[left]]--
        left++
    }

👉 Used in:
- longest substring problems
- k distinct elements

---

## 6. Transform Tricks
- characters → frequency map
- values → counts
- prefix sum → hashmap

---

## 7. Count vs Existence

- Only check existence:

        if (mp.count(x))

- Count occurrences:

        count += mp[x]

---

## 8. Common Mistakes
- Forget initializing:

        mp[0] = 1   (prefix problems)

- Overwriting when need frequency
- Using map instead of unordered_map (performance)

---

## 9. Time Complexity
- Average: O(1)
- Worst: O(n) (rare)

---

## 10. Edge Cases
- duplicates?
- negative numbers?
- large input size?
- collisions (rare but possible)?

---

## 11. Final Decision Flow

    Need fast lookup?
        ↓ YES → HashMap

    Need frequency?
        ↓ YES → HashMap

    Need pair / complement?
        ↓ YES → HashMap

    Prefix-based condition?
        ↓ YES → Prefix Sum + HashMap

---

## 🔥 Core Takeaway
- Lookup → HashMap
- Frequency → HashMap
- Complement → HashMap
- Prefix condition → HashMap + Prefix Sum
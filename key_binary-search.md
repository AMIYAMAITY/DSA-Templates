# Binary Search Pattern Recognition & Cheat Sheet

> Binary Search is **NOT only for searching in sorted arrays**.
> The real power of binary search is:
>
> ```text
> Searching in a MONOTONIC SPACE
> ```
>
> If something changes like:
>
> ```text
> F F F F T T T T
> ```
>
> or:
>
> ```text
> T T T T F F F
> ```
>
> then binary search is possible.

---

# 1. Core Binary Search Recognition Pattern

## Ask these questions:

### ✅ Is the answer monotonic?

Meaning:

```text
If X works,
then all smaller/larger also work.
```

Example:

* Aggressive cows
* Allocate books
* Koko eating bananas
* Ship packages
* Minimum days problem

---

### ✅ Can I form a YES / NO function?

Example:

```cpp
can(mid)
```

returns:

```text
true / false
```

---

### ✅ Does the problem ask:

* maximize minimum
* minimize maximum
* kth smallest
* median
* minimum valid answer
* maximum possible value

If YES → likely Binary Search on Answer.

---

# 2. Types of Binary Search Problems

---

# Type 1: Classic Binary Search on Index

## Recognition

* sorted array
* search target
* lower_bound / upper_bound

---

## Problems

* Search Insert Position
* Binary Search
* First & Last Occurrence
* Floor / Ceil

---

## Template

```cpp
while(l <= h){

    int mid = l + (h-l)/2;

    if(arr[mid] == target)
        return mid;

    else if(arr[mid] < target)
        l = mid + 1;

    else
        h = mid - 1;
}
```

---

# Type 2: Binary Search on Answer

## MOST IMPORTANT TYPE

---

## Recognition Keywords

### 🚨 Strong Indicators

* minimize maximum
* maximize minimum
* smallest possible
* largest possible
* minimum capacity
* minimum speed
* maximum distance
* kth smallest
* median

---

## Core Thinking

Instead of searching indices:

```text
Search the ANSWER space
```

---

## Template

```cpp
while(l <= h){

    int mid = l + (h-l)/2;

    if(can(mid)){
        ans = mid;

        // depending on problem
        h = mid - 1;
        // OR
        l = mid + 1;
    }
    else{
        // opposite direction
    }
}
```

---

# 3. Two Main Binary Search Styles

---

# A) Find Minimum Valid

Pattern:

```text
F F F F T T T T
```

Goal:

```text
first TRUE
```

---

## Template

```cpp
if(valid(mid)){
    ans = mid;
    h = mid - 1;
}
else{
    l = mid + 1;
}
```

---

## Problems

* Minimum eating speed
* Minimum ship capacity
* Allocate books
* Painter partition

---

# B) Find Maximum Valid

Pattern:

```text
T T T T F F F
```

Goal:

```text
last TRUE
```

---

## Template

```cpp
if(valid(mid)){
    ans = mid;
    l = mid + 1;
}
else{
    h = mid - 1;
}
```

---

## Problems

* Aggressive cows
* Maximum minimum distance
* Magnetic force between balls

---

# 4. How to Build `can(mid)` Function

This is the HEART of BS-on-answer.

---

## Rule

`can(mid)` should answer:

```text
"Is it possible?"
```

---

## Examples

### Aggressive cows

```text
Can we place cows with minimum distance = mid ?
```

---

### Koko

```text
Can Koko finish within H hours using speed = mid ?
```

---

### Allocate books

```text
Can we allocate books so max pages <= mid ?
```

---

# 5. Binary Search on VALUE SPACE

Very important advanced pattern.

---

# Recognition

Problem involves:

* median
* kth smallest
* row-wise sorted matrix
* sorted property over values

---

# Core Idea

Binary search on VALUES.

NOT indices.

---

## Example

Median in row-wise sorted matrix.

We ask:

```text
How many elements <= mid ?
```

This count becomes monotonic.

---

# Template

```cpp
while(low <= high){

    int mid = (low + high)/2;

    int count = countLessEqual(mid);

    if(count <= required){
        low = mid + 1;
    }
    else{
        high = mid - 1;
    }
}
```

---

# 6. Binary Search on Partition

Very advanced & important.

---

# Recognition

Problems involving:

* two sorted arrays
* median of arrays
* kth element of arrays

---

# Core Idea

Binary search partition sizes.

---

## Important Condition

```text
left partition max <= right partition min
```

---

## Problems

* Median of two sorted arrays
* Kth element of two sorted arrays

---

# 7. Lower Bound vs Upper Bound

---

# lower_bound

Returns:

```text
first element >= target
```

---

# upper_bound

Returns:

```text
first element > target
```

---

# Visualization

```text
arr = [1,2,2,2,5]
```

---

## lower_bound(2)

```text
index = 1
```

---

## upper_bound(2)

```text
index = 4
```

---

# 8. Binary Search Direction Trick

---

# If current answer works

Ask:

```text
Do I want smaller answer?
OR
larger answer?
```

---

## Want minimum valid?

Move LEFT.

```cpp
h = mid - 1;
```

---

## Want maximum valid?

Move RIGHT.

```cpp
l = mid + 1;
```

---

# 9. Most Important Monotonicity Insight

Binary search requires:

```text
monotonic transition
```

Examples:

```text
F F F T T T
```

or:

```text
T T T F F F
```

---

# 10. Common Problems Mapping

| Problem                | Pattern      |
| ---------------------- | ------------ |
| Binary Search          | Index        |
| Search Insert          | Lower Bound  |
| First/Last Occurrence  | LB + UB      |
| Floor/Ceil             | LB/UB        |
| Aggressive Cows        | Max Valid    |
| Koko Eating Bananas    | Min Valid    |
| Allocate Books         | Min Valid    |
| Painter Partition      | Min Valid    |
| Ship Packages          | Min Valid    |
| Median Matrix          | Value Space  |
| Kth Smallest Matrix    | Value Space  |
| Median Two Arrays      | Partition BS |
| Kth Element Two Arrays | Partition BS |

---

# 11. Golden Rule of Binary Search

## Always Ask:

### What is changing monotonically?

If you find:

```text
invalid invalid invalid valid valid
```

Binary search becomes possible.

---

# 12. Common Mistakes

---

## ❌ Infinite loop

Wrong updates:

```cpp
l = mid;
h = mid;
```

---

## ❌ Overflow

Use:

```cpp
mid = l + (h-l)/2;
```

---

## ❌ Wrong answer initialization

For max problems:

```cpp
ans = -1
```

For min problems:

```cpp
ans = large
```

---

## ❌ Wrong search space

Always derive:

* minimum possible answer
* maximum possible answer

carefully.

---

# 13. Quick Recognition Cheat Sheet

---

## 🚨 If you see:

### "minimum possible"

Think:

```text
Find first TRUE
```

---

### "maximum possible"

Think:

```text
Find last TRUE
```

---

### "kth"

Think:

```text
Binary search on value space
```

---

### "median"

Think:

```text
Value space OR partition BS
```

---

### "maximize minimum"

Think:

```text
Binary Search on Answer
```

---

### "minimize maximum"

Think:

```text
Binary Search on Answer
```

---

# 14. Ultimate Binary Search Mental Model

Binary Search is NOT:

```text
searching sorted arrays
```

Binary Search is:

```text
finding boundary in a monotonic space
```

That is the REAL concept.

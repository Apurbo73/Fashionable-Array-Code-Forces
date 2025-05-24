## Fashionable-Array-Code-Forces:

This C++ code solves a problem where the goal is to **make an array "fashionable"** by removing the fewest number of elements. An array is considered *fashionable* if:

```
min(array) + max(array) is divisible by 2.
```

Let’s break down the code step by step:

---

### 📌 **Step-by-step Explanation**

```cpp
int t; cin >> t;
```

* Read the number of test cases `t`.

---

```cpp
while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
```

* For each test case:

  * Read array size `n`
  * Read the `n` integers into array `a`

---

```cpp
sort(a.begin(), a.end());
```

* Sorting the array helps in easily determining the `min` and `max` values for any subarray.
* `a[i]` will be the smallest and `a[j]` the largest in the subarray from `i` to `j`.

---

```cpp
int max_len = 1;
for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
        int min_val = a[i];
        int max_val = a[j];
        if ((min_val + max_val) % 2 == 0) {
            max_len = max(max_len, j - i + 1);
        }
    }
}
```

* **Brute-force check for every subarray**:

  * For every pair `(i, j)` (from `i` to `j`), calculate:

    * `min_val = a[i]`
    * `max_val = a[j]`
  * Check if `(min_val + max_val) % 2 == 0`, meaning the subarray is *fashionable*.
  * Track the **maximum length** of such a subarray using `max_len`.

---

```cpp
cout << n - max_len << "\n";
```

* The fewest elements to remove = total `n` - longest fashionable subarray.
* Print the answer for this test case.

---

### 🧠 Summary:

This code finds the **largest subarray** where the min + max is even, and returns how many elements must be removed from the original array to get such a subarray.

### ⚠️ Efficiency Note:

This code has a **quadratic time complexity O(n²)** due to the nested loop. It works only because the constraint on `n` is small (e.g., ≤ 50).


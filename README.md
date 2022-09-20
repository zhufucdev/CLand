# Determinant Calculator

Supports **n (n < 10)** class determinant calculation.

Input: **int** _n_, followed by n^2 digits separated by whitespace.

Output: procedure of the determinant's caculation and its result.

# Example

Input:
```
4
1 0 0 0
1 2 0 0
1 2 3 0
1 2 3 4
```

Output:
```
a11 * a22 * a33 * a44 = 24.000000, a11 * a22 * a34 * a43 = -0.000000, a11 * a23 * a32 * a44 = -0.000000, a11 * a23 * a34 * a42 = 0.000000, a11 * a24 * a32 * a43 = 0.000000, a11 * a24 * a33 * a42 = -0.000000, a12 * a21 * a33 * a44 = -0.000000, a12 * a21 * a34 * a43 = 0.000000, a12 * a23 * a31 * a44 = 0.000000, a12 * a23 * a34 * a41 = -0.000000, a12 * a24 * a31 * a43 = -0.000000, a12 * a24 * a33 * a41 = 0.000000, a13 * a21 * a32 * a44 = 0.000000, a13 * a21 * a34 * a42 = -0.000000, a13 * a22 * a31 * a44 = -0.000000, a13 * a22 * a34 * a41 = 0.000000, a13 * a24 * a31 * a42 = 0.000000, a13 * a24 * a32 * a41 = -0.000000, a14 * a21 * a32 * a43 = -0.000000, a14 * a21 * a33 * a42 = 0.000000, a14 * a22 * a31 * a43 = 0.000000, a14 * a22 * a33 * a41 = -0.000000, a14 * a23 * a31 * a42 = -0.000000, a14 * a23 * a32 * a41 = 0.000000
sum = 24.000000
```

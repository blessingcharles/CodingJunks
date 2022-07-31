### Properties


1. swap

a = a^b
b = a^b
a = a^b


2. even and odd
a&1 == 0  // even else odd

3. Xor over 1 to n numbers

if(n%4 == 0) print(n)
else if(n%4 == 1) print(1)
else if(n%4 == 2) print(n+1)
else print(0)

4. Xor over a range of numbers [L , R]

XOR(1 to L-1 ) ^ XOR(1 to R)

5. if ith bit set of number n

n & (1<< i) == 1

6. set ith bit

n = n | (1 << i)

7. clear ith bit

n = n & ~(1 << i)

8. remove the last set bit

n & (n-1)

9. is power of 2
n & (n-1) == 0

10. get the last set bit

n&~(n-1)

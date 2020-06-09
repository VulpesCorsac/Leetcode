static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
/// from https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/566075/(C%2B%2B)-O(1)-0ms-6.1Mb-Bit-manip-single-line-solution-w-explanation-100-100

/*
(This first part of the answer is just proofs, so if you want you can skip this first section)
(There is a tl;dr if you don't want to read this much)

Lets first take a look at some characteristics of the problem:
1.0 If m and n are not equal, then m+1 is included in the range [m, n]. So we have: a) last bit of m is 0 -> last bit of m+1 is 1; or b) last bit of m is 1 -> last bit of m+1 is 0.
1.1. So, in this case, we guarantee that the last bit of the ranged & is 0.
2.0 If m and n are different by more than 2^k, it implies that m+2^k exists on the range. If it does, then a) the k-th bit (from right to left, counting from 0) of m is 0 -> the k-th bit of m+2^k is one (because 2^k can be represented as a bitchain with a single one on the k-th bit and k trailing zeros); or b) the k-th bit from m is 1 -> the k-th bit of m+2^k is 0.
2.1 So, as both k-th bits are different, using & will make the kth bit 0.
2.2 Moreover, as having a difference higher than 2^k also implies a difference higher than 2^(k - 1), 2^(k - 2), ..., 2^1, 2^0 , then if m and n have a difference higher than 2^k, the k bits from the right of the answer will be 0.
3.0 Two integers a and b will have the same bits from the k-th bit until the last bit iff they don't have a difference higher than 2^k. By representing a as the sum (index is i) of a_i * 2^i (m_i is a bit) and b as the sum of b_i * 2^i, then their difference is the sum of 2^i (a_i - b_i). Note that, as the sum of all 2^i 's from 0 to k-1 is bounded by (2^k) - 1, then the bits from 0 to k can't generate a difference higher than 2^k by themselves.
3.1 So, if this difference exists, its only possible if a difference equal to one on the bits k to last exists, which in turn would imply different bits.
3.2 This in turn implies that, if n and m have a difference less than 2^k, then, as every number in the range is less than that difference, every number in the range shares bits from the left of k. Using & on every one of them would as such just return the shared bits.

(You can read from here if you skipped the last part)

Using these facts, lets begin constructing our code.

We can determine if a bit is equal between n and m by xor'ing their bits, as b1 ^ b2 = 0 only if b1 == b2. So, if there is a shared prefix of bits between them, we'll get a bunch of leading zeros at the beginning. By using the __ builtin_clz macro, we can get the number of leading zeros on that sequence.

Note: This macro will NOT work if its input is zero. As the input is n ^ m, this would imply n ^ m == 0. By xor'ing both sides and simplifying, we get n == m, which would imply that only n is on the & range. So, in the case where they are equal, we can inmediately return n.
We can therefore construct a mask by first initializing an int with only ones (0xFFFFFFFF) and then r-shifting it as many times as leading zeros we obtained before. This will generate a sequence with the same number of leading zeros, but with 1's everywhere else. If we therefore use a binary not on that sequence, we'll get a mask which maps a 1 to every bit before there exists a difference between both numbers.

By using & with the mask and n, we'll only get the bits that are shared between each other, which is the part that will be shared between every other number in the range.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return ((n^m) == 0) ? n : (n & (~(0xFFFFFFFF >> __builtin_clz(n^m))));
    }
};

*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            ++c;
        }
        return n << c;
    }
};



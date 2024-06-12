#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// Function to compute the sum of digits of a number
int sumOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a given n satisfies the condition D(k * n) == k * D(n)
bool isValid(long long n, int k) {
    return sumOfDigits(k * n) == k * sumOfDigits(n);
}

// Function to count valid numbers in the range [10^l, 10^r)
long long countValidNumbers(int l, int r, int k) {
    long long count = 0;
    long long start = std::pow(10, l);
    long long end = std::pow(10, r);

    for (long long n = start; n < end; ++n) {
        if (isValid(n, k)) {
            count = (count % MOD+ 1% MOD) % MOD;
        }
    }
    return count;
}

int main() {
     int t;
     cin>>t;
     while(t--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<countValidNumbers(l,r,k)<<endl;
     }

    return 0;
}

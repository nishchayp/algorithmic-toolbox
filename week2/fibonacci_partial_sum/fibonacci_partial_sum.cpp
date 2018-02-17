#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fib_term(long long n) {
    return n % 60;
}

long long fib(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    for (int i = 2; i <= n; ++i)
    {
        long long temp = current + previous;
        previous = current;
        current = temp;        
    }
    return current;
}

int get_fibonacci_partial_sum_fast(long long from, long long to) {
    int f = fib_term(from + 2 - 1);
    int t = fib_term(to + 2);
    if (f < t) {
        return (fib(t) - fib(f)) % 10;
    } else {
        return (fib(60) - fib(f) + fib(t)) % 10;
    }
}               

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}

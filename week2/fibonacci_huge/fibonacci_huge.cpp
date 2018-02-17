#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fib(long long n, long long m) {
    if (n == 0)
        return 0;
    long long previous = 0 % m;
    long long current = 1 % m;
    for (int i = 2; i <= n; ++i)
    {
        long long temp = (previous + current) % m;
        previous = current;
        current = temp;
    }
    return current;
}

long long get_period_length(long long m) {
    long long previous = 0;
    long long current = 1;
    long long count = 1;
    while (!(current == 0 && previous == 1))
    {
        long long temp = (previous + current) % m;
        previous = current;
        current = temp;
        count++;
    }
    return count;    
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    return fib(n % get_period_length(m), m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}

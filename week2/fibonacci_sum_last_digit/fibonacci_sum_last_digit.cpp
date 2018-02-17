#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
	if (n <= 1)
		return n;

	int previous = 0;
	int current = 1;
	int sum = 1;

	for (int i = 2; i <= n; i++) {
		int temp = (current + previous) % 10;
		previous = current;
		current = temp;
		sum = (sum + current) % 10;
	}

	return sum;
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

long long get_period_sum(long long m) {
    long long previous = 0;
    long long current = 1;
    long long count = 1;
    long long sum = 1;
    while (!(current == 0 && previous == 1))
    {
        long long temp = (previous + current) % m;
        previous = current;
        current = temp;
        count++;
        sum = (sum + current) % 10;
    }
    return sum;    
}

int fibonacci_sum_faster(long long n) {
	int period_length = get_period_length(10);
	return fibonacci_sum_fast(n % period_length) + (get_period_sum(10) * n / period_length) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << '\n';
    // std::cout << fibonacci_sum_fast(n) << '\n';
    std::cout << fibonacci_sum_faster(n) << '\n';
}

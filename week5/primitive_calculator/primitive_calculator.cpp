#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_optimal_times(int n) {
	std::vector<int> times(n + 1);
	times[0] = -1;
	times[1] = 0;
	for (int i = 2; i <= n; i++) {
		int x = times[i - 1];
		if (i % 2 == 0) {
			x = min(x, times[i / 2]);
		}
		if (i % 3 == 0) {
			x = min(x, times[i / 3]);
		}
		times[i] = x + 1;
	}
	return times;
}

void print_sequence(std::vector<int> times, int n) {
	std::vector<int> sequence;
	while (n >= 1) {
		sequence.push_back(n);
		if (times[n - 1] == times[n] - 1) {
			n = n - 1;
		} else if (n % 2 == 0 && times[n / 2] == times[n] - 1) {
			n = n / 2;
		} else if (n % 3 == 0 && times[n / 3] == times[n] - 1) {
			n = n / 3;
		}
	}
	for (int i = sequence.size() - 1; i >= 0; i--) {
		std::cout << sequence[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
  int n;
  std::cin >> n;
  // vector<int> sequence = optimal_sequence(n);
  // std::cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   std::cout << sequence[i] << " ";
  // }
  std::vector<int> times = dp_optimal_times(n);
  std::cout << times[n] << std::endl;
  print_sequence(times, n);
}

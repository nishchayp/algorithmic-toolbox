#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  for (int i = 1; n > 0; i++) {
    if ((n - i - (i + 1)) >= 0) {
      summands.push_back(i);
      n = n - i;
    } else {
      summands.push_back(n);
      n = 0;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << "\n";
}

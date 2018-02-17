#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int MaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

long int MaxPairwiseProductFast(const vector<int>& numbers) {
  int max1, max2;
  numbers[0] > numbers[1] ? (max1 = numbers[0], max2 = numbers[1]) : (max1 = numbers[1], max2 = numbers[0]);
  int n = numbers.size();
  for (int i = 2; i < n; ++i) {
  	if (numbers[i] >= max1) {
  		max2 = max1;
  		max1 = numbers[i];
  	} else if (numbers[i] > max2) {
  		max2 = numbers[i];
  	}
  }
  return (long int)max1 * max2;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // int result = MaxPairwiseProduct(numbers);
    long int result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}

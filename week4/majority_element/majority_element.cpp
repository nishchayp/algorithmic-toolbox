#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];

  int mid = left + (right - left + 1) / 2;
  int x_l = get_majority_element(a, left, mid);
  int x_r = get_majority_element(a, mid, right);

  int count_l = 0;
  for (int i = left; i < right; i++) {
  	if (a[i] == x_l) {
  		count_l++;
  	}
  }
  if (count_l > (right - left) / 2) return x_l;

  int count_r = 0;
  for (int i = left; i < right; i++) {
  	if (a[i] == x_r) {
  		count_r++;
  	}
  }
  if (count_r > (right - left) / 2) return x_r;
  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

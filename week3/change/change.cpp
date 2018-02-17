#include <iostream>

int get_change(int m) {
	int count = 0;
	count += m / 10;
	m = m % 10;
	count += m / 5;
	m = m % 5;
	count += m;
	return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

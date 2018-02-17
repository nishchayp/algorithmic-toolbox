#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool sort_rule(string x, string y) {
  int i = 0, j = 0;
  int len_x = x.length();
  int len_y = y.length();
  while (true) {
    if (x[i] != y[j]) {
    	return x[i] > y[j];
    } else if (i < len_x - 1 || j < len_y - 1) {
    	if (i < len_x - 1)
    	  i++;
    	if (j < len_y - 1)
    	  j++;
    } else {
      return len_x < len_y;
    }
  }
}

string largest_number(vector<string> a) {
  std::sort(a.begin(), a.end(), sort_rule);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  std::cout << "\n";
}

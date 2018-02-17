#include <iostream>
#include <string>
#include <vector>

// using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
	int m = str1.length();
	int n = str2.length();
  vector< vector<int> > v(m + 1, vector<int>(n + 1));
  for (int i = 0; i <= m; i++) {
  	v[i][0] = i;
  }
  for (int i = 0; i <= n; i++) {
  	v[0][i] = i;
  }

  for (int j = 1; j <= n; j++) {
  	for (int i = 1; i <= m; i++) {
  	  v[i][j] = min(v[i - 1][j] + 1, v[i][j - 1] + 1);
  	  if (str1[i - 1] == str2[j - 1]) {
  	  	v[i][j] = min(v[i][j], v[i - 1][j - 1]);
  	  } else {
  	  	v[i][j] = min(v[i][j], v[i - 1][j - 1] + 1);
  	  }
  	}
  }

  // for (int i = 0; i <= m; i++) {
  // 	for (int j = 0; j <= n; j++) {
  // 		cout << v[i][j] << " ";
  // 	}
  // 	cout << endl;
  // }

  return v[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

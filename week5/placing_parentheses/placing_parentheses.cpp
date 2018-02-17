#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

// using std::vector;
// using std::string;
// using std::max;
// using std::min;
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

vector<long long> max_min(const string &exp, vector< vector<long long> > &M, vector< vector<long long> > &m, int i, int j) {
  vector<long long> r(2);
  r[0] = numeric_limits<long long>::min();
  r[1] = numeric_limits<long long>::max();
  for (int k = i; k < j; k++) {
  	long long a = eval(M[i][k], M[k + 1][j], exp[k * 2 + 1]);
  	long long b = eval(M[i][k], m[k + 1][j], exp[k * 2 + 1]);
  	long long c = eval(m[i][k], M[k + 1][j], exp[k * 2 + 1]);
  	long long d = eval(m[i][k], m[k + 1][j], exp[k * 2 + 1]);
  	r[0] = max(r[0], a);
  	r[0] = max(r[0], b);
  	r[0] = max(r[0], c);
  	r[0] = max(r[0], d);

  	r[1] = min(r[1], a);
  	r[1] = min(r[1], b);
  	r[1] = min(r[1], c);
  	r[1] = min(r[1], d);
  }
  return r;
}

long long get_maximum_value(const string &exp) {
  int dim = exp.length() / 2 + 1;
  vector< vector<long long> > M(dim, vector<long long>(dim));
  vector< vector<long long> > m(dim, vector<long long>(dim));

  for (int i = 0; i < dim; i++) {
  	M[i][i] = (long long)(exp[i * 2] - 48); 
  	m[i][i] = (long long)(exp[i * 2] - 48); 
  }

  for (int s = 1; s < dim; s++) {
  	for (int i = 0; i + s < dim; i++) {
  	  vector<long long> r(2);
  	  r = max_min(exp, M, m, i, i + s);
  	  M[i][i + s] = r[0];
  	  m[i][i + s] = r[1];
  	}
  }

  return M[0][dim - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}

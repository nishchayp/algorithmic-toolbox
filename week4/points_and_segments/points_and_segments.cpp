#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> fast_count_segments(vector< pair<int, int> > coord, vector<int> points) {
  vector<int> cnt(points.size());
  sort(coord.begin(), coord.end());
  return cnt;
}

vector<int> naive_count_segments(vector< pair<int, int> > coord, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < coord.size(); j++) {
      cnt[i] += coord[j].first <= points[i] && points[i] <= coord[j].second;
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector< pair<int, int> > coord(n);
  for (size_t i = 0; i < coord.size(); i++) {
    std::cin >> coord[i].first >> coord[i].second;
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(coord, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

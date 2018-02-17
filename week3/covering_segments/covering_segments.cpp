#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

// vector<int> optimal_points(vector<Segment> &segments) {
//   vector<int> points;
//   int count = 0;
//   while (count < segments.size()) {  
//     int min = 1000000000;
//     for (size_t i = 0; i < segments.size(); ++i) {
//       if (segments[i].end < min && segments[i].end >= 0)
//         min = segments[i].end;
//     }
//     points.push_back(min);
//     for (size_t i = 0; i < segments.size(); ++i) {
//       if (min <= segments[i].end && min >= segments[i].start) {
//         segments[i]. start = -1;
//         segments[i].end = -1;
//         count++;
//       }
//     }
//   }
//   return points;
// }

bool less_than(Segment i, Segment j) {
  return i.end < j.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  std::sort(segments.begin(), segments.end(), less_than);
  int point = segments[0].end;
  points.push_back(point);
  for (size_t i = 0; i < segments.size(); ++i) {
    if (point < segments[i].start || point > segments[i].end) {
      point = segments[i].end;
      points.push_back(point);
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << "\n";
}

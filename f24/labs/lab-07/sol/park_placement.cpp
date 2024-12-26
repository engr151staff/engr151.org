// lab02.cpp
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

int CalcNumIntersectPoints(int x1, int x2, int y1, int y2, int r1, int r2) {
  int num_points, smaller_r, larger_r;
  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  // define smaller and larger radii
  if (r1 < r2) {
    smaller_r = r1;
    larger_r = r2;
  } else {
    smaller_r = r2;
    larger_r = r1;
  }

  // find number of overlapping points

  if ((distance == 0) && (r1 == r2)) {
    // Coincident circles
    num_points = -1;
  } else if (distance > (r1 + r2)) {
    // Circles too far apart to intersect
    num_points = 0;
  } else if (distance == (r1 + r2)) {
    // Circles outside one another, exactly the right distance apart to touch
    // once
    num_points = 1;
  } else if (distance + smaller_r == larger_r) {
    // Smaller circle inside larger circle, exactly the right distance apart to
    // touch once
    num_points = 1;
  } else if (distance + smaller_r < larger_r) {
    // Smaller circle inside larger circle, too small to touch larger circle
    num_points = 0;
  } else {
    // Anything else, they intersect twice
    num_points = 2;
  }

  return num_points; // 0, 1, 2, or -1(complete overlap)
}

void test() {
  // six test cases //
  // 1. Distance between centers == 0 and radii are equal --> all points
  // 2. Distance between centers > sum of radii --> 0 points
  // 3. Distance between centers == sum of radii --> 1 point
  // 4. Distance between centers + smaller radius == larger radius --> 1 point
  // 5. Distance between centers + smaller radius < larger radius --> 0 points
  // 6. 2 points of intersection

  assert(CalcNumIntersectPoints(30, 30, 30, 30, 15, 15) == -1);
  assert(CalcNumIntersectPoints(30, 30, 60, 30, 10, 5) == 0);
  assert(CalcNumIntersectPoints(30, 30, 60, 30, 10, 20) == 1);
  assert(CalcNumIntersectPoints(30, 30, 40, 30, 20, 10) == 1);
  assert(CalcNumIntersectPoints(30, 30, 40, 30, 20, 5) == 0);
  assert(CalcNumIntersectPoints(30, 30, 40, 30, 10, 5) == 2);
  return;
}

int main() {
  int x1;
  int x2;
  int y1;
  int y2;
  int r1;
  int r2;

  cin >> x1;
  cin >> x2;
  cin >> y1;
  cin >> y2;
  cin >> r1;
  cin >> r2;
  cout << CalcNumIntersectPoints(x1, x2, y1, y2, r1, r2) << endl;
  test();
  return 0;
}

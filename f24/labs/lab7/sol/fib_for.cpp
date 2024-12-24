#include <iostream>

using namespace std;

int main() {

  int count;

  cout << "how many fibonacci numbers do you want printed? ";
  cin >> count;

  int prevPrevious = 0;
  int previous = 1;
  int result = 0;

  // calculate numbers 0 to n of the fibonacci sequence
  for (int i = 0; i < count; i++) {
    if (i == 0) {
      cout << 0;
    } else if (i == 1) {
      cout << 1;
    } else {
      result = previous + prevPrevious;
      prevPrevious = previous;
      previous = result;
      cout << result;
    }
    cout << " ";
  }

  cout << endl;
  return 0;
}

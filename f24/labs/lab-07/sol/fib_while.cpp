#include <iostream>

using namespace std;

int main() {

  int count;

  cout << "how many fibonacci numbers do you want printed? ";
  cin >> count;

  int prevPrevious = 0;
  int previous = 1;
  int counter = 0;
  int result = 0;

  // calculate numbers 0 to n of the fibonacci sequence
  while (counter < count) {
    if (counter == 0) {
      cout << 0;
    } else if (counter == 1) {
      cout << 1;
    } else {
      result = previous + prevPrevious;
      prevPrevious = previous;
      previous = result;
      cout << result;
    }
    cout << " ";
    counter++;
  }

  cout << endl;
  return 0;
}

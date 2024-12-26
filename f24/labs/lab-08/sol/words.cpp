#include "words.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
  char word1[10] = "ENGR";
  char word2[4] = "151";
  char word3[11] = "HeLLoWoRLD";
  char word4[12] = "ILoveToCode";
  char word5[11] = "helloworld";
  /***
      //test your code here
   ***/
  // Test word_length
  assert(word_length(word1) == 4);
  assert(word_length(word2) == 3);
  assert(word_length(word3) == 10);
  assert(word_length(word4) == 11);
  assert(word_length(word5) == 10);

  // Test concatenate
  concatenate(word1, word2);
  assert(word_length(word1) == 4 + 3);
  for (size_t i = 0; i < 7; ++i) {
    assert(word1[i] == ("ENGR151")[i]);
  }

  // Test check_case
  int num_upper = 0;
  int num_lower = 0;
  check_case(word4, num_upper, num_lower);
  assert(num_upper == 4);
  assert(num_lower == 7);
  for (int i = 0; i < word_length(word4); ++i) {
    assert(word4[i] == ("ilovetocode")[i]);
  }

  cout << "All tests passed." << endl;
  return 0;
}

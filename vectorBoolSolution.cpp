#include <iostream>
#include <vector>
#include <chrono>

int main() {
  // Using std::vector<bool>
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<bool> boolVector(1000000);
  for (int i = 0; i < 1000000; ++i) {
    boolVector[i] = (i % 2 == 0);
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "std::vector<bool> time: " << duration.count() << " ms" << std::endl;

  // Using std::vector<char> as an alternative
  start = std::chrono::high_resolution_clock::now();
  std::vector<char> charVector(1000000);
  for (int i = 0; i < 1000000; ++i) {
    charVector[i] = (i % 2 == 0) ? 1 : 0; //Represent bool as char
  }
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "std::vector<char> time: " << duration.count() << " ms" << std::endl;

  return 0;
}

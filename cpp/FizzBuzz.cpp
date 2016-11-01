#include <iostream>
#include <vector>
#include <string>

class Solution{
public:
  std::vector<std::string> fizzBuzz(int n){
    std::vector<std::string> v;
    for (size_t i = 1; i <= n; i++) {
      std::string currWord = "";
      bool isSpecial = false;
      if (i % 3 == 0) {
        currWord = currWord + "Fizz";
        isSpecial = true;
      }
      if (i % 5 == 0) {
        currWord = currWord + "Buzz";
        isSpecial = true;
      }
      if (isSpecial){
        v.push_back(currWord);
      }
      else {
        // C++11 format. use `-std=c++11` when compiling
        v.push_back(std::to_string(i));
      }
    }

    return v;
  }
};


int main(int argc, char const *argv[]) {
  Solution s = Solution();
  std::vector<std::string> v = s.fizzBuzz(15);
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }
  return 0;
}

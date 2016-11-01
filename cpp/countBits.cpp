#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
public:
  std::vector<int> CountBits(int num){
    std::vector<int> result;
    for (int i = 0; i <= num; i++) {
      int sqrt_num = int(log2(i));
      int num_one = 0;
      int tmp_i = i;
      for (int j = sqrt_num; j >=0 && tmp_i > 0; j--) {
        int curr_res =  tmp_i / pow(2, j);
        num_one += curr_res;
//        cout << 'curr_res:' << curr_res<< endl;
        tmp_i -=  pow(2, j) * curr_res;
//        cout << 'tmp_i:' << tmp_i << endl;
      }
      result.push_back(num_one);
    }

    return result;
  }
   vector<int> countBits2(int num){
            vector<int> res={0};
            long long int base=1;
            int count=0;
            for(int i=1;i<=num;i++){
                 res.push_back(res[i-base]+1);
                 if(++count==base){
                       base*=2;
                       count=0;
                 }
            }
            return res;
      }
};

int main(int argc, char const *argv[]) {
  Solution s = Solution();
  std::vector<int> res = s.CountBits(5);
  for (size_t i = 0; i < res.size(); i++) {
    std::cout << res[i] << std::endl;
  }
  return 0;
}

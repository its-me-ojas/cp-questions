class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int a = __builtin_popcount(num1);
    int b = __builtin_popcount(num2);
    int temp = num1;
    for (int i = 0; i < 32; i++) {
      // if a bits are more than b and ith bit is set in num1 ( i want to remove
      // this bit)
      if (a > b && (1 << i) & num1) {
        temp ^= (1 << i);
        --a;
      }
      if (b > a && !((1 << i) & num1)) {
        temp ^= (1 << i);
        ++a;
      }
    }
    return temp;
  }
};

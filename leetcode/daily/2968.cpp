class Solution {
public:
  int digitsSum(int n) {
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
  int punishmentNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (digitsSum(i * i) == i)
        sum += i * i;
    }
    return sum;
  }
};

#include<iostream>
#include <cstring>
#include <string>
using namespace std;

/*
* 作用：用于判断两个字符串及子串是否相等
* 实现步骤：
* 1、预处理幂次
* 2、计算字符的前缀的Hash值
* 3、得到[i, j)区间内的子串的hash值
*/

typedef unsigned long long ull;

// 字符串最大长度
const int N = 100000;
// 用于取余的质数
const int mod = 10000 + 7;
// 幂表
int pow[N];

struct Hash{
  string s;
  ull H[N];

  Hash(string str):s(str){
    MakeHash(s);
  }

  // 生成hash值
  void MakeHash(string s) {
    int len = s.size();
    H[0] = 0;
    for (int i = 0; i < len; i++) {
      H[i + 1] = (H[i] * 26 + (s[i] - 'a' + 1)) % mod;
    }
  }

  // 得到[i, j)区间内的子串的hash值，下标从0开始
  ull GetHash(int i, int j) {
    return H[j] - H[i] * pow[j - i] % mod;
  }

};

// 用于计算基数的幂次
void MakePow(int len){
  pow[0] = 1;
  for (int i = 1; i < len; i++) {
    pow[i] = pow[i - 1] * 26 % mod;
  }
}

// 如果两个字符串的hash值相等，还需判断它俩值是否相等。或者直接调整mod
bool equeal(string s1, string s2){
  return s1 == s2;
}

// 实用示例
int main() {
  string s;
  cin >> s;                                         //aba
  Hash a(s);
  cout << a.GetHash(0, 2) << endl;                  //28
  return 0;
}

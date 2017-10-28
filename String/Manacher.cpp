#include<iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
* 作用：求出一个字符串以任意字符串为中心的最长回文子串的长度
* 实现步骤：
* 1、预处理，将字符串每两个字符串之间加上一个特殊符号’＃‘’
* 2、计算字符的前缀的Hash值
* 3、得到[i, j)区间内的子串的hash值
*/

// 字符串最长长度
const int N = 1000 + 5;
// 处理后的字符串
char manacher[N];
// 用以保存以manacher[i]为中心的最长回文串长度的一半
int a[N];

// 预处理
void init(string &s) {
  manacher[0] = s[0];
  for (int i = 1; i < s.size(); i++) {
    manacher[2 * i - 1] = '#';
    manacher[2 * i] = s[i];
  }
}

int Manacher(int len) {
  a[0] = 0;
  int i = 0, j;
  int left , right;
  int ans = 0;
  while (i < len) {
    // 当在以manacher[i]没有超过越过左边的边界，并且manacher[i + a[i]]的左右两边的字符相等时
    while (i - a[i] > 0 && manacher[(i + a[i]) + 1] == manacher[(i - a[i]) - 1 ]) {
      a[i] += 1;
    }
    // 更新最小的回文长度
    ans = min(ans, a[i]);
    j = i + 1;
    // left和right为manacher[i]左右下标
    left = i - (j - i);
    right = j;
    // 如何为第一、二种情况游标向右，右边在以manacher[i]为中心的回文串内并且以manacher[left]的最左边与manacher[i]不能相等
    while (right <= i + a[i] && i - a[i] != left - a[left]) {
      a[j] = min(a[left], a[i] - (j - i));
      j +=1;
      left = i - (j - i);      
      right = j;
    }
    // 如果为第三种情况，manacher[left]的最左端恰好等于manacher[i]的最左边时，
    // 不能判断a[right]为多少，只知道会比它大
    a[j] = max(a[i] - (j - i), 0);
    i = j;
  }
  return ans;
}

int main() {
  string s;
  while (cin >> s) {
    init(s);
    int ans = Manacher(2 * s.size() -1);
    cout << ans << endl;
    cout << '\n';
  }
}

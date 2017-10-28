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
* 2、计算每一个以s[i]为中心的回文
*/

// 字符串最长长度
const int N = 110000 + 5;
char s[N];
char m[N + N];
int a[N + N];
int len;

void init(){
  len = strlen(s);
  m[0] = '#';
  for (int i = 0; i < len; i++) {
    m[i * 2 + 1] = s[i];
    m[i * 2 + 2] = '#';
  }
  len = 2 * len + 1;
}

int manacher(){
  memset(a, 0, sizeof(a));
  a[0] = 0;
  int i = 0, j, ans = 0;
  while (i < len) {
    while (i - a[i] > 0 && i + a[i] <= len && m[i + a[i] + 1] == m[i - a[i] - 1]) {
      a[i]++;
    }
    ans = max(ans, a[i]);
    j = i + 1;
    while (j <= i + a[i] && i - a[i] != i - (j - i) - a[i - (j - i)]) {
      a[j] = min(a[i - (j - i)], a[i] - (j - i));
      j++;
    }
    a[j] = max(a[i] - (j - i) , 0);
    i = j;
  }
  return ans;
}

int main() {

  while (scanf("%s", s) != EOF) {
    init();
    int ans = manacher();
    printf("%d\n", ans);
  }
  return 0;
}

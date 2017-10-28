#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
* 作用：可判断模式串在匹配出现的次数，解决匹配失败的回溯，只需要管模式串
* 实现步骤：
* 1、预处理，将字符串每两个字符串之间加上一个特殊符号’＃‘’
* 2、计算每一个以s[i]为中心的回文
*/
const int N = 1000000 + 5;
int Next[N];
char s1[N];
char s2[N];
int len;

/*
*  next[i]:
*  k = 0时，next[0]为-1；
*  next[i]不存在时，next[i]为０；
*  next[i]为前i-１个字符串的
*/
void getNext() {
  Next[0] = -1;
  // k为i前面的一位
  int i = 0, k = -1, len = strlen(s2);
  while (i < len) {
    if (k == -1 || s2[i] == s2[k]) {
      Next[++i] = ++k;
    }else{
      k = Next[k];
    }
  }
}

int kmp() {
  int i = 0, k = 0, len1 = strlen(s1), len2 = strlen(s2);
  int ans = 0;
  while (i < len1) {
    if (k == -1 || s1[i] == s2[k]) {
        i++;
        k++;
    }else{
        k = Next[k];
    }
    if (k == len2) {
      ans++;
    }
  }
  return ans;
}

int main()
{
  freopen("in.txt", "r", stdin);
  int  T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s %s", s2, s1);
    getNext();
    printf("%d\n", kmp());
  }
}

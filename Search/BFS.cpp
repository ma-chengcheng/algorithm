#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 10000 + 5;
bool vist[N];
bool del[N];
int text[N];
int pre[N];
int m, n;

int yu;

bool BFS(){
  queue<int> Q;
  Q.push(0);
  int head;
  while (!Q.empty()) {
    head = Q.front();
    Q.pop();
    for (int i = 0; i < 10; i++) {
      if (del[i] == 1 || (head == 0 && i == 0)) {
        continue;
      }
      int num = (head * 10 + i) % n;
      if (vist[num]) {
        continue;
      }

      pre[num] = head;
      vist[num] = 1;
      text[num] = '0' + i;

      Q.push(num);
      if (num == 0) {
        return true;
      }
    }
  }
  return false;
}

// 打印答案
void printAns() {
  string ans;
  int p = 0;
  while (p!=0 || ans.empty()) {
    ans += text[p];
    p = pre[p];
  }
  reverse(ans.begin(), ans.end());
  puts(ans.c_str());
}

int main() {
  freopen("in.txt", "r", stdin);

  int Case =  0;
  while(scanf("%d%d",&n, &m) != EOF){
    memset(vist, 0, sizeof(vist));
    memset(del, 0, sizeof(del));
    int d;
    while (m--) {
      scanf("%d", &d);
      del[d] = 1;
    }
    cout << "Case " << ++Case << ": ";
    if (BFS()) {
      printAns();
    }else{
      printf("%d\n", -1);
    }
  }
  return 0;
}

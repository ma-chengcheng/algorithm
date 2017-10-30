#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

int map[9][9];
struct node{
  int x;
  int y;
  node(int y, int x):y(y), x(x){}
};

bool state;

vector<node> v;

bool check(int index, int num){
  // 判断行列是否用过
  int x = v[index].x;
  int y = v[index].y;
  for (int i = 0; i < 9; i++) {
    // 如果同行同列填入则返回false
    if (map[y][i] == num || map[i][x] == num) {
      return false;
    }

  }
  // 判断9个格子是否用过k
  int row = x / 3 * 3;
  int col = y / 3 * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3;j++) {
      if (map[col + i][row + j] == num) {
        return false;
      }
    }
  }

  return true;
}

void DFS(int index){
  if (index == v.size()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 8; j++) {
        printf("%d ", map[i][j]);
      }
      printf("%d\n", map[i][8]);
    }
    // 表示已经打印了
    state = 1;
    return;
  }else{
    for (int i = 1; i < 10; i++) {
      // printf("%\n", check(index, i));
      if(check(index, i) && state == 0){

        map[v[index].y][v[index].x] =  i;
        DFS(index + 1);
        map[v[index].y][v[index].x] =  0;
      }
    }
  }
  return;
}

int main() {
  freopen("in.txt", "r", stdin);

  char c;
  int Case = 0;

  while (cin >> c) {

    memset(map, 0, sizeof(map));
    v.clear();

    if (c != '?') {
      map[0][0] = c - '0';
    }else{
      map[0][0] = 0;
      v.push_back(node(0, 0));
    }
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (0 == i && 0 == j) {
          continue;
        }
        cin >> c;
        if (c != '?') {
          map[i][j] = c - '0';
        }else{
          map[i][j] = 0;
          v.push_back(node(i, j));
        }
      }
    }
    if (0 != Case) {
      printf("\n");
    }
    state = 0;
    DFS(0);
    Case++;
  }

  return 0;
}

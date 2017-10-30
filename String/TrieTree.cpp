#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

/*
* 作用：存储多个字符串，并可以自动按照字典序排好
* 实现步骤：
* 1、新建根节点
* 2、读入字符串，
* 3、进行操作
*/

string s;

struct Node{
    int num;
    int ch[26];
    Node():num(0){
      memset(ch, -1, sizeof(ch));
    }
};

vector<Node> nodes;

int root;

int newNode(){
  nodes.push_back(Node());
  int index = nodes.size() - 1;
  return index;
}

void insert() {
  nodes[0].num++;
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    int t = s[i] - 'a';

    if (nodes[index].ch[t] == -1) {
      int flag = newNode();
      nodes[index].ch[t] = flag;
    }

    index = nodes[index].ch[t];
    nodes[index].num++;
  }
}

int getAns(){

  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    int t = s[i] - 'a';

    if (nodes[index].ch[t] == -1) {
      return 0;
    }
    index = nodes[index].ch[t];
  }
  return nodes[index].num;
}

int main() {

  nodes.clear();
  root = newNode();

  while (getline(cin, s, '\n')) {
    if (s == "") {
      break;
    }else{
      insert();
    }
  }

  while (cin >> s) {
    printf("%d\n", getAns());
  }

  return 0;
}

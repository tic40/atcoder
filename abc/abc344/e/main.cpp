#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

struct Node {
  int pre, nxt;
  Node(int pre = -1, int nxt = -1): pre(pre), nxt(nxt) {}
};

// 双方向リスト
struct List {
  unordered_map<int,Node> nodes;
  int head, tail;
  List(): head(-INF), tail(INF) {
    nodes[head] = Node(-1,tail);
    nodes[tail] = Node(head,-1);
  }
  // リストから値 x の要素を削除する
  void erase(int x) {
    Node a = nodes[x];
    nodes[a.pre].nxt = a.nxt;
    nodes[a.nxt].pre = a.pre;
    nodes.erase(x);
  }
  // リストの値 x の要素の直後に y を追加する
  void add(int x, int y) {
    int z = nodes[x].nxt;
    nodes[x].nxt = y;
    nodes[z].pre = y;
    nodes[y] = Node(x,z);
  }
  void print() {
    int i = nodes[head].nxt;
    while(i != tail) {
      cout << i << " ";
      i = nodes[i].nxt;
    }
    cout << endl;
  }
};

int main() {
  int n; cin >> n;
  List d;
  {
    int now = d.head;
    REP(i,n) {
      int a; cin >> a;
      d.add(now,a);
      now = a;
    }
  }

  int q; cin >> q;
  REP(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int x,y; cin >> x >> y;
      d.add(x,y);
    } else {
      int x; cin >> x;
      d.erase(x);
    }
  }

  d.print();
  return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

struct Node {
  int v, p;
  Node(int v, int p): v(v), p(p) {}
};

int main() {
  int q; cin >> q;
  vector<Node> vec;
  vec.emplace_back(-1,0);
  map<int,int> mp;
  int v = 0;

  string s; int x;
  REP(_, q) {
    cin >> s;
    if (s == "ADD") {
      cin >> x;
      vec.emplace_back(x,v);
      v = vec.size() - 1;
    } else if (s == "DELETE") {
      v = vec[v].p;
    } else if (s == "SAVE") {
      cin >> x;
      mp[x] = v;
    } else {
      cin >> x;
      v = mp[x];
    }
    cout << vec[v].v << " ";
  }
  cout << endl;
  return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

struct Node {
  int v, p;
  Node(int v, int p) : v(v),p(p) {}
};

int main() {
  int q; cin >> q;
  vector<Node> vc;
  vc.emplace_back(-1,0);
  int v = 0;
  map<int,int> mp;

  string s; int x;
  REP(_, q) {
    cin >> s;
    if (s == "ADD") {
      cin >> x;
      vc.emplace_back(x,v);
      v = vc.size() - 1;
    } else if (s == "DELETE") {
      v = vc[v].p;
    } else if (s == "SAVE") {
      cin >> x;
      mp[x] = v;
    } else {
      cin >> x;
      v = mp[x];
    }
    cout << vc[v].v << " ";
  }
  return 0;
}
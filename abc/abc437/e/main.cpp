#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct Node {
  map<int,int> next;
  vector<int> ids;
};

int main() {
  int n; cin >> n;
  vector<Node> trie(1);
  vector<int> pos(n+1);
  for(int i = 1; i <= n; i++) {
    int x,y; cin >> x >> y;
    int now = pos[x];
    if (trie[now].next.count(y) == 0) {
      trie[now].next[y] = trie.size();
      trie.push_back(Node());
    }

    int to = trie[now].next[y];
    trie[to].ids.push_back(i);
    pos[i] = to;
  }

  vector<int> ans;
  auto dfs = [&](auto dfs, int i) -> void {
    for(auto v: trie[i].ids) ans.push_back(v);
    for(auto [_,v]: trie[i].next) dfs(dfs,v);
  };
  dfs(dfs,0);
  for(auto v: ans) cout << v << " ";

  return 0;
}

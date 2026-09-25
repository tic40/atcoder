#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct Node {
  map<int,int> next;
  vector<int> ids;
};

int main() {
  int n; cin >> n;
  vector<Node> trie(1);
  vector<int> pos(n+1);

  pos[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;

    int v = pos[x];
    if (!trie[v].next.count(y)) {
      trie[v].next[y] = trie.size();
      trie.push_back(Node{});
    }

    int to = trie[v].next[y];
    pos[i] = to;
    trie[to].ids.push_back(i);
  }

  vector<int> ans;
  auto dfs = [&](auto dfs, int v) -> void {
    for (int id: trie[v].ids) ans.push_back(id);
    for (auto [y,to]: trie[v].next) dfs(dfs, to);
  };
  dfs(dfs, 0);

  REP(i,n) cout << ans[i] << " ";
  return 0;
}

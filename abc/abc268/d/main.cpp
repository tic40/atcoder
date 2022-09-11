#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,m;
vector<string> s(8);
vector<int> b;
vector<string> vs;

void dfs(int i, string now, int left) {
  if (i == n) {
    if (now.size() >= 3) vs.push_back(now);
    return;
  }

  REP(j,left) {
    string under(j+1, '_');
    dfs(i+1, now + under + s[b[i]], left - (j+1));
  }

  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) cin >> s[i];
  unordered_set<string> st;
  REP(i,m) {
    string t; cin >> t;
    st.insert(t);
  }

  int total = 0;
  REP(i,n) total += s[i].size();

  b.resize(n);
  REP(i,n) b[i] = i;
  do {
    dfs(1, s[b[0]], 16 - total);
    for(auto v: vs) {
      if (!st.count(v)) { cout << v << endl; return 0; }
    }
    vs = vector<string>();
  } while (next_permutation(b.begin(), b.end()));

  cout << -1 << endl;
  return 0;
}
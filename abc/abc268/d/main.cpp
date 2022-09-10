#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,m;
vector<string> s(8);
vector<string> vs;
vector<int> b;

// left := underscoreを入れられる数
void dfs(int i, string now, int left) {
  if (now.size() > 16) return;
  if (i == n) {
    if (now.size() >= 3) vs.push_back(now);
    return;
  }

  string und = "_";
  REP(j, left) {
    string ns = now + und + s[b[i]];
    dfs(i+1, ns, left - (j+1));
    und += "_";
  }
  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) cin >> s[i];
  set<string> st;
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
  } while (next_permutation(b.begin(), b.end()));

  for(string v: vs) {
    if (!st.count(v)) { cout << v << endl; return 0; }
  }

  cout << -1 << endl;
  return 0;
}
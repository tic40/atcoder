#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<int> a;

void output(vector<int> b, vector<int> c) {
  cout << "Yes" << endl;
  cout << b.size() << " ";
  for(int v: b) cout << v << " ";
  cout << endl;
  cout << c.size() << " ";
  for(int v: c) cout << v << " ";
  cout << endl;
}

void solve() {
  REP(i,n) a[i] %= 200;

  vector<vector<int>> memo(200);
  // bit全探索
  for (int bit = 1; bit < 1<<min(8,n); bit++) {
    int sum = 0;
    vector<int> s;
    REP(i,n) {
      if (bit>>i & 1) {
        sum += a[i];
        sum %= 200;
        s.push_back(i+1);
      }
    }

    if (memo[sum].size() == 0) {
      memo[sum] = s;
    } else {
      output(memo[sum], s);
      return;
    }
  }

  cout << "No" << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  string s;
  int k;
  cin >> s >> k;
  REP(i, k % s.size()) {
    int f = s.front();
    s.erase(0, 1);
    s.push_back(f);
  }
  cout << s << "\n";
}
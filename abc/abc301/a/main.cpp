#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s; cin >> n >> s;
  vector<int> cnt(2);
  for(auto c: s) {
    int now = c == 'T' ? 0 : 1;
    cnt[now]++;
    if (cnt[now] >= (n+1)/2) { cout << c << endl; break; }
  }
  return 0;
}
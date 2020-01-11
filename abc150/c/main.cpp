#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> p(n),q(n);
  REP(i,n) cin >> p[i]; REP(i,n) cin >> q[i];
  vector<int> a(n);
  REP(i,n) a[i] = i+1;

  map<vector<int>, int> mp;
  do {
    mp[a] = mp.size();
  } while (next_permutation(a.begin(), a.end()));

  cout << abs(mp[p]-mp[q]) << endl;
}
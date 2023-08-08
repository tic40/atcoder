#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> a(n);

  auto f = [&](vector<int> x) {
    REP(i,k) x[i]++;
    cout << "?";
    REP(i,k) cout << " " << x[i];
    cout << endl;
    int res;
    cin >> res;
    return res;
  };

  vector<int> b(k+1);
  int t = 0;
  REP(i,k+1) {
    vector<int> x;
    REP(j,k+1) if (i != j) x.push_back(j);
    b[i] = f(x);
    // t += b[i]; t %= 2;
    t ^= b[i];
  }
  REP(i,k+1) a[i] = b[i]^t;

  t = 0;
  REP(i,k-1) t ^= a[i];
  for(int i = k+1; i < n; i++) {
    vector<int> x;
    REP(j,k-1) x.push_back(j);
    x.push_back(i);
    a[i] = t ^ f(x);
  }

  cout << "!";
  REP(i,n) cout << " " << a[i];
  cout << endl;
  return 0;
}
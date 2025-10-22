#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n+1);
  a[0] = a[1] = 1;

  auto t = [](int x) {
    int res = 0;
    while(x) res+=x%10, x/=10;
    return res;
  };

  auto f = [&](auto f, int i) {
    if (a[i] > 0) return a[i];
    int pa = f(f,i-1);
    return a[i] = pa + t(pa);
  };

  cout << f(f,n) << endl;
  return 0;
}
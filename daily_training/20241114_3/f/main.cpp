#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  vector<int> c(9);
  REP(i,9) cin >> c[i];

  int tot = 0, cnt = 0;
  vector<int> b(9);
  iota(b.begin(),b.end(),0);
  do {
    auto f = [&](int i, int j, int k) {
      vector<P> d;
      d.emplace_back(b[i],c[i]);
      d.emplace_back(b[j],c[j]);
      d.emplace_back(b[k],c[k]);
      sort(d.begin(),d.end());

      return d[0].second != d[1].second;
    };
    int ok = 1;

    ok &= f(0,1,2);
    ok &= f(3,4,5);
    ok &= f(6,7,8);
    ok &= f(0,3,6);
    ok &= f(1,4,7);
    ok &= f(2,5,8);
    ok &= f(0,4,8);
    ok &= f(6,4,2);

    if (ok) cnt++;
    tot++;
  } while(next_permutation(b.begin(),b.end()));
  printf("%.10f\n", (double)cnt/tot);
  return 0;
}
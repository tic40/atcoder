#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int m = max(max(a,b),c);
  if ((3*m)%2 != (a+b+c)%2) m++;

  COUT( (3*m - (a+b+c)) / 2);

  /*
  int a[3]; REP(i,3) cin >> a[i];
  int ans = 0;
  auto sorta = [&](){ sort(a, a+3); };
  auto same = [&](){ return a[0] == a[1] && a[0] == a[2]; };
  sorta();
  while(1) {
    if (same()) break;
    int add = (a[2] - a[0]) / 2;
    if (add > 0) {
      a[0] += add*2;
      ans+=add;
    } else {
      a[2]--;
      ans++;
    }
    sorta();
  }
  COUT(ans);
  */
  return 0;
}

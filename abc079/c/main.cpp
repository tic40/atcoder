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
  int n; cin >> n;
  vector<int> a(4, 0);
  int i = 0;
  while(n > 0) {
    a[i++] = n%10;
    n/=10;
  }
  reverse(a.begin(),a.end());

  REP(bit, 1<<3) {
    string t;
    int res = a[0];
    REP(i,3) {
      if (bit >> i & 1) { t.push_back('+'); res+=a[i+1]; }
      else { t.push_back('-'); res-=a[i+1]; }
    }
    if (res == 7) {
      REP(i,4) {
        cout << a[i];
        if (i < 3) cout << t[i];
        else COUT("=7");
      }
      return 0;
    }
  }
  return 0;
}

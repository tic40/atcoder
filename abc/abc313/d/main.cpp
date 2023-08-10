#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> ans(n);

  auto ask = [&](vector<int> &x) {
    cout << "?";
    REP(i,k) cout << " " << x[i]+1;
    cout << endl;
    int res; cin >> res;
    return res;
  };

  vector<int> b(k+1); // b[i] := i を含まない k 個の xor 和の値
  int t = 0; // k+1 個それぞれの xor 和を合計した値
  REP(i,k+1) {
    vector<int> x;
    REP(j,k+1) if (i != j) x.push_back(j);
    b[i] = ask(x);
    // ここは t += b[i]; t %= 2; でもいいが、mod 2 なので xor を取っても同じ
    t ^= b[i];
  }
  REP(i,k+1) ans[i] = b[i]^t;

  t = 0; // ans[0],ans[1]... ans[k-2] の xor 和
  REP(i,k-1) t ^= ans[i];
  vector<int> x;
  REP(j,k-1) x.push_back(j);
  for(int i = k+1; i < n; i++) {
    x.push_back(i);
    ans[i] = t ^ ask(x);
    x.pop_back();
  }

  cout << "!";
  for(auto v: ans) cout << " " << v;
  cout << endl;
  return 0;
}
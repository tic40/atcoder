#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
string s,sright, sleft;

void ask(int p) {
  cout << p << endl;
  cin >> s;
}

bool check(string sleft, string sright, int left, int right) {
  if (sleft == sright) return (right - left) % 2 == 1;
  else return (right - left) % 2 == 0;
}

bool hit() { return s == "Vacant"; }

void solve() {
  int ok = n/2, ng = 0;

  ask(ng);
  if (hit()) return;
  sleft = s;

  ask(ok);
  if (hit()) return;
  sright = s;

  if (!check(sleft, sright, ng, ok)) {
    swap(sleft, sright);
    ng = ok;
    ok = n;
  }

  while(abs(ok-ng) > 1) {
    int mid = (ok+ng)/2;
    ask(mid);
    if (hit()) return;

    if (check(sleft, s, ng, mid)) {
      sright = s;
      ok = mid;
    } else {
      sleft = s;
      ng = mid;
    }
  }

  return;
}

int main() {
  cin >> n;
  solve();
  return 0;
}
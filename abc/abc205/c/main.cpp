#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

ll a,b,c;

void solve() {
  if (a == b) {
    cout << "=" << endl;
    return;
  }

  // どちらも正
  if (0 <= a && 0 <= b) {
    if (a < b) {
      cout << "<" << endl;
    } else {
      cout << ">" << endl;
    }
    return;
  }

  // どちらも負
  if (a < 0 && b < 0) {
    // 指数が偶数
    if (c % 2 == 0) {
      if (abs(a) < abs(b)) {
        cout << "<" << endl;
      } else {
        cout << ">" << endl;
      }
    } else {
      if (abs(a) < abs(b)) {
        cout << ">" << endl;
      } else {
        cout << "<" << endl;
      }
    }
    return;
  }

  // Aだけ負
  if (a < 0) {
    // 指数が偶数
    if (c % 2 == 0) {
      if (abs(a) == abs(b)) {
        cout << "=" << endl;
      } else if (abs(a) < abs(b)) {
        cout << "<" << endl;
      } else {
        cout << ">" << endl;
      }
    } else {
      cout << "<" << endl;
    }
    return;
  }

  // Bだけ負
  if (b < 0) {
    // 指数が偶数
    if (c % 2 == 0) {
      if (abs(a) == abs(b)) {
        cout << "=" << endl;
      } else if (abs(a) < abs(b)) {
        cout << "<" << endl;
      } else {
        cout << ">" << endl;
      }
    } else {
      cout << ">" << endl;
    }
    return;
  }

  return;
}

int main() {
  cin >> a >> b >> c;

  solve();
  return 0;
}
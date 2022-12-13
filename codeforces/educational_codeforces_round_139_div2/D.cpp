#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;  // int vec
typedef vector<vi> vvi;  // int vec vec
typedef vector<pii> vpi; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type, vector<type>, greater<type>>
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define nl "\n"
#define in(t) while (t--)

void solve();

int main() { solve(); }

// snippets
// hash: hash used for pairs used in unordered maps
// comp: comparator of pairs used for priority queues
// _ncrmod: choose function for big numbers using modulo
// _ncr: choose function
// _nprmod: permutation function for big numbers using modulo
// _npr: permutation function
// sieve: sieve of eratosthenes

void solve() {
  ios int t;
  cin >> t;
  vector<bool> seen(4e3 + 1, false);
  vector<int> primes;
  for (int i = 2; i < seen.size(); ++i) {
    if (!seen[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < seen.size(); j += i)
        seen[j] = true;
    }
  }
  in(t) {
    int x, y;
    cin >> x >> y;
    if (abs(x - y) == 1) {
      cout << -1 << nl;
    } else if (__gcd(x, y) > 1) {
      cout << 0 << nl;
    } else {
      if (x < y) {
        swap(x, y);
      }
      int dif = x - y;
      int cur;
      int ans = imax;
      forn(i, primes.size()) {
        if (dif % primes[i] == 0) {
          while (dif % primes[i] == 0) {
            dif /= primes[i];
          }
          int num = primes[i] - (y % primes[i]);
          ans = min(num, ans);
        }
      }
      if (dif > 1) {
        int num = dif - (y % dif);
        ans = min(num, ans);
      }
      cout << ans << nl;
    }
  }
}

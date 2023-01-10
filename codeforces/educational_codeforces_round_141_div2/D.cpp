#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;  // int vec
typedef vector<vi> vvi;  // int vec vec
typedef vector<pii> vpi; // int int pair vec

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
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

const double pi = acos(-1);
const int maxn = 2e5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

// snippets
// hash: hash used for pairs used in unordered maps
// comp: comparator of pairs used for priority queues
// _ncrmod: choose function for big numbers using modulo
// _ncr: choose function
// _nprmod: permutation function for big numbers using modulo
// _npr: permutation function
// sieve: sieve of eratosthenes

int main() {
  ios cout << setprecision(20) << fixed;
  ll n;
  cin >> n;
  vector<ll> a(n);
  forn(i, n) cin >> a[i];
  ll mod = 998244353;
  ll ans = 0;
  vector<ll> counter(2e5, 0);
  counter[1e5 + a[1]] = 1;
  for (ll i = 1; i < n - 1; ++i) {
    vector<ll> cur(2e5, 0);
    forn(j, maxn) {
      if (counter[j] == 0)
        continue;
      ll tmp = j - 1e5;
      cur[1e5 + a[i + 1] - tmp] += counter[j];
      cur[1e5 + a[i + 1] - tmp] %= mod;
      if (tmp) {
        cur[1e5 + a[i + 1] + tmp] += counter[j];
        cur[1e5 + a[i + 1] + tmp] %= mod;
      }
    }
    swap(cur, counter);
  }
  for (ll num : counter) {
    ans += num;
    ans %= mod;
  }
  cout << ans << nl;
}

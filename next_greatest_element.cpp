//https://www.codechef.com/problems/GCDQ
#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
//if RE then remove above 3 lines
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define vt vector
#define pb push_back
#define mp make_pair
#define pob pop_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto x:a)
#define sz(x) (ll)(x).size()
const ll M=(ll)(1e9)+7;
ll N=(ll)(1e5)+10;

void solve(){
   ll n,i,q;
   cin>>n>>q;
   ll a[n+10];
   ll forward[N],backward[N];
   forward[0]=backward[n+1]=0;
   for(i=1;i<=n;i++){
      cin>>a[i];
      forward[i]=__gcd(forward[i-1],a[i]);
   }
   for(i=n;i>=1;i--){
      backward[i]=__gcd(backward[i+1],a[i]);
   }
   while(q--){
      ll l,r;
      cin>>l>>r;
      cout<<__gcd(forward[l-1],backward[r+1]);
      cout<<"\n";
   }
}
int main(){
    // auto start = high_resolution_clock::now();
    // cout<<fixed<<setprecision(2);
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll t;
    // ll i=1;
    cin>>t;
    while(t--){
    // cout<<"Case #"<<i<<": ";
    solve();
    // cout<<"\n";
    // i++;
    }
    //  auto stop = high_resolution_clock::now();
    //   auto duration = duration_cast<microseconds>(stop - start);cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl;
    return 0;
}
/*INPUT
4
4 5 2 25
*/
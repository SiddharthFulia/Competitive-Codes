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

ll large_exponential_iterative(ll a,ll b,ll m){
    //a^b^c
    //When b>>10^18 here(b=b^c) to represent in form of a^b
   ll ans=1;
   while(b){
      if(b&1){
         ans=ans*a%m;
      }
      a=a*a%m;
      b>>=1;//right shift
   }
   return ans;
}

void solve(){
   ll a,b,c;
   cin>>a>>b>>c;
   cout<<large_exponential_iterative(a,large_exponential_iterative(b,c,M-1),M);//replace M-1 with ETF(Euler's totient function) in case M is non-prime
   cout<<"\n";
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
1
50 64 32
*/
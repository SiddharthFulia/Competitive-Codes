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
#define ml multiset
#define pb push_back
#define mp make_pair
#define pob pop_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto &x:a)
#define sz(x) (ll)(x).size()
// const ll M=(ll)(1e9)+7;
const ll N=(ll)(1e5)+10;
ll n,i;
vt<bool> isPrime(N,1);
vt<ll> lp(N,0),hp(N,0);//lp-->lowest prime,hp-->highest prime
void seive(){
  isPrime[0]=isPrime[1]=false;//set 0 and 1 to false
  ll i,j;
  for(i=2;i<N;i++){
    if(isPrime[i]){
      lp[i]=hp[i]=i;//set lowest and highest prime of prime to itself
      for(j=2*i;j<N;j+=i){
        isPrime[j]=false;
        hp[j]=i;
        if(lp[j]==0){
          lp[j]=i;
        }
      }
    }
  }
}

vt<ll> prime_factors_sieve(ll x,vt<ll> prime_factors){
  while(x>1){
    ll prime_number=hp[x];
    while(x%prime_number==0){
      x/=prime_number;
      prime_factors.pb(prime_number);
    }
   }
   return prime_factors;
}

void solve(){
   seive();
  //  for(i=0;i<=n;i++){
  //   cout<<i<<" "<<isPrime[i];
  //   cout<<"\n";
  //  }
  // for(i=1;i<=n;i++){
  //   cout<<lp[i]<<" "<<hp[i]<<"\n";
  // }
   cin>>n;
   vt<ll> prime_factors;
   prime_factors=prime_factors_sieve(n,prime_factors);
   each(prime_factor,prime_factors){
    cout<<prime_factor<<" ";
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
    ll t=1;
    // ll i=1;
    // cin>>t;
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
100 
*/
//https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
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
const ll N=(ll)(2e5)+10;
ll hsh[N];//keep count of numbers in array
ll multiple_count[N];
void solve(){
   ll n,i,j,q;
   cin>>n;
   ll a[n];
   for(i=0;i<n;i++){
    cin>>a[i];
    hsh[a[i]]++;
   }
   //sieve
   for(i=1;i<N;i++){
    for(j=i;j<N;j+=i){
      multiple_count[i]+=hsh[j];
    }
   }
   cin>>q;
   while(q--){
    ll x,y;
    cin>>x>>y;
    ll lcm=x*y/__gcd(x,y);
    ll ans=multiple_count[x]+multiple_count[y];
    if(lcm<N){
      ans-=multiple_count[lcm];
    }
    cout<<ans;
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
6
2 3 5 7 4 9
2
4 5
3 7
*/
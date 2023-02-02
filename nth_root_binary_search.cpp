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
// const ll N=(ll)(1e5)+10;

ld eps=1e-7;//precision till 6 digits

ld multiply(ld mid,ll n){
  ld ans=1;
  while(n--){
    ans*=mid;
  }
  return ans;
}

void solve(){
   ld x;//to find root of x
   ll n,i;
   cin>>x>>n;//nth root
   ld lo=1,hi=x,mid;
   while(hi-lo>eps){
    mid=(hi+lo)/2;
    if(multiply(mid,n)<x){
      lo=mid;
    }
    else hi=mid;
   }
   cout<<setprecision(10)<<lo<<"\n"<<hi<<"\n";
   cout<<pow(x,1.0/n);//inbuilt function to find nth root
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
3
1 2 3
*/
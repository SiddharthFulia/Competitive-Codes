//https://www.spoj.com/problems/AGGRCOW/
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
ll positions[N];

bool can_place_cows(ll mid,ll cows,ll n){
  ll i,posi=-1;//inital position is -1 as there are no cows
  for(i=0;i<n;i++){
    if(cows==0) break;
    if(positions[i]-posi>=mid||posi==-1){
      cows--;
      posi=positions[i];
    }
  }
  return cows==0;
}

void solve(){
   ll n,i,cows;
   cin>>n>>cows;
   for(i=0;i<n;i++){
    cin>>positions[i];
   }
   sort(positions,positions+n);
   ll lo=0,hi=1e9,mid;
   while(hi-lo>1){
    mid=(hi+lo)/2;
    //predicate function
    //T T T T T T F F F F F F F
    if(can_place_cows(mid,cows,n)){
      lo=mid;
    }
    else hi=mid-1;
   }
   if(can_place_cows(hi,cows,n)){
    cout<<hi;
   }
   else cout<<lo;
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
5 3
1
2
8
4
9
*/
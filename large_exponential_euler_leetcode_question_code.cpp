//https://leetcode.com/problems/super-pow/
class Solution {
public:
long long int euler_totient_function(long long int z){
   long long int i=2;
   set <long long int> s;
   long long int y=z;
   while(y!=1){
      if(y%i==0){
         y/=i;
         s.insert(i);
         i=2;
      }
      else{
      i++;
      }
   }
   for (auto x:s){
      z=z*(x-1)/x;
   }
   return z;
}

long long int large_exponential_iterative(long long int a,long long int b,long long int m){
    //a^b^c
    //When b>>10^18 here(b=b^c) to represent in form of a^b
   long long int ans=1;
   while(b){
      if(b&1){
         ans=ans*a%m;
      }
      a=a*a%m;
      b>>=1;//right shift
   }
   return ans;
}
    int superPow(int a, vector<int>& b) {
        long long int n=size(b),m=1337;
        long long int m1=euler_totient_function(m);
        long long int x=0;
        for(long long int i=n-1;i>=0;i--){
            x=(x+b[i]*large_exponential_iterative(10,n-1-i,m1))%m1;
        }
        x=(int)(large_exponential_iterative(a,x,m));
        return x;
    }
};
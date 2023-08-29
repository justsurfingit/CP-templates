 /*Author: justsurfing
Go hard or go home   
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define pb push_back
#define mod 1000000007 
#define inf 100000000000000000
#define CHAR 256
#define all(x) x.begin(), x.end()
#define limit 100005
#define loop(i, s, l, j) for(int i = s; i < l; i += j)
#define N  200005
ll fact[N + 1];
ll inv[N + 1];
ll invFact[N + 1];
bool isComputed = false;
void compute() {
    inv[0] = inv[1] = 1;

    for (int i = 2; i <= N; i++) {
        inv[i] = (inv[mod % i] * (mod - mod / i)) % mod;
    }

    invFact[0] = invFact[1] = 1;
    for (int i = 2; i <= N; i++) {
        invFact[i] = (invFact[i - 1] * inv[i]) % mod;
    }

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    isComputed = true;
}
ll ncr(ll n, ll k) {
    if (!isComputed) {
        printf("Call compute function, you idiot");
    }
    else {
        return (((fact[n] * invFact[k]) % mod) * invFact[n - k]) % mod;
    }
    return -1;
}
ll power( int x,int y)
{
    ll temp=x;
    ll result = 1;
    while (y > 0) {
      if((y&1)==1) // y is odd
      {
        result=(result*temp)%mod;
      }
      temp=(temp*temp)%mod;
      y=y>>1; // y=y/2;
    }
    return result%mod;
}
void SieveOfEratosthenes(int n,vector<int>&get)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
       
        if (prime[p] == true) {
         
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            // cout << p << " ";
            get.pb(p);
}
ll segment[4*N],Lazy[4*N];

void build(vector<ll>&arr,int low,int high,int ind)
{
  if(high==low)
  {
    //termination condition
    segment[ind]=arr[low];
    // segment[ind].second=1;
    return;
  }
  //got it 
  int mid=(low+high)/2;
  build(arr,low,mid,2*ind+1);
  build(arr,mid+1,high,2*ind+2);
  segment[ind]=segment[2*ind+1]+segment[2*ind+2];
}
void build(vector<ll>&arr)
{
  build(arr,0,arr.size()-1,0);
}
ll query(int l,int r,int low,int high,int ind)
{
 //we have to handle three cases here
 if(low>r or high<l)return 0;
 if(low>=l and high<=r)return segment[ind];
 //we have to explore both paths and get the answer
 int mid=(low+high)/2;
 ll left=query(l,r,low,mid,2*ind+1);
 ll right=query(l,r,mid+1,high,2*ind+2);
 // return min(left,right;
 return left+right;

// return p;
}
ll  query(int l,int r,int n)
{
  return query(l,r,0,n-1,0);
}
void update(vector<ll>&arr,int in,ll val,int low,int high,int ind)
{
  int mid=(low+high)/2;
  if(low==high)
  {
    //we got ther4e
    arr[in]=val;
    segment[ind]=arr[in];
    // segment[ind].second=1;
    return;
  }
  
  if(mid>=in)
  {
    //left side traversal
    update(arr,in,val,low,mid,2*ind+1);
  }
  else update(arr,in,val,mid+1,high,2*ind+2);

   segment[ind]=segment[2*ind+1]+segment[2*ind+2];

}
void update(vector<ll>&arr,int in,ll val)
{
  update(arr,in,val,0,arr.size()-1,0);
}
void rangeupdate(int tidx, int lo, int hi, int L, int R, int val){

	// Complete any pending updates before entering this node
	if(Lazy[tidx]!=0){
		segment[tidx] = (hi-lo+1)*Lazy[tidx];
		if(lo!=hi){
			Lazy[2*tidx+1] += Lazy[tidx];
			Lazy[2*tidx+2] += Lazy[tidx];
		}
		Lazy[tidx] = 0;
	}
	
	// The Range which we are currently in : [lo, hi]
	// The Range we have to update for : [L, R]

	// Outside Range
	if(R<lo||L>hi) return;

	// In Range
	if(L<=lo&&hi<=R){
		// Update the Tree's value lazily, and then add update to be done for future to children.
		segment[tidx] += (hi-lo+1)*val;
		if(lo!=hi){
			Lazy[2*tidx+1] += Lazy[tidx];
			Lazy[2*tidx+2] += Lazy[tidx];
		}
		return;
	}

	// Parital Overlap (Go to Left and Right)

	int mid = (lo+hi)/2;
	rangeupdate(2*tidx+1, lo, mid, L, R, val);
	rangeupdate(2*tidx+2, mid+1, hi, L, R, val);

	// Update the values once children are updated
	segment[tidx] = segment[2*tidx+1] + segment[2*tidx+1];

}
int main() {
   /*Uncommment for the sieve */
    //  vector<int>get;
    //     SieveOfEratosthenes(1000005,get);
    // compute();
    //uncomment this for calc nCr
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t,n;
    cin>>t;
    // 1. brute force | 2. two pointers | 3. Prefix sum | 4. Binary search 
    // 5. DSA | 6. Graphs | 7. DP
    // constructive fucks //string
    while(t--)
    {
        // int mod=1e9+7;
        cin>>n;
       
       
    }
     return 0;
}
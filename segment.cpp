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
//change update is for changing the values from l to r to a given value
void changeupdate(int tidx, int lo, int hi, int l, int r, ll k) {

    // Complete any pending updates before entering this node
    if (Lazy[tidx] != 0) {
        segment[tidx] = (hi - lo + 1) * Lazy[tidx];
        if (lo != hi) {
            Lazy[2 * tidx + 1] += Lazy[tidx];
            Lazy[2 * tidx + 2] += Lazy[tidx];
        }
        Lazy[tidx] = 0;
    }

    // The Range which we are currently in: [lo, hi]
    // The Range we have to update for: [l, r]

    // Outside Range
    if (r < lo || l > hi) return;

    // In Range
    if (l <= lo && hi <= r) {
        // Set the entire range to value k
        segment[tidx] = (hi - lo + 1) * k;
        if (lo != hi) {
            Lazy[2 * tidx + 1] = k;
            Lazy[2 * tidx + 2] = k;
        }
        return;
    }

    // Partial Overlap (Go to Left and Right)

    int mid = (lo + hi) / 2;
    rangeupdate(2 * tidx + 1, lo, mid, l, r, k);
    rangeupdate(2 * tidx + 2, mid + 1, hi, l, r, k);

    // Update the values once children are updated
    segment[tidx] = segment[2 * tidx + 1] + segment[2 * tidx + 2];
}
void rangeupdate(int tidx, int lo, int hi, int L, int R, ll val) {

    // Complete any pending updates before entering this node
    if (Lazy[tidx] != 0) {
        segment[tidx] = (hi - lo + 1) * Lazy[tidx];
        if (lo != hi) {
            Lazy[2 * tidx + 1] += Lazy[tidx];
            Lazy[2 * tidx + 2] += Lazy[tidx];
        }
        Lazy[tidx] = 0;
    }

    // The Range which we are currently in : [lo, hi]
    // The Range we have to update for : [L, R]

    // Outside Range
    if (R < lo || L > hi) return;

    // In Range
    if (L <= lo && hi <= R) {
        // Update the Tree's value lazily, and then add update to be done for future to children.
        segment[tidx] += (hi - lo + 1) * val;
        if (lo != hi) {
            Lazy[2 * tidx + 1] += Lazy[tidx];
            Lazy[2 * tidx + 2] += Lazy[tidx];
        }
        return;
    }

    // Parital Overlap (Go to Left and Right)

    int mid = (lo + hi) / 2;
    rangeupdate(2 * tidx + 1, lo, mid, L, R, val);
    rangeupdate(2 * tidx + 2, mid + 1, hi, L, R, val);

    // Update the values once children are updated
    segment[tidx] = segment[2 * tidx + 1] + segment[2 * tidx + 1];

}
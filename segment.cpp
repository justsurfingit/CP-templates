ll segment[4*N];

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
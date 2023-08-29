pair<ll,int>segment[4*N];
pair<ll,int> merge(pair<ll,int>&a,pair<ll,int>&b)
{
  if(a.first<b.first)return a;
  if(a.first>b.first)return b;
  pair<ll,int>p=a;
  p.second+=b.second;
  return p;
}
void build(vector<ll>&arr,int low,int high,int ind)
{
  if(high==low)
  {
    //termination condition
    segment[ind].first=arr[low];
    segment[ind].second=1;
    return;
  }
  //got it 
  int mid=(low+high)/2;
  build(arr,low,mid,2*ind+1);
  build(arr,mid+1,high,2*ind+2);
  segment[ind]=merge(segment[2*ind+1],segment[2*ind+2]);
}
void build(vector<ll>&arr)
{
  build(arr,0,arr.size()-1,0);
}
pair<ll,int> query(int l,int r,int low,int high,int ind)
{
 //we have to handle three cases here
 if(low>r or high<l)return {INT_MAX,0};
 if(low>=l and high<=r)return segment[ind];
 //we have to explore both paths and get the answer
 int mid=(low+high)/2;
pair<ll,int> left=query(l,r,low,mid,2*ind+1);
 pair<ll,int> right=query(l,r,mid+1,high,2*ind+2);
 // return min(left,right;
pair<ll,int>p=merge(left,right);
return p;
}
pair<ll,int> query(int l,int r,int n)
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
    segment[ind].first=arr[in];
    segment[ind].second=1;
    return;
  }
  
  if(mid>=in)
  {
    //left side traversal
    update(arr,in,val,low,mid,2*ind+1);
  }
  else update(arr,in,val,mid+1,high,2*ind+2);

   segment[ind]=merge(segment[2*ind+1],segment[2*ind+2]);

}
void update(vector<ll>&arr,int in,ll val)
{
  update(arr,in,val,0,arr.size()-1,0);
}
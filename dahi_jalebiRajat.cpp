#include<bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout <<">>"<<#x<<": "<<(x)<< endl;
#define DEBUG2(x,y) cout<<#x<<" :: "<<x<<"    "<<#y<<" :: "<<y<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define mem(x,val) memset((x),(val),sizeof(x))
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define ll long long int
#define LL long long int
#define pii pair<ll,ll>
const ll INF = 2e18;
ll M = 1000000007 ;
void function_1(ll n_,ll max_,ll min_,ll flag);
void function_2(ll n_,ll max_,ll min_,ll flag);
void function_16(ll n_,ll root_);
void function_23(int n_,int k);
int test_cases,flag_t=1;

FILE* fptr;

int main()
{
  remove("generated_test_cases.txt");

  cout<<"1) Normal Array\n2) Pair-Wise Distinct Array\n3) Permutation Array\n4) Ordered Array(Sorted/Unsorted)\n5) Array of Pairs\n6) 2D Matrix\n7) 2D Matrix Permutation\n";
  cout<<"8) Number String\n9) Particular String(with Desired Characters)\n10) String of Aphabets\n11) string of Special Characters\n12) Alphanumeric Strings\n13) 2D String\n";
  cout<<"14) Star Shaped Tree\n15) Normal Tree rooted at node\n16) Binary Tree\n17) Normal tree with edge weight\n 18) Normal Tree with Node Weight\n19) Graph through Adjacency Matrix\n";
  cout<<"20) Sparse Graph\n21) Undirected acyclic graph\n22) Random Graph\n23) Graph with given max degree\n24) Connected Graph\n";
  int option;
  ll n_,min_,max_,root_,degree;
  bool flag;
  cout<<"Enter Your option(1-24)\n";
  cin>>option;
  cout<<"Enter number of Test cases\n";
  cin>>test_cases;
  switch(option)
  {
    case 1:cout<<"Enter maximum size of array : ";
          cin>>n_;
          cout<<"upper bound of array elements : ";
          cin>>max_;
          cout<<"Lower bound of array Elements : ";
          cin>>min_;
          cout<<"Do you need float values";
          cin>>flag;
          function_1(n_,max_,min_,flag);
    case 2:cout<<"Enter maximum size of array : ";
          cin>>n_;
          cout<<"upper bound of array elements : ";
          cin>>max_;
          cout<<"Lower bound of array Elements : ";
          cin>>min_;
          cout<<"Do you need float values";
          cin>>flag;
          function_2(n_,max_,min_,flag);
    case 16:cout<<"Enter total numbers of nodes :";
            cin>>n_;
            cout<<"Enter the root node  :";
            cin>>root_;
            function_16(n_,root_);
    case 23:cout<<"Enter total numbers of node(<10000) :";
              cin>>n_;
              cout<<"Enter max Degree: ";
              cin>>degree;
              function_23(n_,degree);
          


  }







  return 0;
}






void generate_numbers_1(ll n, LL x, LL y,int flag) {
	LL mod = (y - x + 1);
	LL displace = x;

	for(int i=1; i<=n; ++i) {
		LL number = ((LL)rand() * rand()) % mod + displace;
		assert(number >= x && number <= y);
    double r = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    if(flag)
		printf("%lf", number*r);
    else
    printf("%lld", number);
		if (i < n) {
			printf(" ");
		}
	}
	printf("\n");
}
void function_1(ll n_,ll max_,ll min_,ll flag)
{
  fptr = freopen("generated_test_cases.txt", "a", stdout);
  if(flag_t==1)
    {
      cout<<test_cases<<endl;
      flag_t=0;
    }
  for(int t=1; t<=test_cases; ++t) {
		ll n = rand() % n_ + 1;
		printf("%lld\n", n);
		LL range_low = min_;
		LL range_high = max_;
		generate_numbers_1(n, range_low, range_high,flag);
	}
}
void function_2(ll n_,ll max_,ll min_,ll flag)
{
  fptr = freopen("generated_test_cases.txt", "a", stdout);
  cout<<test_cases<<endl;
  for(int i=1;i<=test_cases;i++)
  {
    ll n=rand()%n_+1;
    
  ll bucketmax_=max_/n;
  ll prev=min_;
    vector<ll> v;
  while(v.size()<=n)
  {
    ll curr=prev+rand()%bucketmax_+1;
    v.push_back(curr);
    prev=curr;
  }
  random_shuffle(v.begin(),v.end());
  cout<<n<<endl;
  for(int i=0;i<v.size();i++)
  cout<<v[i]<<" ";
  cout<<endl;
  }
}
void function_16(ll n_,ll root_)
{

  fptr = freopen("generated_test_cases.txt", "a", stdout);
  cout<<test_cases<<endl;
  for(int i=1;i<=test_cases;i++)
  {
    ll n=rand()%n_+1;
    ll degree[n+1]={0};
    
     unordered_set<ll> s;
    vector<ll> v;
  for(int j=1;j<=n;j++)
  {
    if(j!=root_)
    v.push_back(j);
  }
  s.insert(root_);
  random_shuffle(v.begin(),v.end());
  cout<<n-1<<endl;
  for(int j=0;j<v.size();j++)
  {
    
    ll ele=*(s.begin());
    cout<<ele<<" "<<v[j]<<endl;
    degree[ele]++;
    degree[v[j]]++;
    s.insert(v[j]);
    if(degree[ele]>=3)
    s.erase(ele);
  }
  }
}
void function_23(int n_,int k)
{
  fptr = freopen("generated_test_cases.txt", "a", stdout);
  cout<<test_cases<<endl;
  for(int i=1;i<=test_cases;i++)
  {
    vector<pair<int,int>> v;
    int n=rand()%n_+1;
    int deg[n+1];
    for(int j=1;j<=n;j++)
    deg[j]=k;
    for(int j=1;j<=n;j++)
    {
      if(deg[j]!=0)
      {
      int curdeg=rand()%deg[j]+1;
      int size=(n-j)/curdeg;
      int pre=j;
      while(curdeg--)
      {
        int ele=pre+rand()%size+1;
        if(deg[ele]>0)
        v.push_back(make_pair(j,ele));
        deg[ele]--;
       

      }
      }
    }
    cout<<v.size()<<endl;
    for(int j=0;j<v.size();j++)
    {
      cout<<v[j].first<<" "<<v[j].second<<endl;
    }

  }

}


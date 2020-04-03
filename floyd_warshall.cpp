#include <bits/stdc++.h>
using namespace std;




void print(vector<vector<int> >&arr)
{
	// for( int i=0;i<(int)arr.size();++i)
	for(auto x: arr)
	{
		// for(auto t: arr.at(i))
		for(auto t: x)
		{
			if(t==1000)
			{
				cout<<"INF"<<" ";
			}
			else
				cout<<t<<" ";
		}
		cout<<endl;
	}
}	


void floy_warshall(vector<vector<int> >&arr)
{
	for(int k=0;k<arr.size();++k)
	{
		for(int i=0;i<arr.size();++i)
		{
			for(int j=0;j<arr.at(i).size();++j)
			{
				assert(arr.at(i).size()==4);
				arr.at(i).at(j)=min(arr.at(i).at(j),(arr.at(i).at(k)+arr.at(k).at(j)));
				// arr[i][j]=min(arr[i][j],(arr[i][k]+arr[j][k]))
				// deb(arr.at(i).at(j));
			}
		}

	}
	print(arr);
}

int main()
{
	vector<vector<int> >arr;
	int m,n;

	cin>>m>>n;
	arr.resize(m);
	int temp;
	for(int i=0;i<m;++i)
	{
		arr.at(i).reserve(n);
		for(int j=0;j<n;++j)
		{
			cin>>temp;
			arr.at(i).push_back(temp);
		}
	}
	floy_warshall(arr);

	return 0;
}

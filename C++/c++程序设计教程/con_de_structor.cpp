#include <iostream>
using namespace std;

int n_test=0;

class test
{
public:
	test();
	~test();
};

test::test()
{
	cout<<"Constructing object "<<++n_test<<endl;
}

test::~test()
{
	cout<<"Destructing object "<<n_test--<<endl;
}

//constructor & destructor
int main()
{
	int t, n;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>n;
		test *t = new test[n];
		delete []t;
	}
	return 0;
}

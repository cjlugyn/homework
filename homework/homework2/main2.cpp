#include<iostream>
#include"list.h"
#include<cstdlib>
using namespace std;

int max(List<int>* p)
{
	stract max =0;
	stract S=0;
	if (p.data >max)
	{
		S =2*max; 
		max = p.data;
		
	}
	else {
		S = 2*p.data;
		max = p.data;
	}
	return S;
}



int main()
{
	List <int> height;
	height.init();
	int leight=0;
	int max = 0;
	List <int>* p = height.ListNodePosi<int> first() const;
	for(int i=0;i<10;i++){
		int e = rand()%105;
		height.ListNodePosi<int> insertAsPred( int const& e );
		p=p->succ;
		leight = max(p);
		if(max <leight)
		{
			max = leight;
		}
		else ;
	}
	cout << max <<endl;
	
}

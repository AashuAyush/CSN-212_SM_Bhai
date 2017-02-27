#include<bits/stdc++.h>
using namespace std;
int main()
{
	int width,height;              
	cin>>height>>width;
	int n;                        
	cin>>n;
	int i=0;
	char blocked[width+1][height+1];       
	for(int x = 0; x<=width; x++)
	{
		for(int y = 0; y<=height; y++)
		{
			blocked[x][y]='N';              
		}
	}
	while(i<n)
	{
		int e,f,g,h;                         
		cin>>e>>f>>g>>h;
		int w=min(e,g);                     
		int he=min(f,h);                    
		if(e!=g)                            
			blocked[w][he]='X';
		else
			blocked[w][he]='Y';   	       
		i++;
	}

	int ways[width+1][height+1];          
	for(int x = 0; x<=width; x++)         
	{
		for(int y = 0; y<=height; y++)
		{
			ways[x][y]=0;
		}
	}

	ways[0][0] = 1;                       
	for(int x = 0; x<=width; x++)
	{
		for(int y = 0; y<=height; y++)
		{
			if(blocked[x-1][y]!='X'&&x>=1)      
				ways[x][y]=ways[x][y]+ways[x-1][y];
			if(blocked[x][y-1]!='Y'&&y>=1)      
				ways[x][y]=ways[x][y]+ways[x][y-1];
		}
	}
	cout<<ways[width][height]<<endl;      
	return 0;
}     


#include<iostream>
#include<fstream>
#include<stdlib.h>

#define white 1
#define grey 2
#define black 3

using namespace std;

int adj[100][100];
int state[100];
int queue[100];
int front = -1 , rear = -1;

void DFS(int );

int i,no_ver,no_edge,origin,destin,cost;

int main ()
{
    fstream file;
    //int i,no_ver,no_edge,origin,destin,cost;
    char fname [100];

    cout<<"ENTER FILE NAME : ";
    cin>>fname;
    file.open(fname,ios::in);

    if (! file)
    {
        cout<<"\n ERROR FILE NOT FOUND ";
        exit(1);
    }

    file>>no_ver;
    file>>no_edge;

    //---------------MAKE GRAPH-------------------
    for(i=1; i<=no_edge; i++)
	{

		{
		        file>>origin;
		        file>>destin;
		        file>>cost;
			adj[origin][destin] = 1;
			adj[destin][origin] = 1;
		}
	}
    cout<<"\n GRAPH CREATED \n";
	//-----------------------------------------------

	//--------------BFS TRAVERSAL--------------------
    int ver;

	for(ver=0; ver<no_ver; ver++)
		state[ver] = white;

	cout<<"\n ENTER SOURCE FOR DFS : ";
	cin>>ver;
	DFS(ver);

	for(ver=0; ver<no_ver; ver++)
	{
		if(state[ver] == white)
			DFS(ver);
	}

    file.close();
    return 0;
}

void DFS(int ver)
{
    int i;
	cout<<ver<<" ";
	state[ver] = grey;
	for(i=0; i<no_ver; i++)
	{
		if(adj[ver][i] == 1 && state[i] == white)
				DFS(i);
	}
	state[ver] = black;
}


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

void BFS(int );
void enqueue(int);
int dequeue();
int empty_que();

int empty_que()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

int dequeue()
{
	int del_item;
	if(front == -1 || front > rear)
	{
		printf("UNDERFLOW\n");
		exit(1);
	}

	del_item = queue[front];
	front = front+1;
	return del_item;
}

void enqueue(int vertex)
{
	if(rear == 99)
		printf("OVERFLOW\n");
	else
	{
		if(front == -1)
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}

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

	cout<<"\n ENTER SOURCE FOR BFS : ";
	cin>>ver;
	//--------------------------------------------------
	BFS(ver);
    file.close();
    return 0;
}

void BFS(int ver)
{
    int i;

    enqueue(ver);

    state[ver]=grey;

    while(!empty_que())
	{
		ver = dequeue( );
		cout<<ver<<" ";
		state[ver] = black;
		i=0;
		while(i<no_ver)
		{
			/*Check for adjacent unvisited vertices */
			if(adj[ver][i] == 1 && state[i] == white)
			{
				enqueue(i);
				state[i] = grey;
			}
	                i++;
		}
	}
	printf("\n");
}


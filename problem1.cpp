// Author: Shaily Roy and Sajjad Ahmed


#include <bits/stdc++.h>

using namespace std;
#define vv  100


void isBipartite(int G[][vv],int V,int e)
{
//initializing two subgraph x,y
	map<int,int>x;
	map<int,int>y;

	int sizex=0;
	int sizey=0;

    // initially taking random nodes in x and y subgraph
	for(int i =1;i<=V;i+=2){
        x[i]=1;
        sizex++;
	}
	for(int i =2;i<=V;i+=2){
        y[i]=1;
        sizey++;
	}


    int xi=1;
    
    //traversing all the nodes
	while (xi<=V)
	{
		int u = xi;

        int c1=0,c2=0;

		//counting the edges of u in x and y graph
		for(int i =0;i<=V;i++){
            if(x[i]==1){
                if(G[u][x[i]]==1){
                c1++;
                }
                }
            if(y[i]==1){
                if(G[u][y[i]]==1){
                c2++;
                }
            }
		}


		//if x has more edges than y, moving u to y
		if(c1>c2){
           if(y[u]==0){
            y[u]=1;
            sizey++;
            x[u]=0;
            sizex--;
           }

		}
		else{
            if(x[u]==0){
            x[u]=1;
            sizex++;
            y[u]=0;
            sizey--;
           }


		}

        xi++;
        }

    //counting the number of edges
    int edge=0;
    vector< pair<int,int> >v;

    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
                if(x[j]==1&&y[i]==1){ //checking if this is a deleted node or not
                  if(G[i][j]==1){
                      v.push_back(make_pair(i,j));
                      edge++;
            }
        }
    }
    }



	cout<<"Number of Left element "<<sizex<<endl;
	cout<<"The left vertices are ";
	for(int i = 1;i<=V;i++){
	    if(x[i]==1)
	    cout<<i<<" ";
	}

	cout<<"\n Number of Right element "<<sizey<<endl;
    cout<<"The Right vertices are ";
	for(int i = 1;i<=V;i++){
        if(y[i]==1)
	    cout<<i<<" ";
	}

	cout<<"\n Number of Edges are "<<edge<<endl;

    for(int i=0;i<v.size();i++){
    	int k= v[i].first;
    	int p= v[i].second;
     	cout<<k<<" "<<p<<endl;
    }


	//return true;


}

// Driver program to test above function
int main()
{
	int v,e;
	cin>>v>>e;

	int G[vv][vv];

 	for(int i = 0; i<v+1; i++ ){
 			for(int j = 0; j<=v; j++ ){
 		          G[i][j]=0;

 			}
 	}


	for(int i = 0; i<e; i++ ){
		int a,b;
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;

	}
isBipartite(G,v,e);


	return 0;
}

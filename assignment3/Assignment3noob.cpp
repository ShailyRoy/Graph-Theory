#include <bits/stdc++.h>
using namespace std;
stack<int>st;
vector <int> v[20] ;   //Vector for maintaining adjacency list     bool visited[20]={0}; //Mark the node if visited
int V=20; // max vertex
int visited[20];
int k=0;
int last1 = 0,last2 = 0;

bool fly(int s,int in){
   //cout<<s<<endl;
if(s==V){
    int ct=st.size();

    if(ct==V)
        return 1;
    else{
        memset(visited,0,sizeof(visited));
        while(!st.empty())
           st.pop();

        k=k+1;
        if(k>=v[0].size()){
            return 0;
        }
        else
            return fly(0,k);
    }
}
if(in == v[s].size()){

        while(!st.empty()){
        int i=st.top();
          st.pop();
        int j = st.top();

        st.pop();
        visited[v[j][i]]=0;
        visited[j]=0;
        if(i+1<v[j].size()){
            return fly(j,i+1);
        }
        }
        return(V,0);
}
 if(visited[s]==1){
    return fly(s+1,0);
}
else if(visited[v[s][in]]==0&&visited[s]==0){
        visited[v[s][in]]=1;
        visited[s]=1;
        last1 = in;
        last2 = s;
        //storing the visited nodes in stack
        st.push(last2);
        st.push(last1);
        return fly(s+1,0);
}

else if(visited[v[s][in]]==1)
    return fly(s,in+1);

}




int main()
{
    string s,s1;

    while(getline(cin,s)){
        memset(visited,0,sizeof(visited));

        int e;
        cin>>V>>e;


        k=0;
        while(!st.empty())
            st.pop();

        memset(v,0,sizeof(v));
        for(int i =0;i<e;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }


        bool perfect = true;

        if(V%2==1||e<V/2)   //node has to be even and number of edges should be at least n/2
            perfect = false;

        else{

           perfect = fly(0,0);

        }
        cout<<s<<endl;
        if(perfect){
            cout<<"Bob\n" ;
        }

        else{
            cout<<"Alice\n";

        }
        getchar();
    }
    return 0;
}

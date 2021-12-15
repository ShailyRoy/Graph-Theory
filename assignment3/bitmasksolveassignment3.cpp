#include <iostream>
#include <vector>
using namespace std;
int V, E;
vector <int> G[100];

bool checkbit(int num, int i){
	//cout << (8 & (1<<i)) << endl;
	if((num & (1<<i)) == 0) return false;
	return true;
}

int setbit(int num, int i){
	return (num|(1<<i));
}

bool check(int state){
	//cout << state << endl;
	if(state == ((1<<V)-1)) return true;
	for(int i = 0; i < V; i++){
		if(checkbit(state,i) == false){
			bool f = false;
			for(int j = 0; j < G[i].size(); j++){
				int k = G[i][j];
				if(checkbit(state,k) == false){
					//cout << i+1 << " -- " << k+1 << endl;
					bool ret = check(setbit(setbit(state,i),k));
					if(ret == true){
						f= true;
						return true;
					}
				}
			}
			if(f == false) return false;
		}
	}
	return false;
}
int main() {
	int a, b;
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(check(0)){
		cout << "Bob" << endl;
	}
	else{
		cout << "Alice" << endl;
	}
	return 0;
}
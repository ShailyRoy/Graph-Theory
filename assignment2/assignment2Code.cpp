//shaily , Sajjad


#include <bits/stdc++.h>
using namespace std;


//havel hakimi algorithm
bool graphExists(vector<int> &v, int n)
{

    while (1)
    {
       //sorting vector in reverse order
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        if (v[0] == 0)
            return true;


        int u = v[0];
        v.erase(v.begin() + 0);


        if (u > v.size())
            return false;


        for (int i = 0; i < u; i++)
        {
            v[i]--;
            if (v[i] < 0)
                return false;
        }
    }
}

int main()
{
    vector<int>a;
    vector<int>a2;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
        a2.push_back(b);
    }


    if(graphExists(a, n)){
        sort(a2.begin(), a2.end());
        reverse(a2.begin(), a2.end());

        for(int i=0;i<n;i++){
                int c= 1;
            for(int j = i+1;c<=a2[i];j++){
                cout<<i+1<<" "<<j+1<<endl;
                a2[j]--;
                c++;
            }
        }

    }

    else
        cout<<"-1"<<endl;

    return 0;
}

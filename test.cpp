
#include <iostream> 
#include <bits/stdc++.h>


using namespace std;

int f(vector<int> &v,int mid)
{
    int val = 0;

    for(int i=0;i<v.size();i++)
    {
        val += min(v[i],mid);
    }
    return val;
}


int main() {

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int low = 0;
    int high = *max_element(v.begin(),v.end());
    int rem = 0;

    while(low<=high)
    {
        int mid = (high + low)/2;

        int cmp = f(v,mid);

        if(cmp <= m )
        {
            rem = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }

    for(int i = 0 ; i < n ; i ++)
    {
        v[i] = max(0, v[i] - rem);
        m-= min(v[i], rem);
    }

    for(int i = 0 ; i < n ; i ++)
    {
        if(m == 0)
        {
            break;
        }
        if(v[i] > 0)
        {
            v[i]--;
            m--;
        }
    }

    for(int i =0; i < n ; i ++)
    {
        cout << v[i] << " ";
    }

    cout << endl;



    return 0;
}



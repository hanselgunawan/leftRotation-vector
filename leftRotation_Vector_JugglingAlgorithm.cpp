#include <bits/stdc++.h>

using namespace std;

/*Fuction to get gcd of a and b*/
int gcd(int num_of_rotation,int size_of_arr)
{
   if(size_of_arr==0)
     return num_of_rotation;
   else
     return gcd(size_of_arr, num_of_rotation%size_of_arr);
}

vector <int> leftRotation(vector <int> a, int d, int n) {
    // Complete this function
    int i, j, k, temp;
    for(i=0;i<gcd(d,n);i++)
    {
        temp = a.at(i);
        j = i;
        while(1)
        {
          k = j + d;
          if (k >= n)
            k = k - n;
          if (k == i)
            break;
          a.at(j) = a.at(k);
          j = k;
        }
        a.at(j) = temp;
    }
    
    return a;
}

int main() {
    //JUGGLING ALGORITHM
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, d, n);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}


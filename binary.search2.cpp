#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 2000


void Nhap(string a[], int &n){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

void binary_s(int n, string target, string a[]){
    int left=0, right=n-1, middle;
    int count=0;
    while (left<=right){
            {
                middle=(left+right)/2;
                count++;
        }
        if (target == a[middle] )
        {
            cout << middle << endl << count << endl;
            return;
        }

        if (target > a[middle])
            left = middle+1;
        else
            right =middle-1;

    }
    cout << -1 << endl;
}


int main()
{
    string a[MAXN];
    int n;
    Nhap(a, n);
    string target;
    cin >> target;

    binary_s(n, target, a);

}

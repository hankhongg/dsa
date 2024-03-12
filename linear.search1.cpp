#include <iostream>
#define MAXN 10000

using namespace std;

void Nhap(int a[], int &n){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

}

int main()
{
    int a[MAXN];
    int n, target;
    int count=1;
    Nhap(a, n);
    cin >> target;
    for (int i=0; i<n; i++){
        if (a[i]==target){
            cout << count-1 << endl << count << endl;
            break;
        }
        count++;
    }
    if (count==n+1) cout << -1 << endl;
    int count1 = 1;
    for (int i=n-1; i>0; i--){
        if (a[i]==target){
            cout << count1-1 << endl << count1 << endl;
            break;
        }
        count1++;
    }
   // if (count1==n) cout << -1 << endl;
}

#include <iostream>
#define MAXN 32000

using namespace std;

void Nhap(int a[], int &n){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

void binary_s(int a[], int n, int target){
    int left=0, right=n-1, middle;
    int count=0, dem=0;
    for (int i=0; i<n;i++){
        if (a[i]==target) dem++;
    }
    while (left<=right){
            {
                middle=(left+right)/2;
                count++;
        }
        if (a[middle]==target)
        {
            cout << middle << endl << count << endl;
            dem++;
            break;
        }

        if (a[middle] < target)
            left = middle+1;
        else
            right =middle-1;

    }
    if (dem==0) cout << -1 << endl;
}

int main()
{
    int a[MAXN], n, target;
    Nhap(a, n);
    cin >> target;
    binary_s(a, n, target);

}

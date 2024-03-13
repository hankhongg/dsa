#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solution(int& s, int& big)
{
    vector<int> a; // vector lưu các giá trị của mảng có độ dài s
    for (int i=0; i<s; i++){
        int input;
        cin >> input;
        a.push_back(input); // lưu các giá trị vào a như bình thường
    }

    vector<int> b; // mảng b nhằm loại giá trị max1 ra khỏi mảng a
    vector<int> c; // mảng c nhằm loại giá trị min1 ra khỏi mảng b

// chốt lại là mảng c là thành quả của mảng ban đầu sau khi loại giá trị lớn nhất & giá trị nhỏ nhất (max1 & min1)

    int max1 = *max_element(a.begin(),a.end());          
    int min1 = *min_element(a.begin(),a.end());

    int t=0, t1=0;
    bool f_max=false, f_min=false;

    for (;t<a.size(); t++){
        if (a[t]==max1){
            f_max=true;
            break;
        }
        else b.push_back(a[t]);
    }
    if (f_max){
        t++;
        for (; t<a.size(); t++){
            b.push_back(a[t]);
        }
    }

    for (;t1<b.size();t1++){
        if (b[t1]==min1){
            f_min=true;
            break;
        }
        else c.push_back(b[t1]);
    }
    if (f_min){
        t1++;
        for (;t1<b.size();t1++){
            c.push_back(b[t1]);
        }
    }

    if (!c.empty()){
    int max2 = *max_element(c.begin(),c.end());
    int min2 = *min_element(c.begin(),c.end());

    big = (max1-min1)+(max2-min2);
    }
    else big=0;

}

void MaxDifferent(int& n, vector<int>& cases)
{
    cin >> n; // số lượng test case
    for (int i=0; i<n; i++){
        bool done=false; // cắm cờ done = false (cờ được tạo nhằm xét xem đã qua trường hợp input = 2 chưa)
        int big=0;
        int input;
        cin >> input; // số lượng phần tử của mảng
        if (input==2){        // xét trường hợp nếu số lượng = 2
            vector<int> temp;
            for (int j=0; j<input; j++){        // nhập 2 số trong mảng
                int input2;
                cin >> input2;
                temp.push_back(input2);
            }
            big = temp[0] > temp[1] ? (temp[0]- temp[1]) : (temp[1] - temp[0]) ; // nếu số ở vị trí [0] > [1] => big = [0] - [1], không thì ngược lại
            cases.push_back(big); // đẩy giá trị big vào vector cases
            done = true; // done = true có nghĩa là đã vào trường hợp input = 2
        }
        if (!done){    // xét nếu chưa trải qua trường hợp input = 2 thì ta chạy hàm trong ngoặc sau:
        Solution(input, big); // nếu input !=2 thì vào func Solution
        cases.push_back(big); // sau khi có giá trị big, lưu vào vector cases
        }
    }

    for (int i=0; i<cases.size(); i++) cout << cases[i] << endl; // cout các giá trị big được lưu trong vector cases
}

int main()
{
    vector<int>cases;
    int n;
    MaxDifferent(n, cases);
}

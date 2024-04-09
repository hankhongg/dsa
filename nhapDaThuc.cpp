/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
#include <iomanip>
using namespace std;


struct DONTHUC {
	int somu;
	double heso;

	DONTHUC(double _heso = 0, int _somu = 0) {
		heso = _heso;
		somu = _somu;
	}

	DONTHUC& operator = (const DONTHUC& rhs) {
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node {
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr) {
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC {
	Node* head;
	Node* tail;
	DATHUC() {
		this->head = nullptr;
		this->tail = nullptr;
	}
};


//###INSERT CODE HERE -
void Nhap(DATHUC& B, double heso, int somu) {
	DONTHUC* dt = new DONTHUC(heso, somu);
	Node *p = new Node(dt);
	
	if (B.head == nullptr) {
		B.head = p;
		B.tail = p;
	}
	else {
		B.tail->next = p;
		B.tail = p;
	}
}

void Xuat(const DATHUC& B) {
	Node* p = B.head;
	Node* temp = B.head;
	int count = 0, dem = 0;
	bool isFirstTerm = true; // check xem no co la don thuc dau tien

	// check xem da thuc co rong khong
	if (p == nullptr) {
		cout << "0";
		return;
	}

	while (temp != nullptr) {
		count++;
		if (temp->data->heso == 0) dem++;
		temp = temp->next;
	}
	if (dem == count) cout << "0";
	else {
		delete temp;
	}

	// chay i va in tung don thuc
	while (p != nullptr) {
		if (p->data->heso != 0) { // don thuc = 0 thi khong in
			// them dau +/- khi can
			if (!isFirstTerm) {
				cout << (p->data->heso > 0 ? "+" : "-");
			}
			else if (p->data->heso < 0) {
				cout << "-";
			}

			// in he so neu he so khac +-1 hoac so mu = 0 
			if (abs(p->data->heso) != 1 || p->data->somu == 0) {
				cout << abs(p->data->heso);
			}

			// in x^ 
			if (p->data->somu > 0) {
				cout << "x";
				if (p->data->somu > 1) {
					cout << "^" << p->data->somu;
				}
			}

			isFirstTerm = false; // sau mot lan chay thi don thuc khong con la don thuc dau tien nua
		}
		p = p->next; // tro sang don thuc tiep theo trong da thuc
	}
}


double TinhDaThuc(DATHUC& B, double x) {
	double value = 0;
	Node* p = B.head;
	while (p != nullptr) {
		value += p->data->heso * pow(x, p->data->somu);
		p = p->next;
	}
	return value;
}

int main() {
	DATHUC B;
	int N;

	cin >> N;
	for (int test = 0; test < N; test++) {
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B, heso, somu);
	}


	cout << "Da thuc vua nhap la: "; Xuat(B);
	double x; cin >> x;
	cout << "\nVoi x=" << x << ", gia tri da thuc la: "
		<< setprecision(2) << fixed << TinhDaThuc(B, x);
	return 0;
}

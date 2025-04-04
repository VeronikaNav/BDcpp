

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Fragrance
{
private:
	string _title;
	string _label;
	int _cost;
public:
	string getT() const { return _title; }
	string getL() const { return _label; }
	int getC() const { return _cost; }
	void setT(string t) { _title = t; }
    void setL(string l) { _label = l; }
	void setC(int c) { _cost = c; }
	Fragrance(string title, string label, int cost) :_title(title), _label(label), _cost(cost) {}
	Fragrance() = default;
	friend istream& operator>>(istream& in, Fragrance& p);
	friend ostream& operator<<(ostream& out, const Fragrance& p);
};
istream& operator>>(istream& in, Fragrance& p) {
	in >> p._title >> p._label >> p._cost;
	return in;
}
ostream& operator<<(ostream& out, const Fragrance& p) {
	out << p._title <<" " << p._label<<" " << p._cost;
	return out;
}
void show() {
    ifstream in("Fragrance.txt");
    if (!in.is_open())
        return;
    int n;
    in >> n;
    in.ignore();
    if (n == 0) {
        cout<<"database empty.\n";
        in.close();
        return;
    }
    else {
        Fragrance*temp = new Fragrance[n];
    for (int i = 0;i < n;i++) {
        in >> temp[i];
    }
    in.close();
		cout<<"\n=== list ===\n";
		for (int i = 0; i < n; i++) {
			cout<<"  tovar "<<i+1<<":\n";
            cout<<"  name:" << temp[i].getT() << endl;
            cout<<"  price:"<<temp[i].getC() << endl;
            cout<<"  brand:"<<temp[i].getL() << endl<<endl;
		}
        delete[]temp;
	}
}
void insert() {
    ifstream in("Fragrance.txt");
    if (!in.is_open())
        return;
    int n;
    in >> n;
    Fragrance* temp = new Fragrance[n + 1];
    if (n != 0) {
        for (int i = 0;i < n;i++) {
            in >> temp[i];
            cout << temp[i] << endl;
        }
    }
    in.close();
    cout<< "vvedite: name, price i brand tovara" << endl;
    cin >> temp[n];
    cout << temp[n] << endl;
    n++;
    ofstream out("Fragrance.txt");
    if (!out.is_open())
        return;
    out << n << endl;
    for (int i = 0;i < n;i++) {
        out << temp[i] << endl;
    }
    out.close();
    delete[] temp;
    cout<<"kaif!\n\n";
}
void find() {
    ifstream in("Fragrance.txt");
    if (!in.is_open())
        return;
    int n;
    in >> n;
    in.ignore();
    Fragrance* temp = new Fragrance[n];
    for (int i = 0;i < n;i++) {
        in >> temp[i];
    }
    in.close();
    string search_title;
    string search_label;
    int found = 0;

    cout<<"\nprint name for search(0-skip):";
    cin>>search_title;
    cout<<"print brand for search(0-skip):";
    cin>>search_label;

    cout<<"\n=== result ===\n";
    if (search_title!="0" && search_label=="0")
    {
        for (int i = 0; i < n; i++) {
            if (temp[i].getT()==search_title)
            {
                cout << "  tovar " << i + 1 << ":" << endl;
                cout << "  name: "<< temp[i].getT()<<endl;
                cout << "  price: "<<temp[i].getC()<<endl;
                cout << "  brand: "<< temp[i].getL()<<endl;
                found = 1;
            }
        }
    }
    if (search_title == "0" && search_label != "0")
    {
        for (int i = 0; i < n; i++) {
            if (temp[i].getL()== search_label) {
                cout << "  tovar " << i + 1 << ":" << endl;
                cout << "  name: " << temp[i].getT() << endl;
                cout << "  price: " << temp[i].getC() << endl;
                cout << "  brand: " << temp[i].getL() << endl;
                found = 1;
            }
        }
    }
    if (search_title != "0" && search_label != "0")
    {
        for (int i = 0; i < n; i++) {
            if ((temp[i].getT() == search_title)&& (temp[i].getL() == search_label)) {
                cout << "  tovar " << i + 1 << ":" << endl;
                cout << "  name: " << temp[i].getT() << endl;
                cout << "  price: " << temp[i].getC() << endl;
                cout << "  brand: " << temp[i].getL() << endl;
                found = 1;
            }
        }
    }
    if (!found) {
        cout<<"error.\n\n";
    }
}
void remoove() {
    ifstream in("Fragrance.txt");
    if (!in.is_open())
        return;
    int n;
    in >> n;
    in.ignore();
    Fragrance* temp = new Fragrance[n];
    for (int i = 0;i < n;i++) {
        in >> temp[i];
    }
    in.close();
    int u;
    cout<<"\nprint number for delete (1-"<<n<<"): ";
    cin>>u;
    if (u < 1 || u > n) {
        cout<<"error.\n";
        return;
    }

    for (int i = u - 1; i < n - 1; i++) {
        temp[i] = temp[i + 1];
    }

    n--;
    ofstream out("Fragrance.txt");
    if (!out.is_open())
        return;
    out << n << endl;
    Fragrance* it = new Fragrance[n];
    for (int i = 0;i < n;i++) {
        it[i] = temp[i];
        out << it[i] << endl;
    }
    out.close();
    delete[]it;
    delete[]temp;
    cout<<"tovar good delete.\n";
}
void modify() {
    ifstream in("Fragrance.txt");
    if (!in.is_open())
        return;
    int n;
    in >> n;
    in.ignore();
    Fragrance* temp = new Fragrance[n];
    for (int i = 0;i < n;i++) {
        in >> temp[i];
    }
    in.close();
    int u;

    cout<<"\nprint number for modify (1-"<<n<<"): ";
    cin >> u;
    if (u < 1 || u > n) {
        printf("error.\n");
        return;
    }

    u--;
    cout<<"current data:\n";
    cout << "  name: " << temp[u].getT() << endl;
    cout << "  price: " << temp[u].getC() << endl;
    cout << "  brand: " << temp[u].getL() << endl;
    cout<<"\nprint new data (-1-skip):\n";
    cout<<"new name: ";
    string nt;
    cin>>nt;
    if (nt != "-1") {
        temp[u].setT(nt);
    }

    cout<<"new price (-1-skip): ";
    int nc;
    cin>>nc;
    if (nc > -1) {
        temp[u].setC(nc);
    }

    cout<<"new brand (-1-skip): ";
    string nl;
    cin>>nl;
    if (nl != "-1") {
        temp[u].setL(nl);
    }
    cout<<"tovar good modify.\n\n";
    ofstream out("Fragrance.txt");
    if (!out.is_open())
        return;
    out << n << endl;
    for (int i = 0;i < n;i++) {
        out << temp[i] << endl;
    }
    out.close();
    delete[] temp;
    cout << "kaif!\n\n";
}

int main() {
    int selection = 0;
    ifstream in("Fragrance.txt");
    if (!in.is_open()) {
        ofstream out("Fragrance.txt");
        if (!out.is_open())
            return 0;
        out << selection << endl;
        out.close();
    }
    else
    {
        in.close();
    }
    do {
        cout<<"\n=== shop ===\n";
        cout<<"1. print\n";
        cout<<"2. add\n";
        cout<<"3. search\n";
        cout<<"4. delete\n";
        cout << "5. modification\n";
        cout << "6. exit\n";
        cout << "print number: ";
        cin >> selection;
        switch (selection) {
        case 1:
            show();
            break;
        case 2:
            insert();
            break;
        case 3:
            find();
            break;
        case 4:
            remoove();
            break;
        case 5:
            modify();
            break;
        case 6:
            cout << "exit program...\n";
            break;
        default:
            cout << "error.\n";
        }
    } while (selection != 6);

 return 0;
}

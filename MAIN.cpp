#include "ZAG.h"
using namespace std;
using namespace nm;
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
        cout << "\n=== shop ===\n";
        cout << "1. print\n";
        cout << "2. add\n";
        cout << "3. search\n";
        cout << "4. delete\n";
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

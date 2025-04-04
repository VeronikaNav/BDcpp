#include <iostream>
#include <string>
#include <fstream>
using namespace std;
namespace nm {
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
	istream& operator>>(istream& in, Fragrance& p);
	ostream& operator<<(ostream& out, const Fragrance& p);
	void show();
	void insert();
	void find();
	void remoove();
	void modify();
}

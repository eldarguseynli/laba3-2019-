#include <iostream>

using namespace std;
class RuMoney
{
public:
	friend int hashCode(RuMoney m);
	friend ostream& operator <<(ostream& os, const RuMoney& m) {
		os << m.rubs << "," << m.pens;
		return os;
	}
	RuMoney() {}
	RuMoney(long rubs, int pens): rubs(rubs), pens(pens){}
	bool operator ==(RuMoney &other) {
		if (rubs == other.rubs && pens == other.pens) return true;
		else return false;
	}
	bool operator !=(RuMoney &other) {
		return !((*this) == other);
	}
private:

	/*Кол-во рублей*/
	long rubs;

	/*Кол-во копеек*/
	int pens; 
};

int hashCode(RuMoney m) { return m.rubs + m.pens; }

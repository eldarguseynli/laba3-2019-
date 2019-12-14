#include <iostream>
#include <string>

using namespace std;
class RuMoney
{
	//Перегрузка оператора вывода
	friend ostream& operator <<(ostream& os, const RuMoney& m) {
		os << m.rubs << "," << m.pens;
		return os;
	}
	//Перегрузка оператора ввода
	friend istream& operator>> (istream& is, RuMoney& m)
	{
		string str;
		is >> str;
		int commaIndex = str.find(",");
		m.rubs = stoi(str.substr(0, commaIndex));
		m.pens = stoi(str.substr(commaIndex + 1));
		return is;
	}

	/* Хеш-функция, считающая хеш-код для обьектов данного класса. 
	 * Необходима для класса HashSet<RuMoney>
	 */
	friend int hashCode(RuMoney m) { return m.rubs + m.pens; }

public:
	//Конструкторы
	RuMoney() {}
	RuMoney(long rubs, int pens): rubs(rubs), pens(pens){}
	//Перегрузка операции равно ли(необходима для класса HashSet<RuMoney>)
	bool operator ==(RuMoney &other) {
		if (rubs == other.rubs && pens == other.pens) return true;
		else return false;
	}
	//Перегрузка операции не равно ли(необходима для класса HashSet<RuMoney>)
	bool operator !=(RuMoney &other) {
		return !((*this) == other);
	}
private:

	/*Кол-во рублей*/
	long rubs;

	/*Кол-во копеек*/
	int pens; 
};


#include "HashSet.hpp"

/*Итератор пользуется открытым интерфейсом класса HashSet для обхода элементов,
* то есть работает независимо от реализации класса HashSet.
* В реализации итератора используется public метод HashSet - all()
* который возвращает вектор из всех элементов множества.
* Этот метод единственный разумный выход для обхода элементов, потому что
* других открытых методов для обхода множества среди стандартных методов
* непредусмотрено.
* Из данной реализации вытекает, что данный итератор неустойчивый,
* т.к. при изменении самого самого множества, итератор продолжит работать
* со старой информацией.
*/


template <typename ValueType>
class IteratorHashSet {
private:
	int _counter = 0;
	HashSet<ValueType>* _hashset;
	vector<ValueType> v;
public:

	IteratorHashSet(HashSet<ValueType> *hashset) : _hashset(hashset) {
		v = _hashset->map.keyVect();
	}

	IteratorHashSet(HashSet<ValueType> *hashset, int counter) : _hashset(hashset), _counter(counter) {
		v = _hashset->map.keyVect();
	}

	template <typename valuetype>
	valuetype operator++(){
		_counter++;
		return v[_counter];
	}

	template <typename ValueType>
	ValueType operator++(int) {
		ValueType x = v[_counter];
		_counter++;
		return x;
	}

	template <typename ValueType>
	ValueType operator--() {
		_counter--;
		return v[_counter];
	}


	template <typename ValueType>
	ValueType operator--(int) {
		ValueType x = v[_counter];
		_counter--;
		return x;
	}

	template <typename ValueType>
	ValueType operator*(){
		return v[_counter];
	}

	template <typename ValueType>
	bool operator==(IteratorHashSet &other){
		if (*_hashset == other._hashset && v == other.v && _counter == other._counter) return true;
		else return false;
	}
	bool operator!=(IteratorHashSet &other) {
		if ((*this) == other) return false;
		else return true;
	}

	//ValueType First() {
	//	return v[0];
	//}
	//ValueType End() {
	//	return v[v.size() - 1];
	//}
	//bool IsDone() {
	//	if (_counter >= v.size()) return true;
	//	else return false;
	//}
};
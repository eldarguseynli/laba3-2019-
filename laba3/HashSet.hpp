/*
 * File: hashset.h
 * ---------------
 * This file exports the HashSet class, which implements an efficient
 * abstraction for storing sets of values.
 */

#ifndef _hashset_h
#define _hashset_h

#include <iostream>
#include "HashMap.hpp"
#include <vector>

	/*
	* Class: HashSet<ValueType>
	* -------------------------
	* Класс HashSet позволяет пользователю хранить множества обьектов в памяти
	* и обращаться с данными множествами, как с абстрактными математическими.
	* Класс HashSet обеспечивает выполнение стандартных операций с множествами за
	* константное время.
	*
	* WARNING: В данной версии класса урезаный функционал:
	* Имеются только следующие функции:
	* 1) Инициализация множества
	* 2) Добавление элемента во множество
	* 3) Удаление элемента из множества
	* 4) Определение размера множества
	* 5) Проверка принадлежности множеству
	* 6) Проверка на пустоту
	*/

template <typename ValueType>
class HashSet {

	template <typename ValueType>
	friend ostream & operator <<(ostream &os, HashSet<ValueType> &set);
public:

	/*
	 * Конструктор: HashSet
	 * Использование: HashSet<ValueType> set;
	 * ------------------------------
	 * Инициализирует множество обьектов указаного типа
	 */

	HashSet();

	/*
	 * Деструктор: ~HashSet
	 * --------------------
	 * Освобождает память, которая связана с данным множеством, из текущей кучи.
	 */

	virtual ~HashSet();

	/*
	* Метод: size
	* Использование : int nEntries = set.size();
	*-------------------------------- -
	* Возвращает количество записей в множестве.
	*/

	int size() const;

	/*
	* Метод: isEmpty
	* Использование : if (set.isEmpty()) ...
	* ---------------------------- -
	*Возвращает true, если множество не содержит записей.
	*/

	bool isEmpty() const;

	/*
	 * Метод: add
	 * Использование: set.add(value);
	 * ----------------------
	 * Добавляет элемент в множество, если его ещё не было в нем.
	 */

	void add(const ValueType & value);

	/*
	* Метод: remove
	* Использование : set.remove(ключ);
	*---------------------- -
	* Удаляет любой элемент из данного множества. Если элемент не содержится
	* в множестве ошибки не возникает, множество остается не измененным.
	*/

	void remove(const ValueType & value);

	/*
	* Метод: contains
	* Использование : if (set.containsKey(ключ)) ...
	* ------------------------------------
	* Возвращает true, если данное множество содержит данный элемент
	*/

	bool contains(const ValueType & value) const;
	/*
	* Оператор присваивания
	* Использование : set1 = set2
	* ------------------------------------
	* Множество set1 будет состоять из всех элементов множества set2.
	*/
	HashSet& operator=(const HashSet &src);

	/*
	* Метод: toString
	* Использование: string str = set.toString();
	* -----------------------------------
	* Конвертирует множество в печатаемую строку
	*/

	//std::string toString();

private:

	HashMap<ValueType, bool> map;        /* Map(ассоциативный массив) используется для хранения множества*/
};


template <typename ValueType>
HashSet<ValueType>::HashSet() {
}

template <typename ValueType>
HashSet<ValueType>::~HashSet() {
}

template <typename ValueType>
int HashSet<ValueType>::size() const {
	return map.size();
}

template <typename ValueType>
bool HashSet<ValueType>::isEmpty() const {
	return map.isEmpty();
}

template <typename ValueType>
void HashSet<ValueType>::add(const ValueType & value) {
	map.put(value, true);
}

template <typename ValueType>
void HashSet<ValueType>::remove(const ValueType & value) {
	map.remove(value);
}

template <typename ValueType>
bool HashSet<ValueType>::contains(const ValueType & value) const {
	return map.containsKey(value);
}

template <typename ValueType>
HashSet<ValueType>& HashSet<ValueType>::operator=(const HashSet &src) {
	map = src.map;
}
//
//template <typename ValueType>
//std::string HashSet<ValueType>::toString() {
//	ostringstream os;
//	os << *this;
//	return os.str();
////}
//template <typename ValueType>
//ostream & operator <<(ostream &os, const HashSet<ValueType> &set);

template <typename ValueType>
ostream & operator <<(ostream &os, HashSet<ValueType> &set) {
	os << "{";
	const vector<ValueType> vKeys = set.map.keyVect();
	int vSize = vKeys.size();
	for (int i = 0; i < vSize; i++) {
		if (i != vSize - 1) os << vKeys[i] << "; ";
		else  os << vKeys[i] << "}";
	}
	return os;
}
#endif

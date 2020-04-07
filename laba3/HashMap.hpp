/*
 * File: hashmap.h
 * ---------------
 * This file exports the HashMap class, which stores a set of key-value
 * pairs.
 */


#include <cstdlib>
#include <string>
#include <vector>
//#include "RuMoney.h"

using namespace std;
 /*
  * Функция: hashCode
  * Использование: int hash = hashCode(key);
  * --------------------------------
//  * Элементарные хеш-функции для стандартных типов
//  */
//int hashCode(const std::string & key) {
//	return key.size();
//}
//int hashCode(int key) {
//	if (key >= 0) return (int)key;
//	return -(int)key;
//}
//int hashCode(char key) {
//	if (key >= 0) return (int)key;
//	return -(int)key;
//}
//int hashCode(long key) {
//	if (key >= 0) return (int)key;
//	return -(int)key;
//}
//int hashCode(double key) {
//	if (key >= 0) return (int)key;
//	return -(int)key;
//}
//int hashCode(float key) {
//	if (key >= 0) return (int)key;
//	return -(int)key;
//}

/*
* Class: HashMap<KeyType,ValueType>
* ---------------------------------
* Класс Hashmap представляет данные для пользователя в качестве map(ассоциативный массив),
* map реализован с помощью хеш-таблицы. Добавление, удаление элемента,
* проверка на вхождение элемента в map в среднем проходят за константное время
* Класс KeyType должен содержать "free" функцию со следующей сигнатурой:
*
*	int hashCode(KeyType key);
*
* hashCode должна возращать неотрицательное число однозначно определенное для каждого ключа
*
* Для разрешения коллизиций в хеш-таблице в реализации класса используется метод цепочек
* Таблица с записями(будем так называть пары ключ-значение) состоит из вектора, состоящего из bukkets(корзинок).
* Каждая bukket является односвязным списком, состоящим из объектов типа Cell*
* Каждая cell в bucket включает в себя обьект класса KeyType и ValueType,
* а так же указатель на следующую cell в односвязном списке
*/

template <typename KeyType, typename ValueType>
class HashMap {
public:

	/*
	* Конструктор: HashMap
	* Использование: HashMap<KeyType,ValueType> map;
	* --------------------------------------
	* Инициализирует новую хеш-таблицу
	*/

	HashMap();

	/*
	* Деструктор: ~HashMap
	* --------------------
	* Освобождает память, которая связана с хеш-таблицей, из текущей кучи.
	*/

	virtual ~HashMap();

	/*
	* Метод: size
	* Использование : int nEntries = map.size();
	*-------------------------------- -
	*Возвращает количество записей в map.
	*/

	int size() const;

	/*
	* Метод: isEmpty
	* Использование : if (map.isEmpty()) ...
	* ---------------------------- -
	*Возвращает true, если map не содержит записей.
	*/

	bool isEmpty() const;

	/*
	* Метод: put
	* Использование : map.put(ключ, значение);
	*-------------------------- -
	*Связывает ключ со значением в данной map. Любое предыдущее значение, связанное
	* с ключом заменяется новым значением.
	*/

	void put(KeyType key, ValueType value);

	/*
	* Метод: get
	* Использование : ValueType value = map.get(ключ);
	*--------------------------------------
	* Возвращает значение, связанное с переданным в функцию ключом, в данной map. Если ключ не найден,
	* get возвращает значение по умолчанию для ValueType (Valuetype()).
	*/

	ValueType get(KeyType key) const;

	/*
	* Метод: containsKey
	* Использование : if (map.containsKey(ключ)) ...
	* ------------------------------------
	* Возвращает true, если в данной map есть запись для данного ключа.
	*/

	bool containsKey(KeyType key) const;

	/*
	* Метод: remove
	* Использование : map.remove(ключ);
	*---------------------- -
	* Удаляет любую запись для данного ключа из данной map.
	*/

	void remove(KeyType key);

	/*
	* Метод: clear
	* Использование : map.clear();
	*------------------ -
	* Удаляет все записи с этой map.
	*/

	void clear();

	/*
	* Оператор: []
	* Использование : map[key]
	* -------------- -
	* Возвращает значение, связанное с ключом. Этот синтаксис позволяет
	* думать о хеш-таблице как о map, индексированном по типу ключа. Если
	* ключ уже присутствует в хеш-таблице, эта функция возвращает ссылку на
	* связанное с ним значение. Если ключ отсутствует в хеш-таблице, создается новая запись,
	* значение в которой - обьект, получаемый конструктором Valuetype().
	*/

	ValueType & operator[](KeyType key);
	ValueType operator[](KeyType key) const;

	/*
	* Метод: keyVect() 
	* Использование: map.keyVect()
	* ------------------------------------
	* Возвращает вектор из ключей всех записей, хранящихся в хеш-таблице
	*/
	vector<KeyType> keyVect() {
		vector<KeyType> v(numEntries);
		int j = 0;
		for (int i = 0; i < nBuckets; i++) {
			for (Cell *cp = buckets[i]; cp != NULL; cp = cp->next) {
				v[j] = cp->key; j++;
			}
		}
		return v;
	}
	/* Private секция */

	/*
	 * Замечания по реализации:
	 * ---------------------
	 * Класс Hashmap реализуется с помощью хеш-таблицы,
	 * в которой коллизии разрешаются методом цепочек
	 */

private:

	/*
	* Определение констант
	* INITIAL_BUKKET_COUNT задает количество пар значение-ключ в хеш-таблице при инициализации
	* MAX_LOAD_PERCENTAGE задает максимальный коэффициент заполнения хеш-таблицы
	*/

	static const int INITIAL_BUCKET_COUNT = 101;
	static const int MAX_LOAD_PERCENTAGE = 70;

	/*Определение типа Cell*/

	struct Cell {
		KeyType key;
		ValueType value;
		Cell *next;
	};

	/*Инcтансные переменные*/

	vector<Cell *> buckets;
	int nBuckets;
	int numEntries;

	/*Private методы:*/
	/*
	* Private метод: createBuckets
	* Использование: createBuckets(nBuckets);
	* -------------------------------
	* Метод createBuckets заполняет вектор bukkets пустыми односвязными списками в количестве new_nBuckets
	* В качестве пустого односвязаного списка подразумевается, что в каждом элементе вектора bukkets
	* будет лежать указатель Cell равный NULL
	*/

	void createBuckets(int new_nBuckets) {
		if (new_nBuckets == 0) nBuckets = 1;
		buckets = vector<Cell *>(new_nBuckets, NULL);
		this->nBuckets = new_nBuckets;
		numEntries = 0; 
	}

	/*
	* Private метод: deleteBuckets
	* Использование: deleteBuckets(buckets);
	* ------------------------------
	* Метод deleteBuckets удаляет все cells в односвязанных списках(bucket) из вектора buckets
	*/

	void deleteBuckets(vector <Cell *> & buckets) {
		for (int i = 0; i < buckets.size(); i++) {
			Cell *cp = buckets[i];
			while (cp != NULL) {
				Cell *np = cp->next;
				delete cp;
				cp = np;
			}
		}
		buckets.clear();
	}

	/*
	* Private метод: expandAndRehash
	* Использование: expandAndRehash();
	* -------------------------
	* Метод expandAndRehash увеличивает размер хеш-таблицы(кол-во buckets),
	* повторно вычисляет хеш-значения для всех пар ключ-значение во всех cells
	* и по новым хеш-значениям распределяет все пары по buckets
	* Данный метод нужен, когда цепочки buckets становятся настолько длинными, что
	* увеличить размер хеш-таблицы и перезаписать ее за О(N)(N - кол-во пар) становится выгоднее,
	* чем оставлять для дальнейшего использования длинные цепочки.
	*/

	void expandAndRehash() {
		vector<Cell *>oldBuckets = buckets;
		createBuckets(oldBuckets.size() * 2 + 1);
		for (int i = 0; i < oldBuckets.size(); i++) {
			for (Cell *cp = oldBuckets[i]; cp != NULL; cp = cp->next) {
				put(cp->key, cp->value);
			}
		}
		deleteBuckets(oldBuckets);
	}

	/*
	* Private метод: findkey
	* Использование Cell *cp = findkey(bucket, key);
	*               Cell *cp = findkey(bucket, key, parent);
	* -------------------------
	* Данный метод по заданому ключу и bucket ищет cell, содержащую заданный ключ.
	* Если находит соответствующую cell, то возвращает указатель на
	* нее, если не находит то возращает NULL. Возможно также передавать третий
	* опциональный аргумент parent - ссылку на Cell*,
	* в которую будет записан адрес клетки, идущей перед клеткой с искомым ключом
	*/

	Cell *findCell(int bucket, KeyType key) const {
		Cell *dummy;
		return findCell(bucket, key, dummy);
	}

	Cell *findCell(int bucket, KeyType key, Cell * & parent) const {
		parent = NULL;
		Cell *cp = buckets[bucket];
		while (cp != NULL && key != cp->key) {
			parent = cp;
			cp = cp->next;
		}
		return cp;
	}

	/*
	* Приватный метод: deepcopy
	* Использование deepcopy(map);
	* -------------------------
	* Метод производит deep copy переданной функции map
	*/

	void deepCopy(const HashMap & src) {
		createBuckets(src.nBuckets);
		for (int i = 0; i < src.nBuckets; i++) {
			for (Cell *cp = src.buckets[i]; cp != NULL; cp = cp->next) {
				put(cp->key, cp->value);
			}
		}
	}

public:


	/*
	 * Deep copying поддержка
	 * --------------------
	 * Конструктор копирования и оператор присваиванивания определены для того, чтобы
	 * совершать deep copy, делая этим возможным передачу, возвращение maps в качестве значения или
	 * присваиванивание одной map другой.
	 */

	HashMap & operator=(const HashMap & src) {
		if (this != &src) {
			clear();
			deepCopy(src);
		}
		return *this;
	}

	HashMap(const HashMap & src) {
		deepCopy(src);
	}

};
	

/*
* Замечания по реализации класса HashMap :
* ---------------------------------- -
* В этой реализации map записи хранятся в хеш - таблице.
* hashtable хранит вектор buckets(корзинок), где каждая bucket - односвязный список
* элементы, которого имеют один и тот же хеш - код(т.е.коллизии решаются методом цепочек)
* Память на buckets выделяется динамически, так при большом коэффициенте загрузки
* можно увеличить количество buckets(rehash).
* Map должна обеспечивать производительность O(1) на операциях
* добавления / удаления / получения элемента из хеш - таблицы.
*/

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::HashMap() {
	createBuckets(INITIAL_BUCKET_COUNT);
}

template <typename KeyType, typename ValueType>
HashMap<KeyType, ValueType>::~HashMap() {
	deleteBuckets(buckets);
}

template <typename KeyType, typename ValueType>
int HashMap<KeyType, ValueType>::size() const {
	return numEntries;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::isEmpty() const {
	return size() == 0;
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::put(KeyType key, ValueType value) {
	(*this)[key] = value;
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::get(KeyType key) const {
	Cell *cp = findCell(hashCode(key) % nBuckets, key);
	if (cp == NULL) return ValueType();
	return cp->value;
}

template <typename KeyType, typename ValueType>
bool HashMap<KeyType, ValueType>::containsKey(KeyType key) const {
	return findCell(hashCode(key) % nBuckets, key) != NULL;
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::remove(KeyType key) {
	int bucket = hashCode(key) % nBuckets;
	Cell *parent;
	Cell *cp = findCell(bucket, key, parent);
	if (cp != NULL) {
		if (parent == NULL) {
			buckets[bucket] = cp->next;
		}
		else {
			parent->next = cp->next;
		}
		delete cp;
		numEntries--;
	}
}

template <typename KeyType, typename ValueType>
void HashMap<KeyType, ValueType>::clear() {
	deleteBuckets(buckets);
	numEntries = 0;
}

template <typename KeyType, typename ValueType>
ValueType & HashMap<KeyType, ValueType>::operator[](KeyType key) {
	int bucket = hashCode(key) % nBuckets;
	Cell *cp = findCell(bucket, key);
	if (cp == NULL) {
		//Проверяем, нет ли слишком длинных цепочек в хеш-таблице
		//Если есть, то есть выполнятеся условие (numEntries > MAX_LOAD_PERCENTAGE * nBuckets / 100.0)
		//То занова строим хеш-таблицу большого размерас теми же элементами
		if (numEntries > MAX_LOAD_PERCENTAGE * nBuckets / 100.0) {
			expandAndRehash();
			bucket = hashCode(key) % nBuckets;
		}
		cp = new Cell;
		cp->key = key;
		cp->value = ValueType();
		cp->next = buckets[bucket];
		buckets[bucket] = cp;
		numEntries++;
	}
	return cp->value;
}

template <typename KeyType, typename ValueType>
ValueType HashMap<KeyType, ValueType>::operator[](KeyType key) const {
	return get(key);
}

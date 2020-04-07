#include "HashSet.hpp"

template <typename ValueType>
class IteratorHashSet;

/*методы необходимые для последнего задания*/
template <typename ValueType>
vector<ValueType> HashSet<ValueType>::all() {
	return (this)->map.keyVect();
}

template <typename ValueType>
IteratorHashSet<ValueType> HashSet<ValueType>::begin() {
	return IteratorHashSet<ValueType>(this, 0);
}

template <typename ValueType>
IteratorHashSet<ValueType> HashSet<ValueType>::end() {
	int length = (this->all()).size(); //длина вектора из элементов 
	return IteratorHashSet<ValueType>(this, length - 1);
}
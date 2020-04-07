#include "RuMoney.h"
#include "IteratorHashSet.hpp"

#include <string>

#pragma once
using namespace std;

#define laba_choice 1 //Выбираем для какой лаборатоной компилируем, выполняем сценарий тестов.
#define TYPE_CHOICE 4

int main() {

#if laba_choice == 1
	cout << "Now we will create 3 RuMoney objects. They will be used for tests." << endl;
	cout << "For different objects input diffrent number of rubs and pens" << endl;

	int r1, r2, r3, p1, p2, p3;

	cout << endl;
	cout << "RuMoney 1)" << endl;
	cout << "rubs: ";
	cin >> r1;
	cout << "pennies: ";
	cin >> p1;

	cout << endl;
	cout << "RuMoney 2)" << endl;
	cout << "rubs: ";
	cin >> r2;
	cout << "pennies: ";
	cin >> p2;

	cout << endl;
	cout << "RuMoney 3)" << endl;
	cout << "rubs: ";
	cin >> r3;
	cout << "pennies: ";
	cin >> p3;

	RuMoney m1(r1, p1), m2(r2, p2), m3(r3, p3);

	cout << endl;

	HashSet<RuMoney> moneys;
	cout << "Let's add 1), 2) and 3) RuMoney objects to our set" << endl;
	moneys.add(m1);
	moneys.add(m2);
	moneys.add(m3);

	cout << "Now, lets create iterator and use method begin()";
	IteratorHashSet<RuMoney> i0 = moneys.begin();
#else
	//Позволяем пользователю проверить правильность выполнения
	//операций над множеством с элементами разных типов.
	cout << "Hello, this programm checkes how successfully" << endl;
	cout << "my class HashSet implements abstraction of set." << endl;
	cout << "-------------------------------------------------" << "\n\n";

	cout << "Firstly, you need to choose type or user class" << endl;
	cout << "with elements of this type or class we will" << endl;
	cout << "check work of Hashset. You can do this choice changing" << endl;
	cout << "value of constant TYPE_CHOICE in the begining of main.cpp:" << endl << endl;

	cout << "1) int" << endl;
	cout << "2) float" << endl;
	cout << "3) double" << endl;
	cout << "4) RuMoney" << endl << endl;
	
	cout << "Value of TYPE_CHOICE: " << TYPE_CHOICE << endl;
	#if TYPE_CHOICE == 1 || TYPE_CHOICE == 2 || TYPE_CHOICE == 3
		
		#if TYPE_CHOICE == 1		
			int n1, n2, n3, n4;
			HashSet<int> numbers;
		#elif TYPE_CHOICE == 2
			float n1, n2, n3, n4;
			HashSet<float> numbers;
		#elif TYPE_CHOICE == 3
			double n1, n2, n3, n4;
			HashSet<double> numbers;
		#endif
		
		cout << endl;
		cout << "Let's create a set of elements of choosed type." << endl;
		cout << "Set is created but we have not added any elements. It should be empty." << endl << endl;

		cout << "Let's check it using method IsEmpty()." << endl;
		cout << "So, method IsEmpty() returns: ";
		if (numbers.isEmpty()) cout << "True" << endl << endl;
		else cout << "False" << endl << endl;

		cout << "Now input any 4 different(!) numbers. They will be used for tests." << endl;
		cout << "(You can input not different numbers but set anyway will not" << endl;
		cout << "store duplicates(as it has to), but this action can break further tests)" << endl << endl;
		cout << "1): ";
		cin >> n1;
		cout << "2): ";
		cin >> n2;
		cout << "3): ";
		cin >> n3;
		cout << "4): ";
		cin >> n4;

		cout << endl;
		cout << "Let's add 1), 2) and 3) numbers to our set" << endl;
		numbers.add(n1);
		numbers.add(n2);
		numbers.add(n3);

		cout << "Now our set was changes. Let's look what it contains." << endl;
		cout << "For this we can use operator << for set:" << endl << endl;

		cout << "Our set (using <<): " << numbers << endl;

		cout << endl;
		cout << "Now let's remove 3) number and after that check size of set:" << endl;
		cout << "To remove 3), we will use method remove() and to find size - method size(): " << endl << endl;
		numbers.remove(n3);

		cout << "Our set (using <<): " << numbers << endl;
		cout << "Size of set (using size()): " << numbers.size() << endl;


		cout << endl;
		cout << "We have not added 4) to our set. Let's check that our set" << endl;
		cout << "does not contain it and contains 1) using method contains(): " << endl << endl;

		cout << "Number 4) is included in set? ";
		if (numbers.contains(n4)) cout << "*Yes* (According to method contains())" << endl << endl;
		else cout << "*No* (According to method contains())" << endl << endl;

		cout << "Number 1) is included in set? ";
		if (numbers.contains(n1)) cout << "*Yes* (According to method contains())" << endl << endl;
		else cout << "*No* (According to method contains())" << endl << endl;

	#else
		HashSet<RuMoney> moneys;

		cout << endl;
		cout << "Let's create a set of elements of choosed type." << endl;
		cout << "Set is created but we have not added any elements. It should be empty." << endl << endl;

		cout << "Let's check it using method IsEmpty()." << endl;
		cout << "So, method IsEmpty() returns: ";
		if (moneys.isEmpty()) cout << "True" << endl << endl;
		else cout << "False" << endl << endl;

		cout << "Now we will create 3 RuMoney objects. They will be used for tests." << endl;
		cout << "For different objects input diffrent number of rubs and pens" << endl;
		cout << "(You can input not different rubs and pens but set anyway will not" << endl;
		cout << "store duplicates(as it has to), but this action can break further tests)" << endl;

		int r1, r2, r3, p1, p2, p3;

		cout << endl;
		cout << "RuMoney 1)" << endl;
		cout << "rubs: ";
		cin >> r1;
		cout << "pennies: ";
		cin >> p1;

		cout << endl;
		cout << "RuMoney 2)" << endl;
		cout << "rubs: ";
		cin >> r2;
		cout << "pennies: ";
		cin >> p2;

		cout << endl;
		cout << "RuMoney 3)" << endl;
		cout << "rubs: ";
		cin >> r3;
		cout << "pennies: ";
		cin >> p3;

		RuMoney m1(r1, p1), m2(r2, p2), m3(r3, p3);

		cout << endl;
		cout << "Let's add 1) and 2) RuMoney objects to our set" << endl;
		moneys.add(m1);
		moneys.add(m2);

		cout << "Now our set was changes. Let's look what it contains." << endl;
		cout << "For this we can use operator << for set:" << endl << endl;

		cout << "Our set (using <<): " << moneys << endl;

		cout << endl;
		cout << "Now let's remove 2) object and after that check size of set:" << endl;
		cout << "To remove 2), we will use method remove() and to find size - method size(): " << endl << endl;
		moneys.remove(m2);

		cout << "Our set (using <<): " << moneys << endl;
		cout << "Size of set (using size()): " << moneys.size() << endl;


		cout << endl;
		cout << "We have not added 3) to our set. Let's check that our set" << endl;
		cout << "does not contain it and contains 1) using method contains(): " << endl << endl;

		cout << "RuMoney object 3) is included in set? ";
		if (moneys.contains(m3)) cout << "*Yes* (According to method contains())" << endl << endl;
		else cout << "*No* (According to method contains())" << endl << endl;

		cout << "RuMoney object 1) is included in set? ";
		if (moneys.contains(m1)) cout << "*Yes* (According to method contains())" << endl << endl;
		else cout << "*No* (According to method contains())" << endl << endl;
	#endif
		
		cout << "----------------------------------------------------------------------------" << endl << endl;
		cout << "So, we have checked all required functional of HashSet." << endl;
		cout << "These tests have to show if HashSet works successufully";
#endif
}
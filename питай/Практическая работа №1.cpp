#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");

	int n;
	
	do
	{

	cout << "\n Введите номер задания ( 1-4, 5 (номер 5 для int), 6 (номер 5 для float), 7(ИДЗ), 0(go out) \n";

	cin >> n;

	if (n == 1) {

		// Номер 1.  
		// Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных 
		// со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.

		setlocale(0, "");
		cout << sizeof(int) << ' ' << "байт(ов)" << ' ' << "занимает тип данных int" << endl;
		cout << sizeof(long int) << ' ' << "байт(ов)" << ' ' << "занимает тип данных long int" << endl;
		cout << sizeof(long long int) << ' ' << "байт(ов)" << ' ' << "занимает тип данных long long int" << endl;
		cout << sizeof(signed int) << ' ' << "байт(ов)" << ' ' << "занимает тип данных signed int" << endl;
		cout << sizeof(unsigned int) << ' ' << "байт(ов)" << ' ' << "занимает тип данных unsigned int" << endl;
		cout << sizeof(short int) << ' ' << "байт(ов)" << ' ' << "занимает тип данных short int" << endl;
		cout << sizeof(float) << ' ' << "байт(ов)" << ' ' << "занимает тип данных float" << endl;
		cout << sizeof(double) << ' ' << "байт(ов)" << ' ' << "занимает тип данных double" << endl;
		cout << sizeof(long double) << ' ' << "байт(ов)" << ' ' << "занимает тип данных long double" << endl;
		cout << sizeof(char) << ' ' << "байт(ов)" << ' ' << "занимает тип данных char" << endl;
		cout << sizeof(bool) << ' ' << "байт(ов)" << ' ' << "занимает тип данных bool" << endl;
	}
	
	if (n == 2) {

		// Номер 2. Вывести на экран двоичное представление в памяти (все разряды) целого числа. 
		// При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.

		int value;
		cout << "Введите значение ";
		cin >> value;
		cout << '\n';
		int order = sizeof(value) * 8;
		unsigned mask = 1 << (order - 1);
		cout << "Результат: ";
		for (int i = 0; i < order; i++) {
			if (value & (mask >> i)) {
				cout << "1";
			}
			else {
				cout << "0";
			}
			if ((i == 0) or (i == 7) or (i == 15) or (i == 23)) {
				cout << ' ';
			}
		}

	}
	
	if (n == 3) {

		// Номер 3. Вывести на экран двоичное представление в памяти (все разряды) типа float. 
		// При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), 
		// мантиссу и порядок.

		union {
			int intValue;
			float floatValue;
		};
		cout << "Введите значение ";
		cin >> floatValue;
		cout << '\n';
		unsigned int order = 32;
		unsigned mask = 1 << (order - 1);
		cout << "Результат: ";
		for (int i = 0; i < order; i++) {
			if (intValue & (mask >> i)) {
				cout << "1";
			}
			else {
				cout << "0";
			}
			if (i == 8) {
				cout << ' ';
			}
			if (i == 0) {
				cout << ' ';
			}
		}
	}
	
	if (n == 4) {

		// Номер 4. Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо 
		// визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.

		union {
			unsigned int At[2];
			double doubleValue;
		};
		cout << "Введите значение ";
		cin >> doubleValue;
		cout << '\n';
		unsigned int order = 64;
		unsigned mask = 1 << (order - 1);
		cout << "Результат: ";
		for (int i = 0; i < 32; i++) {
			if (At[1] & (mask >> i)) {
				cout << "1";
			}
			else {
				cout << "0";
			}
			if (i == 11) {
				cout << ' ';
			}
			if (i == 0) {
				cout << ' ';
			}
		}
		for (int j = 32; j < 64; j++) {
			if (At[0] & (mask >> j)) {
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
	}

	if (n == 5){

		// Номер 5. Реализовать возможность произвольного изменения любого бита в введенном 
		// числе (для всех типов данных) с использованием логических операций.
		// решение для числа типа int

		int value, bitNumber, newBitValue, bitValue, newValue;
		unsigned int key, reversedKey;
		cout << "Введите число ";
		cin >> value;
		cout << '\n';
		cout << "Введите порядковый номер бита, значение которого вы хотите изменить ";
		cin >> bitNumber;
		cout << '\n';
		cout << "Введите новое значение бита ";
		cin >> newBitValue;
		cout << '\n';
		key = 1;
		key = key << (bitNumber - 1);
		reversedKey = ~key;
		if ((value & reversedKey) == value) {
			bitValue = 0;
		}
		else {
			bitValue = 1;
		}
		if (bitValue == newBitValue) {
			newValue = value;
		}
		else {
			if (bitValue == 0) {
				newValue = value + key;
			}
			else {
				newValue = value & reversedKey;
			}
		}
		cout << "Новое значение: " << newValue;

	}

	if (n == 6){

		// решение для числа типа данных float

		union {
			int intValue;
			float floatValue;
		};
		int bitNumber, newBitValue, bitValue, newValue;
		unsigned int key, reversedKey;
		cout << "Введите число ";
		cin >> floatValue;
		cout << '\n';
		cout << "Введите порядковый номер бита, значение которого вы хотите изменить ";
		cin >> bitNumber;
		cout << '\n';
		cout << "Введите новое значение бита ";
		cin >> newBitValue;
		cout << '\n';
		key = 1;
		key = key << (bitNumber - 1);
		reversedKey = ~key;
		if ((intValue & reversedKey) == intValue) {
			bitValue = 0;
		}
		else {
			bitValue = 1;
		}
		if (bitValue == newBitValue) {
			newValue = intValue;
		}
		else {
			if (bitValue == 0) {
				newValue = intValue + key;
			}
			else {
				newValue = intValue & reversedKey;
			}
		}

		union {

			float newFloatValue;
			int newnewValue;
		};
		newnewValue = newValue;
		cout << "Новое значение: " << newFloatValue;

	}
	
	if (n ==7) {

		// ИДЗ. Вариант 14. Извлечение байта. Обнулите все байты числа, кроме второго 
		// (считая с младшего), и сдвиньте значение этого байта в позицию младшего байта.

		int value, mantle = 0, dv = 1;
		long long int r = 1111111100000000;
		for (int i = 0; i <= 15; i++) {
			mantle = mantle + (r % 10) * dv;
			dv *= 2;
			r /= 10;
		}
		cout << "Введите число ";
		cin >> value;
		cout << '\n';
		value = mantle & value;;
		value = value >> 8;
		cout << "Результат в 10 системе: " << value << '\n';
		cout << '\n';
		int order = sizeof(value) * 8;
		unsigned mask = 1 << (order - 1);
		cout << "Результат в 2 системе: ";
		for (int i = 0; i < order; i++) {
			if (value & (mask >> i)) {
				cout << "1";
			}
			else {
				cout << "0";
			}
			if ((i == 0) or (i == 7) or (i == 15) or (i == 23)) {
				cout << ' ';
			}
		}
	}
	} while (n != 0);
}

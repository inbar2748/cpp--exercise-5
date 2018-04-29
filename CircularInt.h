#pragma once

#include <vector>

#include <set>

#include <iostream>

#include <string>



using namespace std;



class CircularInt {

private:

	int first, last;

	int current;



public:

	CircularInt(int x, int y);

	CircularInt(const CircularInt& hour);





	CircularInt& operator+=(const int);

	CircularInt& operator+=(const CircularInt& hour);



	CircularInt& operator-=(const int);

	CircularInt& operator-=(const CircularInt& hour);



	CircularInt& operator*=(const int);

	CircularInt& operator*=(const CircularInt& hour);



	CircularInt& operator/=(const int);

	CircularInt& operator/=(const CircularInt& hour);



	CircularInt operator--(const int);

	CircularInt& operator--();



	CircularInt operator++(int);

	CircularInt& operator++();



	CircularInt& operator=(const int);

	CircularInt& operator=(const CircularInt& hour);



	friend int operator >= (const CircularInt& hour, int number);

	friend int operator >= (int number, const CircularInt& hour);

	friend int operator >= (const CircularInt& x, const CircularInt& y);



	friend int operator > (const CircularInt& hour, int number);

	friend int operator > (int num, const CircularInt& hour;

	friend int operator > (const CircularInt& x, const CircularInt& y);



	friend int operator <= (const CircularInt& hour, int number);

	friend int operator <= (int number, const CircularInt& hour);

	friend int operator <= (const CircularInt& x, const CircularInt& y);



	friend int operator < (const CircularInt& hour, int number);

	friend int operator < (int number, const CircularInt& hour);

	friend int operator < (const CircularInt& x, const CircularInt& y);



	friend int operator == (const CircularInt& hour, int number);

	friend int operator == (int number, const CircularInt& hour);

	friend int operator == (const CircularInt& x, const CircularInt& y);



	friend int operator != (const CircularInt& hour, int number);

	friend int operator != (int number, const CircularInt& hour);

	friend int operator != (const CircularInt& x, const CircularInt& y);



	friend CircularInt operator - (const CircularInt& hour);

	friend CircularInt operator - (const CircularInt& hour, const int number);

	friend CircularInt operator - (const int number, const CircularInt& hour);

	friend CircularInt operator - (const CircularInt& x, const CircularInt& y);



	friend CircularInt operator -= (const CircularInt& hour, const int number);

	friend CircularInt operator -= (const int number, const CircularInt& hour);

	friend CircularInt operator -= (const CircularInt& x, const CircularInt& y);



	friend CircularInt operator * (const CircularInt& hour, const int number);

	friend CircularInt operator * (const int number, const CircularInt& hour);

	friend CircularInt operator * (const CircularInt& x, const CircularInt& y);



	friend CircularInt operator + (const CircularInt& hour);

	friend CircularInt operator + (const CircularInt & hour, const int number);

	friend CircularInt operator + (const int number, const CircularInt & hour);

	friend CircularInt operator + (const CircularInt & x, const CircularInt & y);



	friend CircularInt operator - (const CircularInt & hour, const int number);

	friend CircularInt operator - (const int number, const CircularInt & hour);

	friend CircularInt operator - (const CircularInt & x, const CircularInt & y);



	friend CircularInt operator / (const CircularInt & hour, const int number);

	friend CircularInt operator / (const int number, const CircularInt & hour);

	friend CircularInt operator / (const CircularInt & x, const CircularInt & y);



	/*friend CircularInt operator /= (const CircularInt & hour, const int number);

	friend CircularInt operator /= (const int number,const CircularInt & hour);

	friend CircularInt operator /= (const CircularInt & x,const CircularInt & y);*/



	friend ostream& operator<<(ostream& o, const CircularInt &hour);

	friend istream& operator>>(istream& o, CircularInt &hour);

};



inline ostream& operator<<(ostream& o, const CircularInt &hour) {

	o << hour.current;

	return o;

}



inline istream& operator>>(istream& o, CircularInt &hour) {

	int n;

	o >> n;

	hour.current = n;

	if (hour.current>hour.last) {

		hour.current = hour.current%hour.last;

	}

	while (hour.current<hour.first) {

		hour.current += hour.last;

	}

	return o;

}



inline ostream &operator<<(ostream &o, vector<int> v) {

	string result = "";

	for (unsigned int i = 0; i < v.size(); i++)

	{

		result = result + to_string(v[i]) + " ";

	}

	return o << result;

}



inline int operator==(int number, const CircularInt& hour) {

	if (number == hour.current) return 1;

	else return 0;

}



inline int operator==(const CircularInt& x, const CircularInt& y) {

	if (x.current == y.current) return 1;

	else return 0;

}



inline int operator==(const CircularInt& x, int number) {

	if (x.current == number) return 1;

	else return 0;

}



inline int operator!=(int number, const CircularInt& hour) {

	if (number != hour.current) return 1;

	else return 0;

}



inline int operator!=(const CircularInt& x, const CircularInt& y) {

	if (x.current != y.current) return 1;

	else return 0;

}



inline int operator!=(const CircularInt& x, int number) {

	if (x.current != number) return 1;

	else return 0;

}



inline CircularInt operator-(const CircularInt& hour) {

	CircularInt temp(hour);

	temp.current = temp.last - temp.current;

	return temp;

}



inline CircularInt operator-(const CircularInt& hour, const int number) {

	CircularInt temp(hour);

	temp -= number;

	return temp;

}



inline CircularInt operator-(const int number, const CircularInt& hour) {

	return -(hour - number);

}

inline CircularInt operator-(const CircularInt& x, const CircularInt& y) {

	return x - y.current;

}



inline CircularInt operator+(const int number, const CircularInt& hour) {

	return hour + number;

}



inline CircularInt operator+(const CircularInt & hour, const int number) {

	CircularInt temp(hour);

	temp += number;

	return temp;

}



inline CircularInt operator+(const CircularInt & x, const CircularInt & y) {

	return x + y.current;

}



inline CircularInt operator*(const CircularInt& hour, const int number) {

	CircularInt temp(hour);

	temp *= number;

	return temp;

}

inline CircularInt operator*(const int number, const CircularInt& hour) {

	return hour * number;

}

inline CircularInt operator*(const CircularInt& x, const CircularInt& y) {

	return x * y.current;

}



inline CircularInt operator/(const CircularInt & hour, const int number) {

	CircularInt temp(hour);

	temp / number;

	return temp;

}



inline CircularInt operator/(const int number, const CircularInt & hour) {

	CircularInt temp(hour);

	temp / number;

	return temp;



}



inline CircularInt operator/(const CircularInt & x, const CircularInt & y) {

	return x / y.current;

}



inline int operator>(const CircularInt& hour, int number) {

	if (hour.current > number) return 1;

	else return 0;

}

inline int operator>(int number, const CircularInt& hour) {

	if (number > hour.current) return 1;

	else return 0;

}

inline int operator>(const CircularInt& x, const CircularInt& y) {

	if (x.current > y.current) return 1;

	else return 0;

}



inline int operator<(const CircularInt& hour, int number) {

	if (hour.current < number) return 1;

	else return 0;

}

inline int operator<(int number, const CircularInt& hour) {

	if (number < hour.current) return 1;

	else return 0;

}

inline int operator<(const CircularInt& x, const CircularInt&y) {

	if (x.current < y.current) return 1;

	else return 0;

}



inline int operator<=(const CircularInt& hour, int number) {

	if (hour.current <= number) return 1;

	else return 0;

}

inline int operator<=(int number, const CircularInt& hour) {

	if (number <= hour.current) return 1;

	else return 0;

}

inline int operator<=(const CircularInt& x, const CircularInt& y) {

	if (x.current <= y.current) return 1;

	else return 0;

}



inline int operator>=(const CircularInt& hour, int number) {

	if (hour.current >= number) return 1;

	else return 0;

}

inline int operator>=(int number, const CircularInt& hour) {

	if (number >= hour.current) return 1;

	else return 0;

}

inline int operator>=(const CircularInt& x, const CircularInt& y) {

	if (x.current >= y.current) return 1;

	else return 0;

}



inline CircularInt operator-=(const CircularInt& hour, const int number) {

	CircularInt temp(hour);

	temp.current -= number;

	return temp;

}

inline CircularInt operator-=(const int number, const CircularInt& hour) {

	return hour -= number;

}

inline CircularInt operator-=(const CircularInt& x, const CircularInt& y) {

	return x -= y.current;

}
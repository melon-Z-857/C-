#include"Date.h"

Date::Date(int year, int month, int day) {
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date::~Date() {
	_year = 0;
	_month = 0;
	_day = 0;
}

Date& Date::operator+=(int day) {
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day) {
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day) {
	_day -= day;
	while (_day <= 0) {
		_month--;
		if (_month == 0) {
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day) {
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++() {
	*this += 1;
	return *this;
}

Date Date::operator++(int) {
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator--() {
	*this -= 1;
	return *this;
}

Date Date::operator--(int) {
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

bool Date::operator>(const Date& d) {
	if (_year > d._year) {
		return true;
	}
	else if ((_year == d._year && _month > d._month)) {
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator==(const Date& d) {
	return (_year == d._year && _month == d._month && _day == d._day);
}

bool Date::operator >= (const Date& d) {
	return (*this > d || *this == d);
}

bool Date::operator < (const Date& d) {
	return !(*this >= d);
}

bool Date::operator <= (const Date& d) {
	return !(*this > d);
}

bool Date::operator != (const Date& d) {
	return !(*this == d);
}

int Date::operator-(const Date& d) {
	Date bigdate = *this;
	Date smalldate = d;
	if (smalldate._year > bigdate._year) {
		Date tmp = bigdate;
		bigdate = smalldate;
		smalldate = tmp;
	}
	Date cur = smalldate;
	int gap1 = 0;
	while (cur._year < bigdate._year) {
		if ((cur._year % 4 == 0 && cur._year % 100 != 0) || (cur._year % 400 == 0)) {
			gap1 += 366;
		}
		else {
			gap1 += 365;
		}
		cur._year++;
	}
	int gap2 = bigdate._day;
	for (int i = 1; i < bigdate._month; i++) {
		gap2 += GetMonthDay(bigdate._year, i);
	}
	int gap3 = smalldate._day;
	for (int i = 1; i < smalldate._month; i++) {
		gap3 += GetMonthDay(smalldate._year, i);
	}
	return gap1 + gap2 - gap3;
}
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
// dd/mm/yyyy
class Date {
	string ngay;
	int get_day() {
		return stoi(ngay.substr(0, 2));
	}
	int get_month() {
		return stoi(ngay.substr(3, 2));
	}
	int get_year() {
		return stoi(ngay.substr(6, 4));
	}
	bool leapyear(int nam) {
		return (nam % 4 == 0 && nam % 100 != 0) ? true : false;
	}
public:
	//	Date(int d, int m, i=nt y) : ngay(d), thang(m), nam(y){}
	Date(const string dmy) : ngay(dmy) {}
	bool check_format() {
		if (ngay.length() < 10) {
			return false;
		}
		if (ngay[2] != '/' || ngay[5] != '/') {
			return false;
		}


		return true;
	}
	bool check_value() {
		if (!check_format) {
			return false;
		}
		int day = get_day();
		int month = get_month();
		int year = get_year();

		if (day < 1 || month < 1 || year < 2024 || month > 12 || day > 31) {
			return false;
		}
		if (month == 2){
			if (leapyear(year)) {
				if (day > 29) false;
			}
			else {
				if (day > 28) false;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) return false;
			 }

		return true;
	}
};
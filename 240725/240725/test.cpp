#include"Date.h"
using namespace std;

int main() {
	Date d1(2024, 7, 25);
	Date d2(2023, 7, 20);

	cout << d1 - d2 << endl;

	cout << d1._year << endl;

	return 0;
}
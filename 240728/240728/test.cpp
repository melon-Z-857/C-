//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        string str;
//        size_t i3 = 1;
//        size_t i4 = 1;
//        size_t ret = 0;
//        size_t next = 0;
//        for (auto i1 = num1.rbegin(); i1 < num1.rend(); i1++, i3 *= 10) {
//            i4 = 1;
//            next = 0;
//            for (auto i2 = num2.rbegin(); i2 < num2.rend(); i2++, i4 *= 10) {
//                size_t val1 = (*i1) - '0';
//                size_t val2 = (*i2) - '0';
//                size_t val3 = val1 * val2 + next;
//                next = val3 / 10;
//                val3 %= 10;
//                ret += val3 * i3 * i4;
//            }
//            if (next != 0) {
//                ret += next * i3 * i4 ;
//            }
//        }
//        str = to_string(ret);
//        return str;
//    }
//};
//
//int main() {
//    Solution str;
//    str.multiply("123", "456");
//}



#include"string.h"
int main() {
	bit::string str("hi");
	cout << str << endl;

	return 0;
}



//#include <iostream>
//
//class MyClass {
//private:
//    int memberVariable = 42;
//
//public:
//    // 将全局函数声明为友元函数
//    friend void globalFriendFunction(MyClass&);
//};
//
//// 全局函数的实现
//void globalFriendFunction(MyClass& obj) {
//    std::cout << "This is the global friend function. Member variable: " << obj.memberVariable << std::endl;
//}
//
//int main() {
//    MyClass obj;
//    globalFriendFunction(obj);
//    return 0;
//}
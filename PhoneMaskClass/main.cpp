#include <iostream>
#include "../UnitTestFramework/test_framework.h"
#include "phone_number.h"

void Tests() {
    PhoneNumber phone("+380-12-12");
    AssertEqual(phone.GetInternationalNumber(),"+380-12-12","+380-12-12");
    AssertEqual(phone.GetCountryCode(),"380","380");
    AssertEqual(phone.GetCityCode(),"12","12");
    AssertEqual(phone.GetLocalNumber(),"12","12");

    PhoneNumber phone2("+7-seven-tententen");
    AssertEqual(phone2.GetCityCode(),"seven","seven");
    AssertEqual(phone2.GetLocalNumber(),"tententen","tententen");

    PhoneNumber phone1("+7-38-coursera-cpp");
    AssertEqual(phone1.GetCountryCode(),"7","7");
    AssertEqual(phone1.GetCityCode(),"38","38");
    AssertEqual(phone1.GetLocalNumber(),"coursera-cpp","coursera-cpp");
}
int main() {
    TestRunner tr;
    tr.RunTest(Tests,"Tests");
    return 0;
}

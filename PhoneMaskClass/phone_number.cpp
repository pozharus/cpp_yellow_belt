#include "phone_number.h"
#include <stdexcept>
#include <sstream>
#include <iostream>
using namespace std;
PhoneNumber::PhoneNumber(const string &international_number) {
    if(international_number[0] != '+') {
        throw invalid_argument("Wrong number format");
    } else {
        stringstream ss(international_number);
        if(ss) {
            string country_code;
            string city_code;
            string local_number;
            ss.ignore(1);

            getline(ss,country_code,'-');
            getline(ss,city_code,'-');
            getline(ss, local_number);

            if(!country_code.empty() and !city_code.empty() and !local_number.empty()) {
                country_code_ = country_code;
                city_code_ = city_code;
                local_number_ = local_number;
            } else {
                throw invalid_argument("Wrong number format");
            }
        }
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    string international_number = '+' + country_code_ + '-' + city_code_ + '-'
            + local_number_;
    return international_number;
}

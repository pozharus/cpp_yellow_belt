#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GreatestCommonDivisor(b, a % b);
    }
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}


class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/*
class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational() {
      new_numerator = 0;
      new_denominator = 1;
  };

  Rational(int numerator, int denominator) {
      // Реализуйте конструктор по умолчанию
      // Реализуйте конструктор
      new_numerator = numerator;
      new_denominator = denominator;

      int gcd = GreatestCommonDivisor(new_numerator, new_denominator);

      //Проверка на отрицательность обеих элементов до сокращения
      if(new_numerator < 0 and new_denominator < 0) {
          new_numerator = abs(new_numerator);
          new_denominator = abs(new_denominator);
      }

      //Сокращение
      new_numerator = new_numerator / gcd;
      new_denominator = new_denominator / gcd;

      //Если числитель дроби равен нулю
      if(new_numerator == 0) {
          new_denominator = 1;
          return;
      }

      //Если числитель или знаменатель равен нулю
      if(new_denominator < 0 or new_numerator < 0) {
          if(new_numerator > 0) {
              new_numerator = -new_numerator;
          }
          new_denominator = abs(new_denominator);
          return;
      }
  }

  int Numerator() const {
      return new_numerator;
  }

  int Denominator() const {
      return new_denominator;
  }

private:
    // Добавьте поля
    int new_numerator;
    int new_denominator;
};
*/

void TestConstructor() {
    Rational r;
    AssertEqual(r.Numerator(),0,"[r] Num in default constr");
    AssertEqual(r.Denominator(),1,"[r] Denomin in default constr");
}

void TestReduction() {
    const Rational r0(8,12);
    AssertEqual(r0.Numerator(),2,"[r0] Num can be reduction");
    AssertEqual(r0.Denominator(),3,"[r0] Denomin can be reduction");

    const Rational r1(3,10);
    AssertEqual(r1.Numerator(),3,"[r1] Num can`t be reduction");
    AssertEqual(r1.Denominator(),10,"[r1] Denomin can`t be reduction");
}

void TestNegative() {
    const Rational r2(-4,6);
    AssertEqual(r2.Numerator(),-2,"[r2] Num need to be neg");
    AssertEqual(r2.Denominator(),3,"[r2] Denomin need to be pos");

    const Rational r3(4,-6);
    AssertEqual(r3.Numerator(),-2,"[r3] Num need to be neg");
    AssertEqual(r3.Denominator(),3,"[r3] Denomin need to be pos");

    const Rational r4(-2,-3);
    AssertEqual(r4.Numerator(), 2,"[r4] Num need to be neg");
    AssertEqual(r4.Denominator(),3,"[r4] Denomin need to be pos");
}

void TestZeroNum() {
    const Rational r5(0,-15);
    AssertEqual(r5.Numerator(),0,"[r5] Num need to be neg");
    AssertEqual(r5.Denominator(),1,"[r5] Denomin need to be pos");

    const Rational r6(0,15);
    AssertEqual(r6.Numerator(),0,"[r6] Num need to be neg");
    AssertEqual(r6.Denominator(),1,"[r6] Denomin need to be pos");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestConstructor, "TestConstructor");
  runner.RunTest(TestReduction, "TestReduction");
  runner.RunTest(TestNegative, "TestNegative");
  runner.RunTest(TestZeroNum, "TestZeroNum");
  return 0;
}

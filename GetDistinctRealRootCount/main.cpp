#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>
using namespace std;

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


double GetDiscriminant(double a, double b, double c) {
    double d;
    d = (b*b)-(4*a*c);
    return d;
}

int GetDistinctRealRootCount(double a, double b, double c) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный

    //Если уравнение линейное или константа
    if(a == 0 and b == 0 and c != 0) {
        return 0;
    } else if (a == 0 and b != 0) {
        return 1;
    }

    //Если ни то, ни другое - считаем дискриминант
    double d = GetDiscriminant(a,b,c);

    if(d > 0) {
        return 2;
    } else if (d == 0) {
        return 1;
    } else {
        return 0;
    }
}


void TestRootsCount() {
    //Генератор случайных чисел;
    mt19937 gen; //начальная инициализация числа
    uniform_real_distribution<double> uid(-10, 10); //диапазон принимаемых значений

    for(int i = 0; i < 100; i++) {
        const auto a = uid(gen);
        const auto b = uid(gen);
        const auto c = uid(gen);

        const auto roots_count = GetDistinctRealRootCount(a,b,c);

        Assert(roots_count >= 0 && roots_count <= 2, "Number of roots must be in range from 0 to 2");
    }
}

void TestQuadratic() {
    AssertEqual(GetDistinctRealRootCount(1,1,1),0,
                "ax2 + bx + c = 0; a,b,c = 1");
    AssertEqual(GetDistinctRealRootCount(1,-10,1),2,
                "ax2 + bx + c = 0; a = 1, b = -10, c = 1");
    AssertEqual(GetDistinctRealRootCount(-10,-10,-10),0,
                "ax2 + bx + c = 0; a = -10, b = -10, c = -10");
    AssertEqual(GetDistinctRealRootCount(99,99,99),0,
                "ax2 + bx + c = 0; a = 99, b = 99, c = 99");
}

void TestNonFullQuadratic() {
    AssertEqual(GetDistinctRealRootCount(1,0,1),0,
                "ax2 + c = 0; a = 1, b = 0, c = 1");
    AssertEqual(GetDistinctRealRootCount(-10,0,-10),0,
                "ax2 + c = 0; a = -10, b = 0, c = -10");
    AssertEqual(GetDistinctRealRootCount(-10,0,10),2,
                "ax2 + c = 0; a = -10, b = 0, c = 10");

    AssertEqual(GetDistinctRealRootCount(1,1,0),2,
                "ax2 + bx = 0; a = 1, b = 1, c = 0");
    AssertEqual(GetDistinctRealRootCount(-10,-10,0),2,
                "ax2 + bx = 0; a = -10, b = -10, c = 0");
    AssertEqual(GetDistinctRealRootCount(10,-10,0),2,
                "ax2 + bx = 0; a = 10, b = -10, c = 0");

    AssertEqual(GetDistinctRealRootCount(10,0,0),1,
                "ax2 = 0; a = 10, b = 0, c = 0");
    AssertEqual(GetDistinctRealRootCount(-10,0,0),1,
                "ax2 = 0; a = -10, b = 0, c = 0");
}

void TestLinearEquation() {
    AssertEqual(GetDistinctRealRootCount(0,10,10),1,
                "bx + c = 0; a = 0, b = 10, c = 10");
    AssertEqual(GetDistinctRealRootCount(0,-10,-10),1,
                "bx + c = 0; a = 0, b = -10, c = -10");
    AssertEqual(GetDistinctRealRootCount(0,10,-10),1,
                "bx + c = 0; a = 0, b = 10, c = -10");

    AssertEqual(GetDistinctRealRootCount(0,99,0),1,
                "bx = 0; a = 0, b = 99, c = 0");
    AssertEqual(GetDistinctRealRootCount(0,-99,0),1,
                "bx = 0; a = 0, b = 99, c = 0");
}

void TestConstants() {
    AssertEqual(GetDistinctRealRootCount(0,0,-10),0,
                "c = -10");
    AssertEqual(GetDistinctRealRootCount(0,0,1),0,
                "c = 1");
    AssertEqual(GetDistinctRealRootCount(0,0,67859),0,
                "c = 67859");
}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(TestRootsCount,"TestRootsCount");
    runner.RunTest(TestQuadratic,"TestQuadratic");
    runner.RunTest(TestNonFullQuadratic,"TestNonFullQuadratic");
    runner.RunTest(TestLinearEquation,"TestLinearEquation");
    runner.RunTest(TestConstants, "TestConstants");
    return 0;
}

#include "test_runner.h"
#include "sum_reverse_sort.h"
void Tests() {
    AssertEqual(Sum(0,0),0,"0+0");
    AssertEqual(Sum(-64528,125678),61150,"long nums sum");
    AssertEqual(Sum(-1000,0),-1000,"-1000+0");

    AssertEqual(Reverse("madam"),"madam","madam");
    AssertEqual(Reverse("c"),"c","c");
    AssertEqual(Reverse("1"),"1","1");
    AssertEqual(Reverse("ababagalamaga"),"agamalagababa","long string");
}

int main() {
    TestRunner runner;
    runner.RunTest(Tests,"Tests");
    return 0;
}


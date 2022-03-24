#include <iostream>
#include "./src/p1.h"
using namespace std;
int main()
{
    FixedRecord record("./input/datos1.txt");
    record.load();
    return 0;
}
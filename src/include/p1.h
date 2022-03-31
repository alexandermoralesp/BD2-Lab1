#ifndef P1_h
#define P1_H

#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

#define delimiter '\t'

/* General functions */
void showArrayChars(char value[], int n) {
    for (int q = 0; q < n; q++) {
        std::cout << value[q];
    }
}

/* Alumn API */
struct Alumn {
    char code_[5];
    char name_[11];
    char lastName_[20];
    char career_[15];
    Alumn() = default;
    void showData() {
        showArrayChars(code_, 5);
        showArrayChars(name_, 11);
        showArrayChars(lastName_, 20);
        showArrayChars(career_, 15);
    }
};

class FixedRecord {
   private:
    std::string path_;
   public:
    FixedRecord(std::string path);
    std::vector<Alumn> load();
    void add(Alumn record);
    Alumn readRecord(int pos);
};

#endif
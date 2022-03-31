#ifndef P1_h
#define P1_H

#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

#define delimiter '\t'

/* General functions */
static void showArrayChars(char value[], int n) {
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
    static Alumn unpack(std::string &record);
    static char *pack(Alumn record);
};

// Alumn FixedRecord::unpack(std::string &record) {
//     std::vector<std::string> attributes(5);
//     Alumn output;
//     int curr = -1;
//     for (int s = 0; s < sizeof(record); s++) {
//         if (record[s] == '\\') {
//             attributes[curr] += record[s + 1];
//             s++;
//         } else if (record[s] == '\t') {
//             curr++;
//             continue;
//         } else {
//             attributes[curr] += record[s];
//         }
//     }
//     memcpy(output.code_, attributes[0].c_str(), sizeof(output.code_));
//     memcpy(output.name_, attributes[1].c_str(), sizeof(output.name_));
//     memcpy(output.lastName_, attributes[2].c_str(),
//     sizeof(output.lastName_)); memcpy(output.career_, attributes[3].c_str(),
//     sizeof(output.career_)); return output;
// }

#endif
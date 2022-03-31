#include <iostream>

#include "../src/p1.h"
#include <string>
using namespace std;
void readingFile() {
    ifstream file("../input/datos1.txt");
    vector<Alumn> output;
    Alumn record; 
    if (file.is_open()) {
        while(!file.eof()) {
            record = Alumn();             
            file.read((char*) &record, sizeof(Alumn));
            output.push_back(record);
        }
        file.close();
    }
    for (auto& alumn: output) {
        alumn.showData();
    }
}
void test_load() {
    FixedRecord fixedRecord("input/datos1.txt");
    vector<Alumn> alumns = fixedRecord.load();
    for (auto& alumn: alumns) {
        alumn.showData();
    }
    std::cout <<"\n";
}

void test_add() {
    FixedRecord fixedRecord("input/datos1.txt");
    Alumn alumn;
}
int main() {
    // readingFile();
    try
    {
        test_load();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
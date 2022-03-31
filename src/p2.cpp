#include "./include/p2.h"

FixedRecord::FixedRecord(std::string path) {
    if (path.size() <= 0)
        throw std::invalid_argument(
            "The path value is empty or is not valid directory.");
    path_ = path;
}
std::vector<Alumn> FixedRecord::load() {
    std::ifstream file(path_, std::ios::in);
    std::vector<Alumn> output;
    Alumn record;
    if (file.is_open()) {
        while (!file.eof()) {
            record = Alumn();
            file.read((char*)&record, sizeof(Alumn));
            output.push_back(record);
        }
        file.close();
    }
    return output;
}

int main() {
  FixedRecord fixedrecord("input/datos1.dat");
  std::vector<Alumn> alumns = fixedrecord.load();
  for(auto &alumn:alumns) {
    alumn.showData();
  }
}
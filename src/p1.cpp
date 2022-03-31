#include "./include/p1.h"

FixedRecord::FixedRecord(std::string path) {
    if (path.size() <= 0)
        throw std::invalid_argument(
            "The path value is empty or is not valid directory.");
    path_ = path;
}

std::vector<Alumn> FixedRecord::load() {
    std::ifstream file(path_, std::ios::in | std::ios::binary);
    std::vector<Alumn> output;
    Alumn record;
    if (file.is_open()) {
        bool first = true;
        while (!file.eof()) {
            if(first) {
                first = !first;
                continue;
            }
            record = Alumn();
            file.read((char*)&record, 41);
            output.push_back(record);
        }
        file.close();
    }
    return output;
}
void FixedRecord::add(Alumn record) {
    std::ofstream file(path_, std::ios::app | std::ios::binary);
    if (!file.is_open()) throw("The file was not opened.");
    file.write((char*)&record, sizeof(Alumn));
    file.close();
}
Alumn FixedRecord::readRecord(int pos) {
    std::ifstream file(path_, std::ios::binary);
    if (!file.is_open()) throw std::invalid_argument("No se pudo abrir el archivo");
    Alumn record;
    file.seekg(pos * sizeof(Alumn), std::ios::beg);  // fixed length record
    file.read((char*)&record, sizeof(Alumn));
    file.close();
    return record;
}
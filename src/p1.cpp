#include "p1.h"

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

void FixedRecord::add(Alumn record) {
    std::ofstream file(path_, std::ios::app | std::ios::binary);
    if (!file.is_open()) throw("The file was not opened.");
    file.write((char*)&record, sizeof(Alumn));
    file.close();
}

/* PRIVATE FUNCTIONS OF FIXED RECORD */
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

#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

using namespace std;

struct Alumno {
  char codigo[5];
  char nombre[11];
  char apellidos[20];
  char carrera[15];
};

class FixedRecord {
private:
  string path;
public:
  FixedRecord(string path);
  vector<Alumno> load();
  void add(Alumno record);
  Alumno readRecord(int pos);
};

FixedRecord::FixedRecord(string path) {
  if (path.size() <= 0) throw invalid_argument("The path value is empty or is not valid directory.");
  this->path = path; 
}

int main() {
  return(0);
}

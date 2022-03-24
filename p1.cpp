#include <fstream>
#include <iostream>
#include <string>
#include <vector>
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
    char delimeter;

   public:
    FixedRecord(string path, char delimeter)
        : path(path), delimeter(delimeter){};
    ~FixedRecord() = default;
    vector<Alumno> load() {
        /* Cantidad de espacios definidos para cada atributo */
        vector<Alumno> output;
        vector<int> espacios = {5, 11, 20, 15};

        // Importar el texto del file
        fstream file(path);
        if (file.is_open()) {
            string linea;
            bool first = true;
            while (getline(file, linea)) {
                // If the line is header fields
                if (first) {
                    first = !first;
                    continue;
                }

                // Parsear cada uno y generar un vector de vectores
                vector<string> parse = parser(linea, espacios);

                // Crear una instancia para cada record e insertar en el output
                // (considerar si es mayor que el espacio establecido)
                Alumno alumn = insertToAlumno(parse);
                output.push_back(alumn);
            }
        }
        // Cerrar el archivo
        file.close();
        // return el vector de alumnso
        return output;
    };
    void add(Alumno record) {
        // Crear un string de cada instancia
        string line;

        // Abrir el archivo
        fstream file(path, ios::app);

        // Insertar valores
        line += '\n"' + record.codigo + '",';
        line += '"' + record.nombre + '",';
        line += '"' + record.apellidos + '",';
        line += '"' + record.carrera;

        // insert en el archivo como append
        if (file.is_open()) {
            file.write(line.c_str(), sizeof(line));

            // Cerrar el archivo
            file.close();
        }
    };
    Alumno readRecord(int pos) {
        if (pos < 0) throw("The pos is not a valid input");
        fstream file(path);
        vector<int> espacios = {5, 11, 20, 15};
        if (file.is_open()) {
            string line;
            int i = 0;
            while (getline(file, line)) {
                if (i == pos) {
                    vector<string> parse = parser(line, espacios);
                    Alumno alumn = insertToAlumno(parse);
                    return alumn;
                }
            }
            throw("The pos is excedeed of number of records");
        }
    };

   private:
    vector<string> parser(string line, vector<int> espacios) {
        vector<string> output(espacios.size());
        int curr = -1;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '\\') {
                output[curr] += line[i + 1];
                i++;
            } else if (line[i] == '"' && line[i + 1] == ',') {
                curr++;
                i += 2;
                continue;
            } else if (line[i] == '"') {
                curr++;
                continue;
            } else {
                output[curr] += line[i];
            }
        }
        return output;
    }
    Alumno insertToAlumno(vector<string> attributes) {
        if (attributes.size() != 4)
            throw(
                "Error, attributes vector size is not same of class "
                "attributes.");
        Alumno output;
        strcpy(output.codigo, attributes[0].c_str());
        strcpy(output.nombre, attributes[1].c_str());
        strcpy(output.apellidos, attributes[2].c_str());
        strcpy(output.carrera, attributes[3].c_str());
        return output;
    }
};

int main() { return 0; }
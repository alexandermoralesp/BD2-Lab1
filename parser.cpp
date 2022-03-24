#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


/**
 * @brief 
 * 
 * @param line 
 * @param n number of attributes
 * @return vector<string> 
 */
vector<string> parser(string line, int n) {
    vector<string> output(n);
    int curr = -1;
    for(int i = 0; i <line.size();i++) {
        if(line[i] == '\\') {
            output[curr] += line[i+1];
            i++;
        } else if(line[i] == '"' && line[i+1] == ',') {
            curr++;
            i += 2;
            continue;
        }else if (line[i] == '"') {
            curr++;
            continue;
        }else {
            output[curr] += line[i];
        }
    }
    return output;
}
int main() {
    // string line = "\"12345\",\"Alexander\",\"Morales Panitz\",\"Ciencia de la Computacion\"\"";
    fstream file("./testdata.txt");
    string fline;
    getline(file, fline);
    // cout << line[line.size() - 1] << endl;
    // cout << fline[fline.size() - 1] << endl;
    file.close();
    cout << fline << endl;
    vector<string> values = parser(fline, 4);
    for (size_t i = 0; i < values.size(); i++)
    {
        cout << values[i] << "|";
    }
    // cout << file.rdbuf();
}
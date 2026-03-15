#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string ReadingContent(const string& FileName) {
    ifstream in(FileName);
    if (!in.is_open()) {
        cerr << "file not found: " << FileName << endl;
        exit(1);
    }
    return FileName;
}

vector<string> ProcessData(const string& fileName) {
    ifstream in(fileName);
    string line;
    vector<string> result;

    while (getline(in, line)) {
        result.push_back(line);
    }
    return result;
}

vector<string> TurnOverTheWords(vector<string> lines) {
    for (string &word : lines) {
        reverse(word.begin(), word.end());
    }
    return lines;
}

void WriteData(const vector<string>& lines) {
    ofstream out("result");

    for (string word : lines) {
        out << word << endl;
        cout << word << " ";
    }
}

int main(int argc, char** argv) {

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string fileName = argv[1];

    string lines = ReadingContent(fileName);
    vector<string> data = ProcessData(lines);
    vector<string> words = TurnOverTheWords(data);

    WriteData(words);

    return 0;
}
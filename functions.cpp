#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> search() {
    vector<string> v;
    ifstream in("searcher");
    string line, word;

    if (in.is_open()) {
        cout<<"file is open"<<endl;
        while (getline(in, line)) {
            word = "";
            for (char c : line) {
                if (c != ' ')
                    word += c;
                else if (!word.empty()) {
                    v.push_back(word);
                    word = "";
                }
            }
            if (!word.empty()) {
                v.push_back(word);
            }
        }
    }

    return v; 
}

int finding() {
    vector<string> v = search();

    int resultIndex = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].size() > v[resultIndex].size()) {
            resultIndex = i;
        }
    }

    

    return resultIndex; 
}

int main(int argc, char* argv[]) {
    search();
    finding();

    return 0;
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> search() {
    ifstream in("searcher");
    if(in.is_open()){
        cout<<"file is open"<<endl;
    }
    vector<string> v;
    string sos, word;

    while (getline(in, sos)) {
        for (char s : sos) {
            if (s != ' ') word += s;
            else if (!word.empty()) {
                v.push_back(word);
                word="";
            }
        }
        if (!word.empty()) {
            v.push_back(word);
            word.clear();
        }
    }

    return v; 
}

string finding(const vector<string>& v) {
    int result = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].size() > v[result].size()) {
            result = i;
        }
    }
    return v[result];
    
}

int main() {
    vector<string> result = search();
    cout << finding(result)<<endl;
}

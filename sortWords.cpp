#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

/*
*reads and check is file open.
*@return fileName which is shows his state
*/
string reading(const string& fileName) {
    ifstream in(fileName);
    if (!in.is_open() ) {
        cout << "File is not open" << endl;
    }
    return fileName;
}

/*
*reads and also writes into vector result.
* @return vector of words from the lines.
*/
vector <string> processData(const string& fileName) {
    string word;
    ifstream in(fileName);
    vector <string> result;
    while (in >> word) {
        result.push_back(word);
    }
    return result;
}

/*
*Function is created for paste it into sortWords and to did code more readable.
*/
int compareWords (string w1, string w2) {
    if (w1 < w2) {
        return -1;
    }
    if (w1 > w2) {
        return +1;
    }
    if (w1 == w2) {
        return 0;
    }
    return 0;
}
/*
*The function uses an bubble algorithm and compares words between and if the condition is met swap them.
*@returns sorted file.
*/
vector <string> sortWords(vector <string> words) {
    int n = words.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareWords(words[j], words[j + 1]) > 0) {
                    swap(words[j], words[j + 1]);
            }         
        }   
    }
    return words;
}

/* 
 *The function takes a variable named lines as an argument.
 * works with file name and writes the result into it.
 */
void WriteData(const vector<string>& lines) {
    ofstream out("result");
    for (string word: lines) {  
        out << word << endl;
        cout << word << endl;
    }
}
int main(int argc,char**argv ) {
    if (argc != 2) {
        cout << "Usage:" << argv[0] << "<filename>" << endl;
        return 1;
    }
   
    string fileName = argv[1];
    string read = reading(fileName);
    vector <string> data = processData(read);
    vector <string> sort = sortWords(data);
    WriteData(sort);
}

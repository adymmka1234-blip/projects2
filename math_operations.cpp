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
*In first cicle after each iteration removes on one place
*second cicle has the same idea but he is comparing first and the second to him word
*if in first word has more letters and letters come first they change places and cicle will do it till the end 
*/
vector <string> sortWords(vector <string> lines) {
    int n = lines.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lines[j] > lines[j + 1])
                swap(lines[j], lines[j + 1]);
        }
    }
    return lines;
}

/* 
 *The function takes a variable named lines as an argument
 * works with file name and writes the result into it
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
   
    string fileName= argv[1];
    string read = reading(fileName);
    vector <string> data = processData(read);
    vector <string> sort = sortWords(data);
    WriteData(sort);
}

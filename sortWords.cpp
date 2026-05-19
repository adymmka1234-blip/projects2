#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib> 
#include <cctype>
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


/*it is created for numbers like an assistant without here i can not work with numbers and ort at the right way*/

int isNumbers(string word) {
    for (char c : word) {
        if (!isdigit(c)) {
            return 0; 
        }
    }
     return 1;
}

/*compares numbers and words to seat them in the right way:sorted numbers come first and then sorted words*/

int compare(string w1, string w2) {
      if (isNumbers(w1) && isNumbers(w2)) {

    if (stoi(w1) < stoi(w2)) {
        return -1;
    }

    if (stoi(w1) > stoi(w2)) {
        return +1;
    }
}
if (!isNumbers(w1) && !isNumbers(w2)) {
    if ((w1) < (w2)) {
        return -1;
    }
    if ((w1) > (w2)) {
        return +1;
    }
}
    if (!isNumbers(w1) && isNumbers(w2)) {
        return +1;
    }
    if (isNumbers(w1) && !isNumbers(w2)) {
        return -1;
    }
    return 0;
}

/*
*The function uses an bubble algorithm and compares words and numbers between and if the condition is met swap them.
*@returns sorted file.
*/
    vector <string> sortWords(vector <string> words) {
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (compare(words[j], words[j + 1]) > 0) {
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
int main(int argc,char**argv) {
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

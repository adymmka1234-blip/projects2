
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
string line;
ifstream in(fileName);
vector <string> result;
    while (getline (in, line)) {
        result.push_back(line);
    }
    return result;
}



/*
*In first cicle after each iteration removes on one place
*second cicle has the same idea but he is comparing first and the second to him word
*if in first word has more letters and letters come first they change places and cicle will do it till the end 
*/
vector <string> sortWords(vector <string> lines ) {
    vector <string> result;
    for (string line : lines) {
        istringstream iss(line);
        vector<string> words;
        string word;
        
       
        while (iss >> word) {
            words.push_back(word);
        }
        sort(words.begin(), words.end());

        
        string sortedLine = "";
        for (int i = 0; i < words.size(); i++) {
            sortedLine += words[i];
            if (i != words.size() - 1) {
                sortedLine += " ";
            }
        }

        result.push_back(sortedLine);
    }

    return result;
}


/* 
 *The function takes a variable named lines as an argument
 * works with file name and writes the result into it
 */
void WriteData(const vector<string>& lines) {
    ofstream out("result");
    for (string word: lines) {  
        out << word << endl;
        cout << word << "" << endl;
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
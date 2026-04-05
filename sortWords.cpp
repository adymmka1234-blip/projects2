#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

string reading (const string& fileName) {
ifstream in(fileName);
if (!in.is_open() ) {
    cout << "File is not open" << endl;
}
return fileName;
}

vector <string> processData(const string& fileName) {
string line;
ifstream in(fileName);
vector <string> result;
while (getline(in, line)) {
    result.push_back(line);
}
return result;

}
vector <string> SortWords(vector <string> lines ) {
string word;
int n = lines.size();
for (int i =0; i<n-1;i++) {
    for (int j=0;j< n - i - 1;j++) {
        if (lines[j]>lines[j+1]){
            swap (lines[j], lines[j+1]);
        }
    }
   
}
return lines;
}
void WriteData(const vector<string>& lines) {
    ofstream out("result");
    for (string word: lines) {
        out<<word<<endl;
        cout<<word << ""<<endl;
    }
}
int main (int argc,char**argv ) {
    if (argc!= 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
}
string fileName=argv[1];
string read = reading(fileName);
vector <string> data=processData(read);
vector <string> sort=SortWords(data);
WriteData(sort);
}

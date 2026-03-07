#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <algorithm>

vector <string> ReadingAllLines(const string& fileName,const vector<string> & lines){
ifstream in(fileName);
ofstream out ("result");
vector <string> result;

string line;

if (!in.is_open()) {
        cerr << "file not found: " << fileName<< endl;
}    
while(getline(in,line)){
result.push_back(line);
}
    for(const string& line:lines){
    for(string word:lines){
 for(int i = word.length() - 1; i >= 0; i--) {
    out << word[i];
}
    }
    }
   return result;
}
           
int main(int argc,char**argv){
     string fileName=argv[1];
    if(argc!=2){
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
   
   vector <string> lines=ReadingAllLines(fileName,lines);
   for(string word:lines){
    cout << word << " ";

 }  
 return 0;  
}

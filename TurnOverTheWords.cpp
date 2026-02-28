#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include <algorithm>


vector <string> ReadingAllLines(const string& fileName,const vector<string> & lines){
ifstream in(fileName);
vector <string> result;
string word;
string line;
if (!in.is_open()) {
        cerr << "file not found: " << fileName<< endl;
}    
while(getline(in,line)){
        for (char character : line) {
            if (character != ' ' ) {
                word += character;
            }
            if(character==' '){
             continue;
            }
    
             else if (!word.empty()) {
                 std::reverse(word.begin(), word.end());
                result.push_back(word);
                word="";
            }
        }}
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
cout << word << "";
return 0;
   }  
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

std::vector<std::string> v;
std::string sos;
std::ifstream in("searcher");
int resultIndex = 0;
string word;

void c(int argc, char* argv[]) {
    if(in.is_open()){
        cout << "файл открытий" << endl;
        while(getline(in, sos)){
           for(char s : sos){
    if(s != ' '){
        word += s;
    } else {
        if(!word.empty()) {
            v.push_back(word);
            word = "";
        }
    }
}

if(!word.empty()) {
    v.push_back(word);
    word = "";
}

            }
        }
       
    }


void finding() {
    for(int i = 1; i < v.size(); i++){
        if(v[i].size() < v[resultIndex].size()){
            continue;
        }
        if(v[i].size() > v[resultIndex].size()){
            resultIndex = i;
        }
    }
   in.close();
}

int main(int argc, char* argv[]) {
    c(argc, argv);

     if (!v.empty()) {
        finding();
        cout << v[resultIndex] << endl;}
    return 0;
    
}
 
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class function{
    public:
    std::vector<std::string> v;
std::string sos;
std::ifstream in;
   
    string word;
    void search(){
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
    }}
}
if(!word.empty()) {
    v.push_back(word);
    word = "";
}
}


}};

class found: public function{
 int resultIndex=0;
 
 public:void finding(){
for(int i = 1; i < v.size(); i++){
        if(v[i].size() < v[resultIndex].size()){
            continue;
        }
        if(v[i].size() > v[resultIndex].size()){
            resultIndex = i;
        }
        if (!v.empty()) {
        
       }
    
     }
     cout << v[resultIndex] << endl;
     

  
    }
    void run1(){
        finding();
    }
};
     int main(int argc, char* argv[]){
     found f;
    f.in.open("searcher");
    f.search();
    f.finding();
    f.in.close();
}

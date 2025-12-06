#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    std::vector<std::string> v;
    std::string sos;
    std::ifstream in("searcher");

    if(in.is_open()){
        cout << "файл открытий" << endl;
        while(getline(in, sos)){
            v.push_back(sos);
        }

        string word;
        for(int i = 0; i < v.size(); i++){
            while(getline(in, sos)){
                for(char s : sos){
                    if(s != ' '){
                        word = s;
                    }
                    if(s == ' '){
                        v.push_back(word);
                    }
                }
            }
        }

        int resultIndex = 0;
        for(int i = 1; i < v.size(); i++){
            if(v[i].size() < v[resultIndex].size()){
                continue;
            }
            if(v[i].size() > v[resultIndex].size()){
                resultIndex = i;
            }
        }
        cout << v[resultIndex] << endl;

        in.close();
    }
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


vector <string> ReadingAllFiles(){
    string line;
vector <string> words;
ifstream in("searcher");
if(in.is_open()){
    cout<<"File is open"<<endl;}
while(getline(in,line)){
     words.push_back(line);
     
}
return words;
}


int OutputResult(const vector<string> & lines){
    int count=0;
for( const string& line:lines){
for(char Letter:line){
    if(Letter !=' '){
       count++;   
    }

}
}
return count;
}

int main(int argc,char**argv){
vector <string> content=ReadingAllFiles();
int result=OutputResult(content);
cout<<result<<endl;

}






#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;
int main(int argc,char*argv[]){
if(argc<4){
return 1;
}
string command=argv[1];
int a=atoi(argv[2]);
int b=atoi(argv[3]);
if(command =="mul"){
    cout<<a*b<<endl;
}
return 0;
}
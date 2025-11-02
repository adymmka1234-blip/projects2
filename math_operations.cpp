#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

int main(int argc, char* argv[]) {
     
    
    if(argc<4){

        cout<<"Arguments are missing"<<endl;
    }
    
    std::string strA = argv[2];
    std::string str1 = argv[3];
for (char c : strA) {           
    if (!isdigit(c)) {           
        std::cout << "argument incorrect written" << std::endl;
        return 1;               
    }
}
for (char d: str1) {           
    if (!isdigit(d)) {           
        std::cout << "argument incorrect written" << std::endl;
        return 1;               
    }
}
    
   
    
    
    
     string command =argv[1];
    int a=atoi(argv[2]);
    int b = atoi(argv[3]);
    if(command=="add"){
      cout<<a + b<<endl;

    }
    if(command=="div"){
      cout<<a / b<<endl;

    }
    if(command=="mul"){
      cout<<a * b<<endl;

    }
    if(command=="sub"){
      cout<<a-b<<endl;

    }
    
   
    
    if(command !="add" && command !="div" && command 
    !="mul" && command !="sub" ){
    cout<<"command not found"<<endl;
    }
    

    

}










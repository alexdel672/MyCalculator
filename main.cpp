#include <iostream>
#include <stack>
using namespace std;

bool operand(char userIn){
    bool isOp = false;
    if(userIn == '0','1','2','3','4','5','6','7','8','9'){
        isOp = true;
    }
    return isOp;
}
bool isNum(char userIn){
    bool isNum = false;

}
int getAnswer(string user){
    stack<int> s; 

    for(int i = 0; i < user.length; i++){
    	
    }
    
}

int main() {
cout<<"Enter expression to evaluate"<<endl;
string userIn="";
getline(cin,userIn);

int answer = getAnswer(userIn);


    return 0;
}
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool isOp(char);
bool isNum(char);
bool isBal(string);
int higherPrec(char c);
string convertPost(string);

bool isBal(string userIn){

    stack<char> s;
    char par;
    char check;
    for(int i = 0; i < userIn.length(); i++){
        par = userIn[i];
        if(par == '('){
            s.push(par);
        }else if(par == ')'){
            if(s.empty()) {
                return false;
            } else{
                check = s.top();
                s.pop();
                if(check!='(')
                    return false;
            }
        }
    }
    return (s.empty());
}

bool isOp(char i){
    switch(i){
        case '^': return true;
        case '*': return true;
        case '/': return true;
        case '+': return true;
        case '-': return true;
        default: return false;
    }


}
bool isNum(char i){
if(i <= '9' && i >= '0'){
    return true;
}else{
    return false;
}
}
int higherPrec(char i){
    switch(i) {
        case '^': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return false;
    }
}
string convertPost(string userIn){
    stack <char> s;
    stack <char> post;
    int addToPost =0;
    string post1;
    int point = 0;
    while(point != userIn.length()){
        if(userIn[point] == ' '){
            point++;
        }
        else if(isNum(userIn[point])){
            addToPost = userIn[point]-'0';
            while(isNum(userIn[point+1])){

                addToPost = addToPost*10 + (userIn[point+1] -'0');
                point++;
            }
            post.push(addToPost);
            addToPost = 0;
        }else if(isOp(userIn[point])){
            if(s.empty()){
                s.push(userIn[point]);
            }else {
                bool keepPop = true;
                while(s.top()!='(' || keepPop || !s.empty()){
                    int v1 = higherPrec(userIn[point]);
                    int v2 = higherPrec(s.top());
                    if(v1 >= v2){
                        s.push(userIn[point]);
                        keepPop = false;
                    }else{
                        post.push(s.top());
                        s.pop();
                    }
                }


            }
        }
        else if(userIn[point] == '('){
            s.push(userIn[point]);
        }
        else if(userIn[point] == ')'){
            while(!s.empty() && s.top() != '('){
               post.push(s.top());
               s.pop();
            }
        }
        point++;
    }

}

int main() {

    cout<<"Enter expression to evaluate"<<endl;
    string userIn="";
    getline(cin,userIn);
    bool result  = isBal(userIn);
    if(result){
        convertPost(userIn);
    }else{
        cout<<"Expression is not balanced"<<endl;
    }

    return 0;
}
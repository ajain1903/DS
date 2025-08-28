#include <iostream>
#include <string>
struct Stack
{
    std::string stack;
    int top = -1;
};

void push(char data, Stack &S)
{
    S.top = S.top + 1;
    S.stack[S.top] = data;
}

void pop(Stack &S)
{
    S.top -= 1;
}

void display(Stack &S)
{
    int top = S.top;
    for (int i = 0; i < top + 1; i++)
    {
        std::cout << S.stack[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    Stack s;
    std::string input;
    std::cin>>input;
    
    for (int i = 0; i < input.length(); i++)
    {
        if(input[i]=='{' || input[i]=='(' || input[i]=='['){
            push(input[i],s);
            continue;
        }

        if(input[i]==')' && s.stack[s.top]=='(')
            pop(s);
        else if(input[i]=='}' && s.stack[s.top]=='{')
            pop(s);
        else if(input[i]==']' && s.stack[s.top]=='[')
            pop(s);
        else{
            std::cout<<"false";
            return 0;
        }

    }
    std::cout<<"True";
    return 0;
    
}
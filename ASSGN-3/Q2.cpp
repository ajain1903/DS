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
    for (int i = top; i >= 0; i--)
    {
        std::cout << S.stack[i];
    }
    std::cout << std::endl;
}

int main(){
    std::string input;
    std::cin>>input;

    Stack s;

    for (int i = 0; i < input.length(); i++)
    {
            push(input[i],s);
    }

    display(s);
}
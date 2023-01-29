#include<iostream>
#include<string>

int main() {
    float x,y;
    x=y=0.5;
    std::string expression;
    std::cout<<"Give the Expression:"<<std::endl;
    std::cin>>expression;
    size_t gate = expression.find("+");
    if(gate == 0){
        std::cout<<"Unspecified GATE Expresion";
    }else {
        float p=(x+y-x*y);
        std::cout<<"Switching Activity is "<<p<<std::endl;
        return 0;
    }
};
#include<iostream>
#include<string>

float OR(std::string expression,float x,float y){
    size_t gate = expression.find("OR");
    if(gate == 0){
        std::cout<<"Unspecified GATE Expresion";
    }else {
        float p=(x+y-x*y);
        std::cout<<"Switching Activity is "<<p<<std::endl;
        return p;
    }
};

float AND(std::string expression,float x,float y){
    size_t gate = expression.find("AND");
    if(gate == 0){
        std::cout<<"Unspecified GATE Expresion";
    }else {
        float p=(x*y);
        std::cout<<"Switching Activity is "<<p<<std::endl;
        return p;
    }
};

float NAND(std::string expression,float x,float y){
    size_t gate = expression.find("NAND");
    if(gate == 0){
        std::cout<<"Unspecified GATE Expresion";
    }else {
        float p=(1-x*y);
        std::cout<<"Switching Activity is "<<p<<std::endl;
        return p;
    }
};

float NOR(std::string expression,float x,float y){
    size_t gate = expression.find("NOR");
    if(gate == 0){
        std::cout<<"Unspecified GATE Expresion";
    }else {
        float p;
        p=((1-x)*(1-y));
        std::cout<<"Switching Activity is "<<p<<std::endl;
        return p;
    }
};

float NOT(std::string expression,float x){
    size_t gate = expression.find("NOT");
    if(gate == 0){
        std::cout<<"Unspecified GATE Expresion";
    }else {
        float p=(1-x);
        std::cout<<"Switching Activity is "<<p<<std::endl;
        return p;
    }
};

std::string parser(std::string exp){
    
} 

int main() {
};
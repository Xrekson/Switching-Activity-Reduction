#include<iostream>
#include<string>

float OR(float x,float y){
    {
        float p=(x+y-x*y);
		float sa = p*(1-p);
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        return p;
    }
};

float AND(float x,float y){
    {
        float p=(x*y);
		float sa = p*(1-p);
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        return sa;
    }
};

float NAND(float x,float y){
    {
        float p=(1-x*y);
		float sa = p*(1-p);
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        return sa;
    }
};

float NOR(float x,float y){
    {
        float p;
        p=((1-x)*(1-y));
		float sa = p*(1-p);
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        return sa;
    }
};

float NOT(float x){
    {
        float p=(1-x);
		float sa = p*(1-p);
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        return sa;
    }
};


int main() {
	int choise;
	float x,y;
	std::cout<<"Gate choise:";
	std::cout<<"1-AND, 2-OR, 3-NAND, 4-NOR, 5-NOT"<<std::endl;
	std::cin>>choise;
	do{
	if(choise == 1){
		std::cout<<"Input Probability:"<<std::endl;
		std::cout<<"X:";std::cin>>x;
		std::cout<<"Y:";std::cin>>y;
		AND(x,y);
	}else if(choise == 2){
		std::cout<<"Input Probability:"<<std::endl;
		std::cout<<"X:";std::cin>>x;
		std::cout<<"Y:";std::cin>>y;
		OR(x,y);
	} else if(choise == 3){
		std::cout<<"Input Probability:"<<std::endl;
		std::cout<<"X:";std::cin>>x;
		std::cout<<"Y:";std::cin>>y;
		NAND(x,y);
	}else if(choise == 4){
		std::cout<<"Input Probability:"<<std::endl;
		std::cout<<"X:";std::cin>>x;
		std::cout<<"Y:";std::cin>>y;
		NOR(x,y);
	}else if(choise == 5){
		std::cout<<"Input Probability:"<<std::endl;
		std::cout<<"X:";std::cin>>x;
		NOT(x);
	}
	std::cout<<"1-AND, 2-OR, 3-NAND, 4-NOR, 5-NOT"<<std::endl;
	std::cin>>choise;
	}
	while(choise!=0);
};

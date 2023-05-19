#include <iostream>
#include <fstream>
#include <string>
#include <vector>

float * OR(float x,float y){
    {
        float p=(x+y-x*y);
		float sa = p*(1-p);
        float output[2];
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output[0] = p;
        output[1] = sa;
        return output;
    }
};

float * AND(float x,float y){
    {
        float p=(x*y);
		float sa = p*(1-p);
        float output[2];
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output[0] = p;
        output[1] = sa;
        return output;
    }
};

float * NAND(float x,float y){
    {
        float p=(1-x*y);
		float sa = p*(1-p);
        float output[2];
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output[0] = p;
        output[1] = sa;
        return output;
    }
};

float * NOR(float x,float y){
    {
        float p;
        p=((1-x)*(1-y));
		float sa = p*(1-p);
        float output[2];
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output[0] = p;
        output[1] = sa;
        return output;
    }
};

float * NOT(float x){
    {
        float p=(1-x);
		float sa = p*(1-p);
        float output[2];
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output[0] = p;
        output[1] = sa;
        return output;
    }
};

int main() 
{
    std::fstream inFile,outFile;
    std::string inputfile,outputfile;
    std::string line;
    std::vector<std::string> linesin,linesout;
    int InputNum;
    inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    outFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    std::cout << "Enter the input file name to open: ";
    std::cin >> inputfile;
    std::cout << "Enter the output file name to open: ";
    std::cin >> outputfile;
    inFile.open(inputfile.c_str(), std::fstream::in);
    outFile.open(outputfile.c_str(), std::fstream::in);
    int count1 = 0;
    int count0 = 0;
    if (inFile.is_open() == false) {
        std::cout << "ERROR: not able to open" << inputfile << std::endl;}
    else {
        while(!inFile.eof()){
            getline(inFile, line);
            linesin.push_back(line);
            std::cout << "Input = " << line << std::endl;
        }
    }
    if (outFile.is_open() == false) {
        std::cout << "ERROR: not able to open " << outputfile << std::endl;}
    else {
        while(!outFile.eof()){
            getline(outFile, line);
            linesout.push_back(line);
            std::cout << "Output = " << line << std::endl;
        }
    }
    while(linesout[count1][0] == 1){
        count1++;
    }


/* int main() {
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
}; */

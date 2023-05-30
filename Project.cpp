#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

std::vector<float> OR(float x,float y){
    {
        float p=(x+y-x*y);
		float sa = p*(1-p);
        std::vector<float> output;
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output.push_back(p);
        output.push_back(sa);
        return output;
    }
};

std::vector<float> AND(float x,float y){
    {
        float p=(x*y);
		float sa = p*(1-p);
        std::vector<float> output;
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output.push_back(p);
        output.push_back(sa);
        return output;
    }
};

std::vector<float> NAND(float x,float y){
    {
        float p=(1-x*y);
		float sa = p*(1-p);
        std::vector<float> output;
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output.push_back(p);
        output.push_back(sa);
        return output;
    }
};

std::vector<float> NOR(float x,float y){
    {
        float p;
        p=((1-x)*(1-y));
		float sa = p*(1-p);
        std::vector<float> output;
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output.push_back(p);
        output.push_back(sa);
        return output;
    }
};

std::vector<float> NOT(float x){
    {
        float p=(1-x);
		float sa = p*(1-p);
        std::vector<float> output;
		std::cout<<"Probability is "<<p<<std::endl;
        std::cout<<"Switching Activity is "<<sa<<std::endl;
        output.push_back(p);
        output.push_back(sa);
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
    inputfile = "input1.txt";outputfile = "output1.txt";
    //std::cout << "Enter the input file name to open: ";
    //std::cin >> inputfile;
    //std::cout << "Enter the output file name to open: ";
    //std::cin >> outputfile;
    inFile.open(inputfile.c_str(), std::fstream::in);
    outFile.open(outputfile.c_str(), std::fstream::in);
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
    std::vector<int> output1[linesout[0].length()-1];
    std::cout<< linesout.size() << std::endl;
    std::cout<< linesout[0].length() << std::endl;
    int n=0;
    while(n!=2){
        for(int i=0;i<linesout.size();i++){
            if(linesout[i][n]=='1'){
                output1[n].push_back(i);
            }
        }
        n++;
    }
    std::vector<int> input[]
    for(int i=0;i<linesout[0].length()-1;i++)
    {
        std::cout<<"Output for f"<< i <<std::endl;
        for (auto j = output1[i].begin(); j != output1[i].end(); ++j)
        std::cout << *j << " " << std::endl;
    }
    for(int i = 0;i<linesin.size();i++){
        for(int j=0;j<linesin[i].length();j++){
            if(linesin[i][j]=='1')
        }
    }

};
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

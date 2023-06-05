#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

long double OR(long double x,long double y){
    {
        long double p=(x+y-x*y);
        return p;
    }
};

long double AND(long double x,long double y){
    {
        long double p=(x*y);
        return p;
    }
};

long double NAND(long double x,long double y){
    {
        long double p=(1-x*y);
        return p;
    }
};

long double NOR(long double x,long double y){
    {
        long double p;
        p=((1-x)*(1-y));
        return p;
    }
};

long double NOT(long double x){
    {
        long double p=(1-x);
        return p;
    }
};

int main() 
{
    std::fstream inFile,outFile;
    std::string inputfile,outputfile;
    std::string line;
    std::vector<int> number;
    std::vector<std::vector<int>> drain;
    std::vector<std::vector<std::vector<int>>> merge;
    std::vector<std::string> linesin,linesout;
    int InputNum=0;
    inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    outFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    inputfile = "input2.txt";outputfile = "output2.txt";
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
        }
    }
    if (outFile.is_open() == false) {
        std::cout << "ERROR: not able to open " << outputfile << std::endl;}
    else {
        while(!outFile.eof()){
            getline(outFile, line);
            linesout.push_back(line);
        }
    }
    std::vector<std::vector<int>> output1;
    for(int n=0;n<linesout[0].length()-1;n++){
        for(int i=0;i<linesout.size();i++){
            if(linesout[i][n]=='1'){
                number.push_back(i);
            }
        }
        output1.push_back(number);
        number.clear();
    }
    for(int i=0;i<output1.size();i++)
    {
        std::cout<<"Output for f"<< i <<std::endl;
        for (auto j = output1[i].begin(); j != output1[i].end(); ++j)
        std::cout << *j << " " << std::endl;
    }
    std::vector<std::vector<int>> numbers;
    for(int i = 0;i<linesin.size();i++){
        for(int j=0;j<linesin[0].length();j++){
            if(linesin[i][j]=='1'){
                number.push_back(j);
            }else if(linesin[i][j]=='0'){
                int l=0-j;
                number.push_back(l);
            }
        }
        numbers.push_back(number);
        number.clear();
    }
    for(int i=0;i<numbers.size();i++)
    {
        std::cout<<"Input for f"<< i <<std::endl;
        for (auto j = numbers[i].begin(); j != numbers[i].end(); ++j)
        std::cout << *j << " " << std::endl;
    }
    for(int i=0;i<output1.size();i++){
        InputNum=0;
        for(int j = 0;j<output1[i].size(),InputNum<numbers.size();InputNum++){
            if(output1[i][j]==InputNum){
                drain.push_back(numbers[InputNum]);
                j++;
            }
        }
        merge.push_back(drain);
        drain.clear();
    }
    for(int i=0;i<merge.size();i++)
    {
        std::cout<<"Merge for f"<< i <<std::endl;
        for (int j=0;j<merge[i].size();j++){
            std::cout<<"Input Number "<<j<<std::endl;
            for(auto k = merge[i][j].begin(); k != merge[i][j].end();k++){
                std::cout<< *k <<" ";
            }
        std::cout<<""<<std::endl;
        }
    }

};
/* int main() {
	int choise;
	long double x,y;
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

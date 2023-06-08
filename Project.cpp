#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::vector<std::vector<long double>>> reden;
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
std::vector<long double> branchAND(std::vector<long double> inden){
    auto n = inden.begin();
    long double p1,p2,a,b;
    std::vector<long double> result;
    while(n!=inden.end()){
        if(n==inden.begin()){
            p1=*n;
            n++;
        }else if(*(n-1)==p1 || p1==AND(a,b)){
            p2=*n;
            if(p1<0){
                a=p1*(-1);
            }else{
                a=p1;
            }
            if(p2<0){
                b=p2*(-1);
            }else{
                b=p2;
            }
            p1=AND(a,b);
            result.push_back(p1);
            n++;
        }
    }
    return result;
};

std::vector<long double> branchOR(std::vector<long double> inden){
    auto n = inden.begin();
    long double p1,p2,a,b;
    std::vector<long double> result;
    while(n!=inden.end()){
        if(n==inden.begin()){
            p1=*n;
            n++;
        }else if(*(n-1)==p1 || p1==OR(a,b)){
            p2=*n;
            a=p1;
            b=p2;
            p1=OR(a,b);
            result.push_back(p1);
            n++;
        }
    }
    return result;
};

void SA(std::vector<std::vector<std::vector<long double>>> list){
    std::vector<std::vector<std::vector<long double>>> ult;
    std::vector<std::vector<long double>> result;
    std::vector<long double> base;
    int r=0;
    for(int i=0;i<list.size();i++)
    {
        for (int j=0;j<list[i].size();j++){
            result.push_back(branchAND(list[i][j]));
        }
        reden.push_back(result);
        ult.push_back(result);
        result.clear();
    }
    for(int i=0;i<ult.size();i++)
    {
        for (int j=0;j<ult[i].size();j++){
            base.push_back(ult[i][j][ult[i][j].size()-1]);
        }
        reden[i].push_back(base);
        result.push_back(branchOR(base));
        base.clear();
    }
    for(int i=0;i<result.size();i++)
    {
        if(result[i].size()>1){
        do{
            base=branchOR(result[i]);
            for(auto j = base.begin();j!=base.end();j++){
                std::cout<<*j<<" ";
            }
            printf("\n");
            result[i]=base;
            reden[i].push_back(base);
        }while(result[i].size()!=1);
    }
    }
    for(int i=0;i<result.size();i++){
        std::cout<<"At the end Switching-Activity for f"<<i<<":";
        for(auto k = result[i].begin(); k != result[i].end();k++){
                std::cout<< *k <<" ";
            }
            printf("\n");
    }
    
};

int main() 
{
    std::fstream inFile,outFile;
    std::string inputfile,outputfile;
    std::string line;
    long double brain;
    std::vector<int> number;
    std::vector<long double> bane;
    std::vector<std::vector<long double>> drain;
    std::vector<std::vector<std::vector<long double>>> merge;
    std::vector<std::string> linesin,linesout;
    int InputNum,notnum;
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
    for(int n=0;n<linesout[0].length();n++){
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
    std::vector<std::vector<long double>> numbers;
    for(int i = 0;i<linesin.size();i++){
        for(int j=0;j<linesin[0].length();j++){
            if(linesin[i][j]=='1'){
                bane.push_back(0.5l);
            }else if(linesin[i][j]=='0'){
                bane.push_back(-0.5l);
            }
        }
        numbers.push_back(bane);
        bane.clear();
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
        notnum=0;
        std::cout<<"Merge for f"<< i <<std::endl;
        for (int j=0;j<merge[i].size();j++){
            std::cout<<"Input Number "<<j<<std::endl;
            for(auto k = merge[i][j].begin(); k != merge[i][j].end();k++){
                std::cout<< *k <<" ";
                if(*k<0){
                    notnum++;
                }
            }
        std::cout<<""<<std::endl;
        }
        number.push_back(notnum);
    }
    SA(merge);
    for(int i=0;i<reden.size();i++)
    {
        brain=0;
        std::cout<<"Total Switching-Activity for f"<< i <<std::endl;
        for (int j=0;j<reden[i].size();j++){
            for(auto k = reden[i][j].begin(); k != reden[i][j].end();k++){
                brain+=(*k)*(1-(*k));
            }
        }
        brain+=(number[i]*0.25);
        std::cout<<brain;
        bane.push_back(brain);
        printf("\n");
    }
};

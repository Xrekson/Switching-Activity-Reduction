#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <string>
long int timer = 0;
std::vector<std::vector<float>> reden;
std::vector<float> red;
float OR(float x, float y){
    {float p = (x + y - (x * y));
return p;
}
}
;

float AND(float x, float y){
    {float p = (x * y);
return p;
}
}
;

float NAND(float x, float y){
    {float p = (1 - x * y);
return p;
}
}
;

float NOR(float x, float y){
    {float p;
p = ((1 - x) * (1 - y));
return p;
}
}
;

float NOT(float x){
    {float p = (1 - x);
return p;
}
}
;
std::vector<float> branchAND(std::vector<float> inden)
{
    auto n = inden.begin();
    float p1, p2, a, b;
    std::vector<float> result;
    while (n != inden.end())
    {
        if (n == inden.begin())
        {
            p1 = *n;
            n++;
        }
        else if (*(n - 1) == p1 || p1 == AND(a, b))
        {
            p2 = *n;
            if (p1 < 0)
            {
                a = p1 * (-1);
            }
            else
            {
                a = p1;
            }
            if (p2 < 0)
            {
                b = p2 * (-1);
            }
            else
            {
                b = p2;
            }
            p1 = AND(a, b);
            result.push_back(p1);
            n++;
        }
    }
    return result;
};

std::vector<float> branchOR(std::vector<float> inden)
{
    auto n = inden.begin();
    float p1, p2, a, b;
    std::vector<float> result;
    while (n != inden.end())
    {
        if (n == inden.begin())
        {
            p1 = *n;
            n++;
        }
        else if (*(n - 1) == p1 || p1 == OR(a, b))
        {
            p2 = *n;
            a = p1;
            b = p2;
            p1 = OR(a, b);
            result.push_back(p1);
            n++;
        }
    }
    return result;
};

void SA(std::vector<std::vector<std::vector<float>>> list)
{
    std::vector<std::vector<std::vector<float>>> ult;
    std::vector<std::vector<float>> result;
    std::vector<float> base, tin;
    long int r = 0;
    for (long int i = 0; i < list.size(); i++)
    {
        for (long int j = 0; j < list[i].size(); j++)
        {
            result.push_back(branchAND(list[i][j]));
            base = branchAND(list[i][j]);
            tin.insert(tin.end(), base.begin(), base.end());
        }
        ult.push_back(result);
        reden.push_back(tin);
        tin.clear();
        result.clear();
        base.clear();
    }
    for (long int i = 0; i < ult.size(); i++)
    {
        for (long int j = 0; j < ult[i].size(); j++)
        {
            base.push_back(ult[i][j][ult[i][j].size() - 1]);
        }
        result.push_back(branchOR(base));
        base.clear();
    }
    for (long int i = 0; i < result.size(); i++)
    {
        for (auto k = result[i].begin(); k != result[i].end(); k++)
        {
            reden[i].push_back(*k);
        }
    }
};

int main(int argc, char *argv[])
{
    std::fstream inFile, outFile, result;
    std::string inputfile, outputfile;
    std::string line;
    float brain, sum;
    std::vector<long int> number;
    std::vector<float> bane;
    std::vector<std::vector<float>> drain;
    std::vector<std::vector<std::vector<float>>> merge;
    std::vector<std::string> linesin, linesout;
    clock_t start = clock();
    long int InputNum, notnum;
    for (int i = 1; i < argc; i++)
    {
        inputfile = argv[i];
        inputfile += "1.txt";
        outputfile = argv[i];
        outputfile += "2.txt";
        try
        {
            inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            outFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            inFile.open(inputfile.c_str(), std::fstream::in);
            outFile.open(outputfile.c_str(), std::fstream::in);
            if (inFile.is_open() == false)
            {
                std::cout << "ERROR: not able to open" << inputfile << std::endl;
            }
            else
            {
                while (!inFile.eof())
                {
                    getline(inFile, line);
                    linesin.push_back(line);
                }
            }
            if (outFile.is_open() == false)
            {
                std::cout << "ERROR: not able to open " << outputfile << std::endl;
            }
            else
            {
                while (!outFile.eof())
                {
                    getline(outFile, line);
                    linesout.push_back(line);
                }
            }
            std::vector<std::vector<long int>> output1;
            for (long int n = 0; n < linesout[0].length(); n++)
            {
                for (long int i = 0; i < linesout.size(); i++)
                {
                    if (linesout[i][n] == '1')
                    {
                        number.push_back(i);
                    }
                }
                output1.push_back(number);
                number.clear();
            }
            std::vector<std::vector<float>> numbers;
            for (long int i = 0; i < linesin.size(); i++)
            {
                for (long int j = 0; j < linesin[0].length(); j++)
                {
                    if (linesin[i][j] == '1')
                    {
                        bane.push_back(0.5l);
                    }
                    else if (linesin[i][j] == '0')
                    {
                        bane.push_back(-0.5l);
                    }
                }
                numbers.push_back(bane);
                bane.clear();
            }
            for (long int i = 0; i < output1.size(); i++)
            {
                InputNum = 0;
                for (long int j = 0; j < output1[i].size(), InputNum < numbers.size(); InputNum++)
                {
                    if (output1[i][j] == InputNum)
                    {
                        drain.push_back(numbers[InputNum]);
                        j++;
                    }
                }
                merge.push_back(drain);
                drain.clear();
            }
            for (long int i = 0; i < merge.size(); i++)
            {
                notnum = 0;
                for (long int j = 0; j < merge[i].size(); j++)
                {
                    for (auto k = merge[i][j].begin(); k != merge[i][j].end(); k++)
                    {
                        if (*k < 0)
                        {
                            notnum++;
                        }
                    }
                }
                number.push_back(notnum);
            }
            SA(merge);
            line.clear();
            InputNum = inputfile.find("1");
            sum = 0;
            line = "Result " + inputfile.substr(0, InputNum) + ".txt";
            result.open(line, std::ios::out);
            for (long int i = 0; i < reden.size(); i++)
            {
                brain = 0;
                result << "Switching-Activity for f" << i << ": ";
                for (long int j = 0; j < reden[i].size(); j++)
                {
                    brain += (reden[i][j]) * (1 - reden[i][j]);
                }
                brain += number[i] * 0.25;
                result << brain << "\n";
                bane.push_back(brain);
                sum += brain;
            }
            reden.clear();
            clock_t end = clock();
            double elapsed = double(end - start) / CLOCKS_PER_SEC;
            result << "Total Switching-Activity for " << inputfile.substr(0, InputNum) << " :" << sum << "\n";
            result << "Time measured:" << elapsed << " seconds.\n";
            result.close();
            inFile.close();
            outFile.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
};

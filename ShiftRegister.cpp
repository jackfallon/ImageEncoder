#include <iostream>
#include <string>
#include <vector>

#include "ShiftRegister.hpp"


ShiftRegister::ShiftRegister(std::string seed){
    initSeed = seed;
    
    if (initSeed.length() < 16){
        throw std::logic_error("Not enough characters");
    }
    else if (initSeed.length() > 16){
        throw std::logic_error("Too many characters");
    }
    for (size_t i = 0; i < initSeed.length(); i++){
        if (initSeed[i] != '0' && initSeed[i] != '1'){
            throw std::logic_error("Invalid characters entered");
        }
    }
        
}

std::string ShiftRegister::getSeed(){
    return initSeed;
}

int ShiftRegister::step(){
    int firstResult;
    int secondResult;
    int finalResult;
    std::string tempString = initSeed;

    firstResult = tempString[0] ^ tempString[2];
    secondResult = firstResult ^ (tempString[3] - '0');
    finalResult = secondResult ^ (tempString[5] - '0');

    std::string temp;
    for (size_t i = 0; i < initSeed.length() - 1; i++){
        temp.push_back(initSeed[i + 1]);
    }
    temp.push_back(finalResult);
    initSeed = temp;
   
    return finalResult;
}

int ShiftRegister::generate(int k){
    int var = 0;
    int result = 0;
    for (int i = 0; i < k; i++){
        result = step();
        var *= 2;
        var += result;  
    }
    return var;
}

std::ostream& operator<<(std::ostream& outStream, const FibLFSR& lfsr){
    outStream << lfsr.initSeed;
    return outStream;
}

#include "log.h"

#include <iostream>


Log::Log(uint level){
    this->_curLevel = level;
    this->_outfile.open("hnlog.txt", std::ios::out);
}

Log::~Log(){
    this->_outfile.close();
}

void Log::log(std::string text, uint level){
    if (level <= _curLevel){
        std::cout.flush();
        std::cout << "(" << level << ")";
        std::cout << "[" << this->_functionStack.back()->name() << "]>>" << text << std::endl;
        std::cout.flush();

        this->_outfile << "(" << level << ")";
        this->_outfile << "[" << this->_functionStack.back()->name() << "]>>" << text << std::endl;
    }
}

void Log::flush(){
    std::cout.flush();
}

void Log::push(LogFunction *fun){
    this->_functionStack.push_back(fun);
}

void Log::pop(){
    this->_functionStack.pop_back();
}

#include "hnpython.h"

HNPython::HNPython(){
    FUN();
    this->_py_running = false;
}

HNPython::~HNPython(){
    FUN();
    if (this->_py_running){
        LOGW("Python-interpreter is still running, forcing quit");
        this->stopPython();
    }

    //Delete all modules
    int modcount = 0;
    std::map<std::string, PyModule*>::iterator it = this->_modules.begin();
    while (it != this->_modules.end()){
        delete it->second;
        it++;
        modcount++;
    }
    LOGD("Cleaned " + std::to_string(modcount) + " modules from memory!");
}

#pragma once
#ifndef WRAPPER_H
#define WRAPPER_H

#include <functional>
#include <map>
#include <string>
#include "Subject.h"

class Wrapper {
public:
   
    Wrapper(Subject* obj, std::function<std::string(const std::map<std::string, std::string>&)> func);

  
    std::string call(const std::map<std::string, std::string>& args);

private:
    Subject* object;
    std::function<std::string(const std::map<std::string, std::string>&)> method;
};

#endif 


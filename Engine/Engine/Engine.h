#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <string>
#include "Wrapper.h"

class Engine {
public:
   
    void register_command(const std::string& name, Wrapper* wrapper);

   
    std::string execute(const std::string& name, const std::map<std::string, std::string>& args);

private:
    std::map<std::string, Wrapper*> commands;
};

#endif 


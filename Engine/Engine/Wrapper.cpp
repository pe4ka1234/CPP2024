#include "Wrapper.h"

Wrapper::Wrapper(Subject* obj, std::function<std::string(const std::map<std::string, std::string>&)> func)
    : object(obj), method(func) {}

std::string Wrapper::call(const std::map<std::string, std::string>& args) {
    return method(args);
}

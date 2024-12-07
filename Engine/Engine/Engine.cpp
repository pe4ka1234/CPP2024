#include "Engine.h"

void Engine::register_command(const std::string& name, Wrapper* wrapper) {
    commands[name] = wrapper;
}

std::string Engine::execute(const std::string& name, const std::map<std::string, std::string>& args) {
    if (commands.find(name) == commands.end()) {
        return "Error: Command not found.";
    }
    return commands[name]->call(args);
}

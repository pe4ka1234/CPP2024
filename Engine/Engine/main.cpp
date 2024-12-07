#include <iostream>
#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"

int main() {
    
    Subject subj;

   
    Wrapper wrapper(&subj, [&subj](const std::map<std::string, std::string>& args) {
        return subj.f3(args);
        });

   
    Engine engine;

    
    engine.register_command("command1", &wrapper);

  
    std::cout << engine.execute("command1", { {"operation", "replace_word"}, {"file", "example.txt"}, {"old_word", "world"}, {"new_word", "everyone"} }) << std::endl;

    std::cout << engine.execute("command1", { {"operation", "find_phrase"}, {"file", "example.txt"}, {"phrase", "everyone"} }) << std::endl;

    std::cout << engine.execute("command1", { {"operation", "capitalize_words"}, {"file", "example.txt"} }) << std::endl;

    std::cout << engine.execute("command1", { {"operation", "capitalize_sentences"}, {"file", "example.txt"} }) << std::endl;

    std::cout << engine.execute("command1", { {"operation", "number_sentences"}, {"file", "example.txt"} }) << std::endl;

    return 0;
}

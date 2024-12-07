#include "Subject.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <stdexcept>

std::string Subject::read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filename);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Subject::write_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filename);
    }
    file << content;
}

std::string Subject::f3(const std::map<std::string, std::string>& args) {
    if (args.find("file") == args.end()) {
        return "Error: 'file' argument is required.";
    }

    std::string filename = args.at("file");
    std::string operation = args.at("operation");
    std::string text = read_file(filename);

    if (operation == "replace_word") {
        std::string old_word = args.at("old_word");
        std::string new_word = args.at("new_word");
        std::regex word_regex("\\b" + old_word + "\\b");
        text = std::regex_replace(text, word_regex, new_word);

    }
    else if (operation == "find_phrase") {
        std::string phrase = args.at("phrase");
        return (text.find(phrase) != std::string::npos) ? "Found" : "Not Found";

    }
    else if (operation == "capitalize_words") {
        bool capitalize = true;
        for (auto& ch : text) {
            if (std::isspace(ch)) {
                capitalize = true;
            }
            else if (capitalize && std::isalpha(ch)) {
                ch = std::toupper(ch);
                capitalize = false;
            }
        }

    }
    else if (operation == "capitalize_sentences") {
        bool capitalize = true;
        for (auto& ch : text) {
            if (capitalize && std::isalpha(ch)) {
                ch = std::toupper(ch);
                capitalize = false;
            }
            if (ch == '.' || ch == '!' || ch == '?') {
                capitalize = true;
            }
        }

    }
    else if (operation == "number_sentences") {
        std::stringstream stream(text);
        std::string sentence;
        std::string result;
        int counter = 1;

        while (std::getline(stream, sentence, '.')) {
            if (!sentence.empty()) {
                result += std::to_string(counter++) + ". " + sentence + ".\n";
            }
        }
        text = result;

    }
    else {
        return "Error: Unknown operation.";
    }

    write_file(filename, text);
    return "Success: File updated.";
}

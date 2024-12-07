#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <map>

class Subject {
public:
   
    std::string f3(const std::map<std::string, std::string>& args);

private:
    std::string read_file(const std::string& filename);
    void write_file(const std::string& filename, const std::string& content);
};

#endif 

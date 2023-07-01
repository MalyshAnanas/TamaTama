#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void Write(int lineNumber, const std::string& newText) {
    std::fstream file("content/TamaTama.txt", std::ios::in | std::ios::out);
    if (!file) {
        std::cout << "Error" << std::endl;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    if (lineNumber <= -1) {
        lines.push_back(newText);
    }
    else if (lineNumber <= 0 || lineNumber > lines.size()) {
        std::cout << "NoNoNoNo" << std::endl;
        return;
    }
    else {
        lines[lineNumber - 1] = newText;
    }

    file.clear();
    file.seekp(0);
    file.clear();
    for (const auto& line : lines) {
        file << line << std::endl;
    }
    file.close();
}
std:: string Read(int linenumber) {
    std::fstream file("content/TamaTama.txt", std::ios::in | std::ios::out);
    if (!file) {
        std::cout << "Error" << std::endl;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines[linenumber -1];
}
#include <string>
#include <vector>
#include <fstream>
#include <ios>
#pragma once

class FileHandler {
private:
    std::string path;
    bool has_newline(std::string s) {
        return s.find('\n') != std::string::npos;
    }
public:
    FileHandler(std::string path) {
        this->path = path;
    }

    void set_path(std::string path) {
        this->path = path;
    }

    std::string get_path() {
        return this->path;
    }

    std::vector<std::string> read_file() {
        std::ifstream file;
        file.open(get_path());

        if (file.fail()) {
            std::cout << "Oh no! An error occured when trying to open the file";
            return {};
        }

        std::vector<std::string> result;
        std::string line;

        // removes the header
        std::getline(file, line);

        while (std::getline(file, line)) {
            result.push_back(line);
        }

        file.close();

        return result;
    }

    int save_file(std::vector<std::string> lines, std::ios_base::openmode mode = std::ios::out) {
        std::ofstream file;
        file.open(get_path(), mode);

        if (file.fail()) return 1;

        for (std::string line : lines) {
            if (!has_newline(line)) line.push_back('\n');
            file << line;
        }

        file.close();

        return 0;
    }
};
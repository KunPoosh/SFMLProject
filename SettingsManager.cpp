// SettingsManager.cpp
#include "SettingsManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

SettingsManager& SettingsManager::getInstance() {
    static SettingsManager instance;
    return instance;
}

void SettingsManager::loadSettings(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        std::getline(file, englishString);

        std::getline(file, line);
        std::istringstream iss(line);
        int value;
        unlockedCGs.clear();
        while (iss >> value) {
            unlockedCGs.push_back(value != 0);
        }

        if (std::getline(file, line)) {
            std::istringstream iss(line);
            iss >> soundVolume >> musicVolume;
        }
    }
    else {
        std::cout << "Unable to open file for reading" << std::endl;
    }
}

void SettingsManager::saveSettings(const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << englishString << "\n";

        for (bool cg : unlockedCGs) {
            file << (cg ? 1 : 0) << " ";
        }
        file << "\n";

        file << soundVolume << " " << musicVolume << "\n";
    }
    else {
        std::cout << "Unable to open file for writing" << std::endl;
    }
}

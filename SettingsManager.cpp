#include "SettingsManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

SettingsManager& SettingsManager::getInstance() {
    //单例唯一入口
    /*
    负责人: 波波沙

    功能:
        单例的唯一入口

    参数: void

    返回值: SettingsManager&
    */
    //----------------------实现------------------------//

    static SettingsManager instance;
    return instance;
}

void SettingsManager::loadSettings(const std::string& filename) {
    //读取文件
    /*
    负责人: 波波沙

    功能:
        将存档文件的所有数据读入内存

    参数: 
        const std::string& filename //存档文件路径

    返回值: void
    */
    //----------------------实现------------------------//

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

    //进行测试
    printSettings();
}

void SettingsManager::saveSettings(const std::string& filename) {
    //保存文件
    /*
    负责人: 波波沙

    功能:
        将内存中的数据存到文件中保存

    参数:
        const std::string& filename //存档文件路径

    返回值: void
    */
    //----------------------实现------------------------//

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

void SettingsManager::printSettings() const {
    // 测试方法，打印当前设置
    std::cout << "English String: " << englishString << std::endl;
    std::cout << "Unlocked CGs: ";
    for (bool cg : unlockedCGs) {
        std::cout << (cg ? "1" : "0");
    }
    std::cout << std::endl;
    std::cout << "Sound Volume: " << soundVolume << std::endl;
    std::cout << "Music Volume: " << musicVolume << std::endl;
}

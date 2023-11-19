// SettingsManager.hpp
#ifndef SETTINGSMANAGER_HPP
#define SETTINGSMANAGER_HPP

#include <string>
#include <vector>

class SettingsManager {
public:
    static SettingsManager& getInstance();

    void loadSettings(const std::string& filename);
    void saveSettings(const std::string& filename);

    // 公开的成员变量或者getter/setter
    std::string englishString;
    std::vector<bool> unlockedCGs;
    int soundVolume;
    int musicVolume;

private:
    SettingsManager() {} // 私有构造函数
};

#endif // SETTINGSMANAGER_HPP

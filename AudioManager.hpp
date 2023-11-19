#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <list>

// -------------------- 类设计 --------------------
/*
    【音频管理类】
    负责人： 波波沙

    功能：单例模式，存储所有的音频，包括音乐和音效，并且提供播放功能
        1.读取所有的素材
        2.在需要的地方随时使用
*/

class AudioManager {
public:

    //单例的唯一入口
    static AudioManager& getInstance();
    AudioManager(const AudioManager&) = delete;
    void operator=(const AudioManager&) = delete;

    //读取音效,同时设置音效音量初始值
    void loadSound(const std::string& name, const std::string& filename, float volume);
    //播放音效，将播放的音效加入一个列表，使得单个音效可以同时进行多个播放。
    void playSound(const std::string& name);
    //停止播放音效（一般不用，音效都很短）
    void stopSound(const std::string& name);

    //读取音乐，同时设置音乐音量初始值
    void loadMusic(const std::string& name, const std::string& filename, float volume);
    //播放音乐，可选择是否循环播放，播放时如果有正在播放的则进行切换
    void playMusic(const std::string& name, bool loop);
    //停止播放音乐,
    void stopMusic();

    //设置全局音效的音量
    void setSoundVolume(float volume);
    //设置全局音乐的音量
    void setMusicVolume(float volume);

    //更新以销毁播放完毕的音效
    void update();

private:
    //构造方法
    AudioManager();

    //存储所以的音效Buffer
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    //所有的音效
    std::map<std::string, sf::Sound> sounds;
    // 使用 unique_ptr 管理 sf::Music 对象
    std::map<std::string, std::unique_ptr<sf::Music>> music; 
    // 存储每个音效的初始音量
    std::map<std::string, float> initialSoundVolumes; 
    // 存储每个音乐的初始音量
    std::map<std::string, float> initialMusicVolumes; 

    // 指向当前播放的 BGM
    sf::Music* currentBGM = nullptr; 
    // 正在播放的音效列表
    std::list<sf::Sound> playingSounds; 
};

#endif // AUDIOMANAGER_HPP

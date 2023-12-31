#include "AudioManager.hpp"

AudioManager& AudioManager::getInstance() {
    //单例唯一入口。
    /*
    负责人: 波波沙

    功能:
        返回当前单例的引用

    参数: void

    返回值: AudioManager&
    */
    //----------------------实现------------------------//

    static AudioManager instance;
    return instance;
}

AudioManager::AudioManager() {
    //构造方法。
    /*
    负责人: 波波沙

    功能:
        读取所有的素材

    参数: void

    返回值: void
    */
    //----------------------实现------------------------//

    //默认音乐音效音量为1
    volumeMusic = 1;
    volumeSound = 1;

    //读入音乐
    //读入主菜单BGM
    loadMusic("MenuMusic1", "Asset/Music/MenuMusic1.mp3", 50);

    //读入音效
    //读入选择按钮音效
    loadSound("SelectButton", "Asset/Sound/Selectbutton.mp3", 100);
    //读入点击按钮时的音效
    loadSound("ClickButton", "Asset/Sound/Clickbutton.mp3", 100);
}

void AudioManager::loadSound(const std::string& name, const std::string& filename, float volume) {
    //读取音效,同时设置音效音量初始值
    /*
    负责人: 波波沙

    功能:
        将音效读入，设置音效的音量基值

    参数: 
        const std::string& name     //音效的名字，通过这个调用音效
        const std::string& filename //音效文件的路径
        float volume                //音效音量的基准值（0-100）

    返回值: void
    */
    //----------------------实现------------------------//

    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename)) {
        soundBuffers[name] = buffer;
        initialSoundVolumes[name] = volume;
    }
}

void AudioManager::playSound(const std::string& name) {
    //播放音效
    /*
    负责人: 波波沙

    功能:
        播放音效

    参数:
        const std::string& name     //音效的名字，通过这个调用音效

    返回值: void
    */
    //----------------------实现------------------------//

    auto bufferIt = soundBuffers.find(name);
    if (bufferIt != soundBuffers.end()) {
        auto sound = std::make_unique<sf::Sound>();
        sound->setBuffer(bufferIt->second);
        sound->setVolume(initialSoundVolumes[name] * volumeSound);
        sound->play();
        playingSounds.push_back(std::move(sound));
    }
}

void AudioManager::loadMusic(const std::string& name, const std::string& filename, float volume) {
    //读取音乐，同时设置音乐音量初始值
    /*
    负责人: 波波沙

    功能:
        读取音乐，同时设置音乐音量初始值

    参数:
        const std::string& name         //音乐的名字，通过这个名字调用音乐
        const std::string& filename     //音乐文件的路径
        float volume                    //音乐的音量基值

    返回值: void
    */
    //----------------------实现------------------------//

    auto musicFile = std::make_unique<sf::Music>();
    if (musicFile->openFromFile(filename)) {
        music[name] = std::move(musicFile);
        initialMusicVolumes[name] = volume;
        music[name]->setVolume(volume);
    }
}

void AudioManager::playMusic(const std::string& name, bool loop) {
    //播放音乐，可选择是否循环播放，播放时如果有正在播放的则进行切换
    /*
    负责人: 波波沙

    功能:
        播放音乐，可选择是否循环播放，播放时如果有正在播放的则进行切换

    参数:
        const std::string& name         //音乐的名字，通过这个选择要播放的音乐
        bool loop                       //是否要循环播放BGM

    返回值: void
    */
    //----------------------实现------------------------//

    auto found = music.find(name);
    if (found != music.end() && found->second) {
        if (currentBGM) {
            currentBGM->stop();
        }
        currentBGM = found->second.get();
        currentBGM->setLoop(loop);
        currentBGM->play();
    }
}

void AudioManager::stopMusic() {
    //停止播放音乐
    /*
    负责人: 波波沙

    功能:
        停止播放音乐

    参数:void

    返回值: void
    */
    //----------------------实现------------------------//

    if (currentBGM) {
        currentBGM->stop();
        currentBGM = nullptr;
    }
}

void AudioManager::setSoundVolume(float volume) {
    //设置音效的全局音量
    /*
    负责人: 波波沙

    功能:
        设置音效的全局音量

    参数:
        float volume    //一个介于0-1之间的数，用来设置音量大小

    返回值: void
    */
    //----------------------实现------------------------//

    volumeSound = volume;
}

void AudioManager::setMusicVolume(float volume) {
    //设置音乐的全局音量
    /*
    负责人: 波波沙

    功能:
        设置音乐的全局音量

    参数:
        float volume    //一个介于0-1之间的数，用来设置音量大小

    返回值: void
    */
    //----------------------实现------------------------//

    volumeMusic = volume;

    for (auto& musicItem : music) {
        float initialVolume = initialMusicVolumes[musicItem.first];
        if (musicItem.second) {
            musicItem.second->setVolume(initialVolume * volume);
        }
    }
}

void AudioManager::update() {
    //更新以销毁播放完毕的音效
    /*
    负责人: 波波沙

    功能:
        更新以销毁播放完毕的音效

    参数:void

    返回值: void
    */
    //----------------------实现------------------------//

    auto it = playingSounds.begin();
    while (it != playingSounds.end()) {
        if ((*it)->getStatus() == sf::Sound::Stopped) {
            it = playingSounds.erase(it);
        }
        else {
            ++it;
        }
    }
}

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
        sounds[name].setBuffer(soundBuffers[name]);
        initialSoundVolumes[name] = volume;
        sounds[name].setVolume(volume);
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

    auto found = sounds.find(name);
    if (found != sounds.end()) {
        found->second.play();
    }
}

void AudioManager::stopSound(const std::string& name) {
    auto found = sounds.find(name);
    if (found != sounds.end()) {
        found->second.stop();
    }
}

void AudioManager::loadMusic(const std::string& name, const std::string& filename, float volume) {
    auto musicFile = std::make_unique<sf::Music>();
    if (musicFile->openFromFile(filename)) {
        music[name] = std::move(musicFile);
        initialMusicVolumes[name] = volume;
        music[name]->setVolume(volume);
    }
}

void AudioManager::playMusic(const std::string& name, bool loop) {
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
    if (currentBGM) {
        currentBGM->stop();
        currentBGM = nullptr;
    }
}

void AudioManager::setSoundVolume(float volume) {
    for (auto& sound : sounds) {
        float initialVolume = initialSoundVolumes[sound.first];
        sound.second.setVolume(initialVolume * volume);
    }
}

void AudioManager::setMusicVolume(float volume) {
    for (auto& musicItem : music) {
        float initialVolume = initialMusicVolumes[musicItem.first];
        if (musicItem.second) {
            musicItem.second->setVolume(initialVolume * volume);
        }
    }
}

void AudioManager::update() {
    auto it = playingSounds.begin();
    while (it != playingSounds.end()) {
        if (it->getStatus() == sf::Sound::Stopped) {
            it = playingSounds.erase(it);
        }
        else {
            ++it;
        }
    }
}

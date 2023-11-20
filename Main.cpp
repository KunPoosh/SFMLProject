#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "StateManager.hpp"
#include "StateMenu.hpp"
#include "StateSetting.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "SettingsManager.hpp"

int main() {
	//程序入口
	/*
	负责人: 波波沙

	功能:
		运行程序基本逻辑

	参数: void

	返回值: int
	*/
	//----------------------实现------------------------//

	//创建窗口
	sf::RenderWindow window(sf::VideoMode(960, 960), "SFML window");
	//限制游戏帧率上限为60FPS
	window.setFramerateLimit(60);


	//创建场景管理器
	StateManager stateManager;

	//使用音频管理器
	AudioManager& audioManager = AudioManager::getInstance();

	//使用文件管理器
	SettingsManager& settingsManager = SettingsManager::getInstance();

	//将场景管理器初始化场景设置为主界面(使用智能指针)
	stateManager.changeState(std::make_unique<StateMenu>(stateManager));
	//默认初始播放BGM
	audioManager.playMusic("MenuMusic1", true);

	//读取一次存档
	settingsManager.loadSettings("Asset/save.txt");

	//----------------游戏主循环------------------//
	while (window.isOpen()) {

		//将窗口下传
		stateManager.handleInputCurrentState(window);

		//进行场景的普通的每帧更新
		stateManager.updateCurrentState();

		//清理播放的音效
		audioManager.update();

		//清空缓冲
		window.clear(sf::Color(250, 240, 200));

		//渲染当前场景的内容
		stateManager.drawCurrentState(window);

		//显示渲染完成的场景
		window.display();
	}

	return 0;
}






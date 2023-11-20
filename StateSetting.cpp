#include "StateSetting.hpp"
#include "StateMenu.hpp"

StateSetting::StateSetting(StateManager& manager) : stateManager(manager) {
	//构造方法

	//素材管理器单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置"设置"按钮的位置等信息。
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200,150), sf::Color(100, 100, 100,150), sf::Color(150, 150, 150,150));
	home.setPosition(50, 50, 200, 50);

	//设置背景图片
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// 使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//初始化标题
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString("Settings");
	title.setPosition(350, 50);
}

void StateSetting::handleInput(sf::RenderWindow& window) {

	sf::Event event;
	while (window.pollEvent(event))
	{
		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... 处理按钮点击事件，使用stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			if (this->home.isMouseOver(window)) {
				this->stateManager.changeState(std::make_unique<StateMenu>(stateManager));
			}
		}
		if (event.type == sf::Event::MouseMoved) {
			if (home.isMouseOver(window)) {
				home.onHover();
			}
			else {
				//当鼠标不再悬停在按钮上时恢复原始颜色
				home.resetColor();
			}
		}
	}

}

void StateSetting::update() {
	// ... 更新逻辑
}

void StateSetting::draw(sf::RenderWindow& window) {
	//最先渲染背景图片
	window.draw(BackgroundImage);

	// ... 绘制按钮
	this->home.draw(window);

	//绘制文字
	window.draw(this->title);
}
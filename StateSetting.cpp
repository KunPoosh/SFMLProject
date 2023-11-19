#include "StateSetting.hpp"
#include "StateMenu.hpp"

StateSetting::StateSetting(StateManager& manager) : stateManager(manager) {

	AssetManager& assetManager = AssetManager::getInstance();

	//设置"设置"按钮的位置等信息。
	home.setFont(assetManager.getFont("simhei"), sf::Color::Black, "返回", 24);
	home.setColor(sf::Color(200, 200, 200), sf::Color(100, 100, 100), sf::Color(150, 150, 150));
	home.setPosition(100, 600, 200, 40);

	//初始化标题
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::Black);
	title.setCharacterSize(50);
	title.setString("Settings");
	title.setPosition(250, 100);
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
	// ... 绘制按钮
	this->home.draw(window);

	//绘制文字
	window.draw(this->title);
}
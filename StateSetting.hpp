#ifndef WINDOW1STATE_HPP
#define WINDOW1STATE_HPP

#include "Button.hpp"
#include "StateManager.hpp"
#include "State.hpp"
#include "AssetManager.hpp"


// -------------------- 类设计 --------------------
/*
	【设置场景类】（未完成）
	负责人： 

	功能：实现设置界面的功能
*/

class StateSetting : public State {
public:
	//构造方法（未完成）
	StateSetting(StateManager& manager);

	//处理输入的事件（未完成）
	void handleInput(sf::RenderWindow& window) override;

	//更新（未完成）
	void update() override;

	//渲染（未完成）
	void draw(sf::RenderWindow& window) override;

private:
	//常见管理器的引用
	StateManager& stateManager;

	//返回按钮
	Button home;
	//标题字
	sf::Text title;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;
};

#endif // WINDOW1STATE

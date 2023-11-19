#include "StateMenu.hpp"
#include <iostream>

StateMenu::StateMenu(StateManager& manager)
    : stateManager(manager)
{
    //构造方法，传入一个场景管理器的引用，方便调用场景管理器的方法。(未完成)
    /*
    负责人: 波波沙

    功能:
        初始化主场景：
            1.创建按钮（新游戏，鉴赏模式，设置，游戏指南，退出游戏）
            2.创建背景图片
            3.创建游戏标题字
            4.使当前场景对象关联场景管理器对象

    参数:
        StateManager& manager   //场景管理器单例，关联到类中的场景管理器指针上。

    返回值: StateMenu
    */
    //----------------------实现------------------------//

    //使用素材管理器
    AssetManager& assetManager = AssetManager::getInstance();

    //设置背景图片
    BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
    BackgroundImage.setPosition(0, 0);

    //设置"开始游戏"按钮的位置等信息
    startButton.setFont(assetManager.getFont("simhei"), sf::Color::Black, "新游戏", 50);
    startButton.setColor(sf::Color(255, 0, 0, 0), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180,100));
    startButton.setPosition(0, 350, 450, 100);

    //设置"设置"按钮的位置等信息。
    /*settingsButton.setFont(assetManager.getFont("simhei"), sf::Color::Black, "设置", 24);
    settingsButton.setColor(sf::Color(200, 200, 200), sf::Color(100, 100, 100), sf::Color(150, 150, 150));
    settingsButton.setPosition(100, 100, 200, 40);*/

}

void StateMenu::handleInput(sf::RenderWindow& window){
    //将当前发生的事件（主要是点击按钮的事件）进行处理，并且反馈操作到当前窗口中。复写基类方法。(未完成)
    /*
    负责人: 波波沙

    功能: 处理各种事件。
            点击事件，点到各各按钮上时的不同对应措施。

    参数:
        sf::RenderWindow& window    //程序主窗口，主要用于进一步下传。
        sf::Event& event            //主窗口中发生的一个事件，用于处理。

    返回值: void
    */
    //----------------------实现------------------------//

    //创建一个事件类，用来接受和处理事件
    sf::Event event;

    while (window.pollEvent(event))
    {
        //当点击关闭时关闭窗口
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        //当鼠标点击时判断这个瞬间鼠标在那个按钮的上方
        if (event.type == sf::Event::MouseButtonPressed) {
            //在按钮"设置"的上方
            if (settingsButton.isMouseOver(window)) {
                //将场景切换到设置界面
                stateManager.changeState(stateManager.createState("StateSetting"));
            }
        }
        //当鼠标移动时获取鼠标位置，判断是否在某一个按钮上面，是的话讲按钮改变颜色
        if (event.type == sf::Event::MouseMoved) {
            //返回true代表当前鼠标在当前"设置按钮上"
            if (settingsButton.isMouseOver(window)) {
                //调用按钮的方法改变颜色
                settingsButton.onHover();
            }
            else {
                //当鼠标不再悬停在按钮上时恢复原始颜色
                settingsButton.resetColor();
            }

            if (startButton.isMouseOver(window)) {
                startButton.onHover();
            }
            else
            {
                startButton.resetColor();
            }
        }
    }

 
}

void StateMenu::update()  {
    //更新当前窗口，主窗口没有什么需要更新的。
    //将当前发生的事件（主要是点击按钮的事件）进行处理，并且反馈操作到当前窗口中。复写基类方法。(未完成)
    /*
    负责人: 波波沙

    功能: 无

    参数:void

    返回值: void
    */
    //----------------------不需要实现------------------------//
}

void StateMenu::draw(sf::RenderWindow& window) {
    //渲染，渲染所有的按钮和背景图片等等。(未完成)
    /*
    负责人: 波波沙

    功能: 无

    参数:
        sf::RenderWindow& window    //需要渲染到的位置

    返回值: void
    */
    //----------------------实现------------------------//

    //渲染背景图
    window.draw(BackgroundImage);

    //调用对应按钮的渲染方法，将窗口下传。
    this->startButton.draw(window);
    this->settingsButton.draw(window);
}

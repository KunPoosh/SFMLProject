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
    startButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"新游戏", 50);
    startButton.setColor(sf::Color(200, 200, 200, 80), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180,130));
    startButton.setPosition(50, 350, 400, 100);

    //设置"鉴赏模式"按钮的位置等信息
    galleryButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"鉴赏模式", 50);
    galleryButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 100));
    galleryButton.setPosition(50, 450, 400, 100);

    //设置"设置"按钮的位置等信息
    settingsButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"设置", 50);
    settingsButton.setColor(sf::Color(200, 200, 200, 80), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    settingsButton.setPosition(50, 550, 400, 100);

    //设置"关于"按钮的位置等信息
    aboutButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"关于", 50);
    aboutButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 100));
    aboutButton.setPosition(50, 650, 400, 100);

    //设置"退出"按钮的位置等信息
    exitButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"退出游戏", 50);
    exitButton.setColor(sf::Color(200, 200, 200, 80), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    exitButton.setPosition(50, 750, 400, 100);

    isSelectStare = false;
    isSelectGallery = false;
    isSelectSettings = false;
    isSelectAbout = false;
    isSelectExit = false;

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

    //引用音频播放单例
    AudioManager& audioManager = AudioManager::getInstance();

    while (window.pollEvent(event))
    {
        //当点击关闭时关闭窗口
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        //当鼠标点击时判断这个瞬间鼠标在那个按钮的上方
        if (event.type == sf::Event::MouseButtonPressed) {
            //在按钮开始游戏的上方
            if (startButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
            }

            //在按钮鉴赏模式的上方
            else if (galleryButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
            }

            //在按钮"设置"的上方
            else if (settingsButton.isMouseOver(window)) {
                //将场景切换到设置界面
                stateManager.changeState(stateManager.createState("StateSetting"));
                audioManager.playSound("ClickButton");
            }

            //在按钮关于的上方
            else if (aboutButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
            }

            //在按钮退出的上方
            else if (exitButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
                window.close();
                return;
            }

        }

        //当鼠标移动时获取鼠标位置，判断是否在某一个按钮上面，是的话讲按钮改变颜色
        if (event.type == sf::Event::MouseMoved) {
            //返回true代表当前鼠标在当前"设置按钮上"
           
            //在开始游戏按钮的上方
            if (startButton.isMouseOver(window)) {
                startButton.onHover();
                if (!isSelectStare) {
                    isSelectStare = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                startButton.resetColor();
                isSelectStare = false;
            }

            //在鉴赏模式按钮的上方
            if (galleryButton.isMouseOver(window)) {
                galleryButton.onHover();
                if (!isSelectGallery) {
                    isSelectGallery = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                galleryButton.resetColor();
                isSelectGallery = false;
            }

            //在设置按钮的上方
            if (settingsButton.isMouseOver(window)) {
                settingsButton.onHover();
                if (!isSelectSettings) {
                    isSelectSettings = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else {
                settingsButton.resetColor();
                isSelectSettings = false;
            }

            //在关于按钮的上方
            if (aboutButton.isMouseOver(window)) {
                aboutButton.onHover();
                if (!isSelectAbout) {
                    isSelectAbout = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                aboutButton.resetColor();
                isSelectAbout = false;
            }

            //在退出按钮的上方
            if (exitButton.isMouseOver(window)) {
                exitButton.onHover();
                if (!isSelectExit) {
                    isSelectExit = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                exitButton.resetColor();
                isSelectExit = false;
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
    startButton.draw(window);
    galleryButton.draw(window);
    settingsButton.draw(window);
    aboutButton.draw(window);
    exitButton.draw(window);
}

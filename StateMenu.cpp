#include "StateMenu.hpp"
#include <iostream>

StateMenu::StateMenu(StateManager& manager)
    : stateManager(manager)
{
    //���췽��������һ�����������������ã�������ó����������ķ�����(δ���)
    /*
    ������: ����ɳ

    ����:
        ��ʼ����������
            1.������ť������Ϸ������ģʽ�����ã���Ϸָ�ϣ��˳���Ϸ��
            2.��������ͼƬ
            3.������Ϸ������
            4.ʹ��ǰ�������������������������

    ����:
        StateManager& manager   //�������������������������еĳ���������ָ���ϡ�

    ����ֵ: StateMenu
    */
    //----------------------ʵ��------------------------//

    //ʹ���زĹ�����
    AssetManager& assetManager = AssetManager::getInstance();

    //���ñ���ͼƬ
    BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
    BackgroundImage.setPosition(0, 0);

    //����"��ʼ��Ϸ"��ť��λ�õ���Ϣ
    startButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����Ϸ", 50);
    startButton.setColor(sf::Color(200, 200, 200, 80), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180,130));
    startButton.setPosition(50, 350, 400, 100);

    //����"����ģʽ"��ť��λ�õ���Ϣ
    galleryButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����ģʽ", 50);
    galleryButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 100));
    galleryButton.setPosition(50, 450, 400, 100);

    //����"����"��ť��λ�õ���Ϣ
    settingsButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 50);
    settingsButton.setColor(sf::Color(200, 200, 200, 80), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    settingsButton.setPosition(50, 550, 400, 100);

    //����"����"��ť��λ�õ���Ϣ
    aboutButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 50);
    aboutButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 100));
    aboutButton.setPosition(50, 650, 400, 100);

    //����"�˳�"��ť��λ�õ���Ϣ
    exitButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"�˳���Ϸ", 50);
    exitButton.setColor(sf::Color(200, 200, 200, 80), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    exitButton.setPosition(50, 750, 400, 100);

    isSelectStare = false;
    isSelectGallery = false;
    isSelectSettings = false;
    isSelectAbout = false;
    isSelectExit = false;

}

void StateMenu::handleInput(sf::RenderWindow& window){
    //����ǰ�������¼�����Ҫ�ǵ����ť���¼������д������ҷ�����������ǰ�����С���д���෽����(δ���)
    /*
    ������: ����ɳ

    ����: ��������¼���
            ����¼����㵽������ť��ʱ�Ĳ�ͬ��Ӧ��ʩ��

    ����:
        sf::RenderWindow& window    //���������ڣ���Ҫ���ڽ�һ���´���
        sf::Event& event            //�������з�����һ���¼������ڴ���

    ����ֵ: void
    */
    //----------------------ʵ��------------------------//

    //����һ���¼��࣬�������ܺʹ����¼�
    sf::Event event;

    //������Ƶ���ŵ���
    AudioManager& audioManager = AudioManager::getInstance();

    while (window.pollEvent(event))
    {
        //������ر�ʱ�رմ���
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        //�������ʱ�ж����˲��������Ǹ���ť���Ϸ�
        if (event.type == sf::Event::MouseButtonPressed) {
            //�ڰ�ť��ʼ��Ϸ���Ϸ�
            if (startButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
            }

            //�ڰ�ť����ģʽ���Ϸ�
            else if (galleryButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
            }

            //�ڰ�ť"����"���Ϸ�
            else if (settingsButton.isMouseOver(window)) {
                //�������л������ý���
                stateManager.changeState(stateManager.createState("StateSetting"));
                audioManager.playSound("ClickButton");
            }

            //�ڰ�ť���ڵ��Ϸ�
            else if (aboutButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
            }

            //�ڰ�ť�˳����Ϸ�
            else if (exitButton.isMouseOver(window)) {
                audioManager.playSound("ClickButton");
                window.close();
                return;
            }

        }

        //������ƶ�ʱ��ȡ���λ�ã��ж��Ƿ���ĳһ����ť���棬�ǵĻ�����ť�ı���ɫ
        if (event.type == sf::Event::MouseMoved) {
            //����true����ǰ����ڵ�ǰ"���ð�ť��"
           
            //�ڿ�ʼ��Ϸ��ť���Ϸ�
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

            //�ڼ���ģʽ��ť���Ϸ�
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

            //�����ð�ť���Ϸ�
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

            //�ڹ��ڰ�ť���Ϸ�
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

            //���˳���ť���Ϸ�
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
    //���µ�ǰ���ڣ�������û��ʲô��Ҫ���µġ�
    //����ǰ�������¼�����Ҫ�ǵ����ť���¼������д������ҷ�����������ǰ�����С���д���෽����(δ���)
    /*
    ������: ����ɳ

    ����: ��

    ����:void

    ����ֵ: void
    */
    //----------------------����Ҫʵ��------------------------//
}

void StateMenu::draw(sf::RenderWindow& window) {
    //��Ⱦ����Ⱦ���еİ�ť�ͱ���ͼƬ�ȵȡ�(δ���)
    /*
    ������: ����ɳ

    ����: ��

    ����:
        sf::RenderWindow& window    //��Ҫ��Ⱦ����λ��

    ����ֵ: void
    */
    //----------------------ʵ��------------------------//

    //��Ⱦ����ͼ
    window.draw(BackgroundImage);

    //���ö�Ӧ��ť����Ⱦ�������������´���
    startButton.draw(window);
    galleryButton.draw(window);
    settingsButton.draw(window);
    aboutButton.draw(window);
    exitButton.draw(window);
}

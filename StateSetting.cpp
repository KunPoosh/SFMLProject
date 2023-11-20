#include "StateSetting.hpp"
#include "StateMenu.hpp"

StateSetting::StateSetting(StateManager& manager) : stateManager(manager) {
	//���췽��

	//�زĹ���������
	AssetManager& assetManager = AssetManager::getInstance();

	//����"����"��ť��λ�õ���Ϣ��
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 30);
	home.setColor(sf::Color(200, 200, 200,150), sf::Color(100, 100, 100,150), sf::Color(150, 150, 150,150));
	home.setPosition(50, 50, 200, 50);

	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//��ʼ������
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
		//������ر�ʱ�رմ���
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... ����ť����¼���ʹ��stateManager.changeState(...)
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
				//����겻����ͣ�ڰ�ť��ʱ�ָ�ԭʼ��ɫ
				home.resetColor();
			}
		}
	}

}

void StateSetting::update() {
	// ... �����߼�
}

void StateSetting::draw(sf::RenderWindow& window) {
	//������Ⱦ����ͼƬ
	window.draw(BackgroundImage);

	// ... ���ư�ť
	this->home.draw(window);

	//��������
	window.draw(this->title);
}
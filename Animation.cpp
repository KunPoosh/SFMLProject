#include "Animation.hpp"

sf::Vector2f Animation::lerp(const sf::Vector2f& start, const sf::Vector2f& end, float progress) {
    // 线性插值函数
    return start + (end - start) * progress;
}

TitleAnimation::TitleAnimation() {
    //召唤大哥
    AssetManager& assetManager = AssetManager::getInstance();

    Pic1.setTexture(assetManager.getTexture("Title1"));
    Pic2.setTexture(assetManager.getTexture("Title2"));
    Pic3.setTexture(assetManager.getTexture("Title3"));
    Pic1.setPosition(-10, -10);
    Pic2.setPosition(280,120);
    Pic3.setPosition(450, 60);
    Pic1.setColor(sf::Color(255, 255, 255, 255));
    Pic2.setColor(sf::Color(255, 255, 255, 255));
    Pic3.setColor(sf::Color(255, 255, 255, 255));
    endPic1 = sf::Vector2f(30, 30);
    endPic2 = sf::Vector2f(280, 120);
    endPic3 = sf::Vector2f(350, 60);

    //动画持续时间
    animationDuration = 3.0f;

    //清空开始时的计数器
    totalTime = 0.f;
}

void TitleAnimation::update(float deltaTime) {
    totalTime += deltaTime;

     //计算动画进度的比例
    float progress = std::min(totalTime / animationDuration, 1.0f);

     //计算每个图片的新位置和透明度
    Pic1.setPosition(lerp(Pic1.getPosition(), endPic1, progress));
    Pic2.setPosition(lerp(Pic2.getPosition(), endPic2, progress));
    Pic3.setPosition(lerp(Pic3.getPosition(), endPic3, progress));

    int alpha = static_cast<int>(255 * progress);
    sf::Color color(255, 255, 255, alpha);
    Pic1.setColor(color);
    Pic2.setColor(color);
    Pic3.setColor(color);
}

void TitleAnimation::draw(sf::RenderWindow& window) {
    // 绘制当前动画帧
    window.draw(Pic1);
    window.draw(Pic3);
    window.draw(Pic2);
}

#include "Bullet.hpp"

void Bullet::setPosition(const sf::Vector2f& position) {
    // 设置子弹的位置
    /*
    负责人: 波波沙

    功能:
        输入一个位置，将子弹移动过来

    参数:
        const sf::Vector2f& position    //一个位置坐标

    返回值: void
    */
    //----------------------实现------------------------//
    sprite.setPosition(position);
}

void EnemyBullet1::update(float deltaTime){
    // 更新子弹的位置（未完成）
    /*
    负责人: 波波沙

    功能:
        更新子弹的位置，并且实现碰撞判定

    参数: 
        float deltaTime //全局统一间隔时间

    返回值: void
    */
    //----------------------实现------------------------//

    //移动子弹
    sprite.move(direction * speed * deltaTime);

    //碰撞判定
    //....

    //子弹离开屏幕被销毁
    // 获取子弹位置...
    sf::Vector2f position = sprite.getPosition();
    // 设置额外的边界缓冲区
    float buffer = 30.0f; // 例如，50像素的缓冲区
    // 检查边界
    if (position.x < -buffer || position.x > 660 + buffer ||
        position.y < -buffer || position.y > 960 + buffer) {
        markForDestruction(); // 标记为待销毁
    }

    //命中过的子弹要被销毁
    if (health <= 0) {
        markForDestruction();
    }
}

void EnemyBullet1::draw(sf::RenderWindow& window){
    //渲染子弹
    /*
    负责人: 波波沙

    功能:
        显示子弹

    参数: 
        sf::RenderWindow& window    //要渲染的地方

    返回值: void
    */
    //----------------------实现------------------------//

    //渲染
    window.draw(sprite);
}

void PlayerBullet1::update(float deltaTime) {
    // 更新子弹的位置（未完成）
    /*
    负责人: 波波沙

    功能:
        更新子弹的位置，并且实现碰撞判定

    参数:
        float deltaTime //全局统一间隔时间

    返回值: void
    */
    //----------------------实现------------------------//

    //更新子弹位置
    sprite.move(direction * speed * deltaTime);

    //和所有敌人进行碰撞判定 O(mn)
    //...


    //子弹离开屏幕被销毁
    // 获取子弹位置...
    sf::Vector2f position = sprite.getPosition();
    // 设置额外的边界缓冲区
    float buffer = 30.0f; // 例如，50像素的缓冲区
    // 检查边界
    if (position.x < -buffer || position.x > 660 + buffer ||
        position.y < -buffer || position.y > 960 + buffer) {
        markForDestruction(); // 标记为待销毁
    }

    //命中过的子弹要被销毁
    if (health <= 0) {
        markForDestruction();
    }
}

void PlayerBullet1::draw(sf::RenderWindow& window){
    //渲染子弹
    /*
    负责人: 波波沙

    功能:
        显示子弹

    参数:
        sf::RenderWindow& window    //要渲染的地方

    返回值: void
    */
    //----------------------实现------------------------//

    //渲染
    window.draw(sprite);
}
#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

// -------------------- 类设计 --------------------
/*
    【子弹基类】
    负责人： 波波沙

    功能：
        所有子弹和拾取道具的基类，包括了必要的属性和方法

*/

class Bullet : public Entity {
protected:
    sf::Sprite sprite;         // 子弹的精灵
    sf::Vector2f direction;    // 子弹的方向
    float speed;               // 子弹的速度
    int health;                // 子弹的生命值
    int atk;                   // 子弹的伤害

public:

    //构造方法，直接输入纹理，方向，速度，血量，攻击力
    Bullet(const sf::Texture& texture, const sf::Vector2f& dir, float spd, int hp, int atk)
        : direction(dir), speed(spd), health(hp) ,atk(atk){
        sprite.setTexture(texture);
    }

    // 将 update 和 draw 方法声明为纯虚函数
    //更新
    virtual void update(float deltaTime) = 0;
    //渲染
    virtual void draw(sf::RenderWindow& window) = 0;

    // 单独设置子弹的位置
    void setPosition(const sf::Vector2f& position);

    // 可以添加设置和获取子弹属性的虚方法
    // ...
};


// -------------------- 类设计 --------------------
/*
    【敌人子弹类1】
    负责人： 波波沙

    功能：
        只由敌人使用的一种子弹

*/

class EnemyBullet1 : public Bullet {
public:
    // 使用基类的构造函数
    using Bullet::Bullet;

    //更新子弹位置，输入间隔时间（未完成）
    void update(float deltaTime) override;
    //渲染子弹
    void draw(sf::RenderWindow& window) override;

    // 可以添加特定于敌人子弹的方法
    //...
};


// -------------------- 类设计 --------------------
/*
    【玩家子弹类1】
    负责人： 波波沙

    功能：
        只由敌人使用的一种子弹

*/

class PlayerBullet1 : public Bullet {
public:
    // 使用基类的构造函数
    using Bullet::Bullet;

    //更新
    void update(float deltaTime) override;
    //渲染
    void draw(sf::RenderWindow& window) override;

    // 如有需要，可以添加特定于玩家子弹的其他方法
};

#endif

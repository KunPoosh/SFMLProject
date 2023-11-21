#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"
#include "Bullet.hpp"
#include "AssetManager.hpp"

// -------------------- 类设计 --------------------
/*
    【敌人基类】
    负责人： 波波沙

    功能：所有敌人的模板，精英怪也可以
        
*/

class Enemy : public Entity {
protected:
    sf::Sprite sprite;                  // 敌人的精灵
    int health;                         // 生命值
    sf::Vector2f direction;             // 移动方向
    float speed;                        // 移动速度

    float attackCooldown = 1.f;         // 攻击冷却时间
    float attackTimer = 0.f;            // 用于追踪攻击更新的计时器

public:
    // 构造函数，输入一个纹理，生命值，移动方向，速度
    Enemy(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
        : health(hp), direction(dir), speed(spd) {
        sprite.setTexture(texture);
    }

    // 纯虚函数，由子类实现
    //更新
    virtual void update(float deltaTime) = 0;
    //渲染
    virtual void draw(sf::RenderWindow& window) = 0;

    // 获取敌人的位置
    sf::Vector2f getPosition();

    // 计算指向玩家的单位向量
    sf::Vector2f getDirectionTowardsPlayer();

    // 其他可能的方法...
};


// -------------------- 类设计 --------------------
/*
    【敌人类1】（未完成）
    负责人： 波波沙

    功能：一个小怪，攻击方式是垂直向下发射一颗弹幕

*/

class Enemy1 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy1(const sf::Texture& texture,int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};



#endif

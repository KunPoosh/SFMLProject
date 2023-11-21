#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"


// -------------------- 类设计 --------------------
/*
    【玩家类】（未完成）
    负责人： 波波沙

    功能：玩家
        1.移动
        2.接受事件
            .处理移动
            .处理攻击
        3.更新
            .生命恢复
            .道具效果
        4.拥有道具

*/

class Player : public Entity {
private:
    sf::Sprite sprite;             // 玩家角色的精灵
    sf::Sprite hitboxSprite;       // 判定点的精灵

    int health;                    // 生命值
    int strength;                  // 力量值

    float accumulatedTime;         // 累计时间
    float attackInterval;          // 攻击间隔
    float healthRegenerationRate;  // 生命再生速度

    int atkBullet;                 // 子弹的伤害
    int helthBullet;               // 子弹的血量
    int speedBullet;               // 子弹的速度

public:

    //构造方法，手动创建
    Player();

    //更新
    void update(float deltaTime) override;

    //处理事件
    void handleInput(sf::Event event);

    //渲染
    void draw(sf::RenderWindow& window) override;

    //返回判定点中心的位置
    sf::Vector2f getHitboxPosition() const {
        return hitboxSprite.getPosition() + sf::Vector2f(5,5);
    }

    // 设置和获取属性的方法
    // ...
};

#endif

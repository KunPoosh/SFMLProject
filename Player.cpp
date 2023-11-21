#include "Player.hpp"

Player::Player() {

    //召唤素材！
    AssetManager& assetManager = AssetManager::getInstance();

    sprite.setTexture(assetManager.getTexture("Jumko"));
    hitboxSprite.setTexture(assetManager.getTexture("HitBox"));

    health = 1000;
    strength = 0;

    accumulatedTime = 0.f;
    attackInterval = 0.2f;
    healthRegenerationRate = 1.f;

    atkBullet = 10;
    helthBullet = 1;
    speedBullet = 1;
}

void Player::update(float deltaTime){
    // 更新玩家状态
    accumulatedTime += deltaTime;

    // 攻击逻辑
    if (accumulatedTime >= attackInterval) {
        // 执行攻击
        accumulatedTime = 0.f;  // 重置累计时间
    }

    // 生命恢复逻辑
    if (health < 100) {  // 假设最大生命值是100
        health += healthRegenerationRate * deltaTime;
        if (health > 100) health = 100;  // 限制生命值上限
    }
}

void Player::handleInput(sf::Event event) {
    //处理事件
}

void Player::draw(sf::RenderWindow& window){
    //渲染
    window.draw(sprite);
    window.draw(hitboxSprite);
}
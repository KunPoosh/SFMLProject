#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"

// 初始化静态成员
EntityManager* EntityManager::instance = nullptr;

// 私有构造函数定义
EntityManager::EntityManager() {
    // 初始化代码，如果有的话
}


EntityManager* EntityManager::getInstance() {
    // 获取实体管理器单例实例
    /*
    负责人: 波波沙

    功能:
        单例的唯一入口

    参数:void

    返回值: EntityManager*
    */
    //----------------------实现------------------------//
    if (!instance) {
        instance = new EntityManager();
    }
    return instance;
}

void EntityManager::setPlayer(std::shared_ptr<Player> player) {
    // 设置玩家对象
    /*
    负责人: 波波沙

    功能:
        让管理器单独关联一个玩家对象，因为玩家对象是唯一的

    参数:
        std::shared_ptr<Player> player  //玩家对象用智能指针存储

    返回值: void
    */
    //----------------------实现------------------------//
    this->player = player;
}

std::shared_ptr<Player> EntityManager::getPlayer() {
    // 获取玩家对象
    /*
    负责人: 波波沙

    功能:
        在其他地方需要玩家对象的时候，可以返回玩家对象

    参数:
        void

    返回值: std::shared_ptr<Player>
    */
    //----------------------实现------------------------//
    return player;
}

void EntityManager::addEntity(std::shared_ptr<Entity> entity) {
    // 添加一个新实体
    /*
    负责人: 波波沙

    功能:
        添加一个敌人，子弹，道具，只要是实体就可以

    参数:
        std::shared_ptr<Entity> entity      //输入对应的类名和对象

    返回值: void
    */
    //----------------------实现------------------------//
    entities.push_back(entity);
}

void EntityManager::updateEntities(float deltaTime) {
    // 更新所有实体
    /*
    负责人: 波波沙

    功能:
        通过下传deltaTime来更新所有的实体, 并且清除需要被销毁的对象

    参数:
        float deltaTime //全局间隔时间

    返回值: void
    */
    //----------------------实现------------------------//

    if (player) {
        player->update(deltaTime); // 更新玩家
    }
    for (auto& entity : entities) {
        entity->update(deltaTime); // 更新其他实体
    }

    // 移除标记为销毁的实体
    entities.erase(std::remove_if(entities.begin(), entities.end(),
        [](const std::shared_ptr<Entity>& entity) {
            return entity->isToBeDestroyed();
        }), entities.end());
}

void EntityManager::drawEntities(sf::RenderWindow& window) {
    // 渲染所有实体
    /*
    负责人: 波波沙

    功能:
        下传window，渲染所有的实体

    参数:
        sf::RenderWindow& window    //需要渲染到的地方

    返回值: void
    */
    //----------------------实现------------------------//

    if (player) {
        player->draw(window); // 渲染玩家
    }
    for (auto& entity : entities) {
        entity->draw(window); // 渲染其他实体
    }
}

void EntityManager::handleInput(sf::Event event) {
    // 处理玩家的事件输入
    /*
    负责人: 波波沙

    功能:
        将事件传给玩家，让玩家来决定如何操作

    参数:
        sf::Event event //从场景取得的事件

    返回值: void
    */
    //----------------------实现------------------------//
    player->handleInput(event);
}

void EntityManager::clearAllEntities() {
    // 清空所有实体，包括玩家
    /*
    负责人: 波波沙

    功能:
        清空所有的实体，在需要时使用！

    参数:
        void

    返回值: void
    */
    //----------------------实现------------------------//
    entities.clear();       // 清空所有普通实体
    player.reset();         // 重置玩家对象
}
#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

// -------------------- 类设计 --------------------
/*
    【实体管理器】
    负责人： 波波沙

    功能：单例模式，管理所有的实体
        1.统一更新所有实体
        2.统一渲染所有的实体
        3.处理玩家的操作
*/

// 向前声明
class Entity;
class Player;

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> entities; // 存储所有实体的容器
    std::shared_ptr<Player> player;                // 指向玩家对象的智能指针
    static EntityManager* instance;                // 指向实体管理器实例的指针

    // 私有构造函数，防止外部创建实例
    EntityManager();

public:
    // 获取实体管理器的单例实例
    static EntityManager* getInstance();

    // 设置玩家对象
    void setPlayer(std::shared_ptr<Player> player);

    // 获取玩家对象
    std::shared_ptr<Player> getPlayer();

    // 添加一个新实体
    void addEntity(std::shared_ptr<Entity> entity);

    // 更新所有实体
    void updateEntities(float deltaTime);

    // 渲染所有实体
    void drawEntities(sf::RenderWindow& window);

    // 处理玩家的事件输入
    void handleInput(sf::Event event);

    // 清空所有实体，包括玩家
    void clearAllEntities();

    // 其他管理实体的方法...
};

#endif

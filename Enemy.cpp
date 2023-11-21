#include "Enemy.hpp"
#include "Player.hpp"

sf::Vector2f Enemy::getPosition(){
	// 获取敌人的位置
	/*
	负责人: 波波沙

	功能:
		将当前敌人对象的位置返回

	参数:
		void

	返回值: sf::Vector2f
	*/
	//----------------------实现------------------------//
	return sprite.getPosition();
}

sf::Vector2f Enemy::getDirectionTowardsPlayer(){
	// 计算指向玩家的单位向量
	/*
	负责人: 波波沙

	功能:
		返回一个从敌人指向玩家的单位向量

	参数:
		

	返回值: sf::Vector2f
	*/
	//----------------------实现------------------------//
	auto entityManager = EntityManager::getInstance();
	auto player = entityManager->getPlayer(); // 假设这会返回玩家的shared_ptr

	if (player) {
		sf::Vector2f playerPosition = player->getHitboxPosition(); // 或 getPosition，取决于你的需求
		sf::Vector2f direction = playerPosition - sprite.getPosition();
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

		if (length != 0) {
			direction /= length;
		}

		return direction;
	}
	else {
		// 如果没有找到玩家，返回零向量或者合适的默认值
		return sf::Vector2f(0, 0);
	}
}


Enemy1::Enemy1(const sf::Texture& texture,int hp, const sf::Vector2f& dir, float spd)
    : Enemy(texture, hp, dir, spd) {
	//构造方法
	/*
	负责人: 波波沙

	功能:
		构造敌人，这种类型的攻击模式的敌人的射速可以在这里调

	参数:
		const sf::Texture& texture    //敌人的贴图。

	返回值: void
	*/
	//----------------------实现------------------------//

	//射速
	attackCooldown = 1.f;

	//初始化计时器
	attackTimer = 0.f;
}

void Enemy1::update(float deltaTime){
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 波波沙

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);

	//发射子弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//召唤大哥
		AssetManager& assetManager = AssetManager::getInstance();

		// 创建一个新的子弹实例，
		std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Button1"),
			sf::Vector2f(0,1),
			1000,
			1,
			10
		);
		//设置子弹的位置
		newBullet->setPosition(this->getPosition());


		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addEntity(newBullet);
	}

}

void Enemy1::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 波波沙

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}
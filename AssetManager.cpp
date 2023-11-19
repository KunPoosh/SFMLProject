#include "AssetManager.hpp"

AssetManager::AssetManager() {
	//构造方法。
	/*
	负责人: 波波沙

	功能:
		读取所有的素材

	参数: void

	返回值: void
	*/
	//----------------------实现------------------------//

	//读取字体"黑体"
	loadFont("simhei", "Asset/Font/simhei.ttf");
	//读取字体"幼圆"
	loadFont("SIMYOU", "Asset/Font/SIMYOU.TTF");

	//读取图片"酱可-主菜单"
	loadTexture("JumkoMenu", "Asset/Picture/JumkoMenu.png");
}

void AssetManager::loadTexture(const std::string& name, const std::string& filename) {
	// 创建并加载纹理
	/*
	负责人: 波波沙

	功能:
		创建并且加载纹理

	参数:
		const std::string& name     //哈希表的键，用这个名称去搜索对应的纹理
		const std::string& filename //纹理的路径

	返回值: void
	*/
	//----------------------实现------------------------//

	sf::Texture texture;
	if (texture.loadFromFile(filename)) {
		textures[name] = texture;
	}
}

void AssetManager::loadFont(const std::string& name, const std::string& filename) {
	// 创建并加载字体
	/*
	负责人: 波波沙

	功能:
		创建并且加载字体

	参数:
		const std::string& name     //哈希表的键，用这个名称去搜索对应的字体
		const std::string& filename //字体的路径

	返回值: void
	*/
	//----------------------实现------------------------//

	sf::Font font;
	if (font.loadFromFile(filename)) {
		fonts[name] = font;
	}
}

sf::Texture& AssetManager::getTexture(const std::string& name) {
	// 读取纹理
	/*
	负责人: 波波沙

	功能:
		读取纹理

	参数:
		const std::string& name     //输入键也就是名字来返回对应的纹理

	返回值: sf::Texture&
	*/
	//----------------------实现------------------------//

	return textures[name];
}


sf::Font& AssetManager::getFont(const std::string& name) {
	// 读取字体
	/*
	负责人: 波波沙

	功能:
		读取字体

	参数:
		const std::string& name     //输入键也就是名字来返回对应的字体

	返回值: sf::Font&
	*/
	//----------------------实现------------------------//

	return fonts[name];
}

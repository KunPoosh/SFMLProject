#include "State.hpp"

std::wstring State::convertToWideString(const std::string& str) {
	//将String转化成能显示的文字
	/*
	负责人: 波波沙

	功能:
		解决场景中的中文乱码的问题

	参数:
		const std::string& str  //输入的正常String

	返回值: std::wstring
	*/
	//----------------------实现------------------------//

	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(str);
}
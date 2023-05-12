#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <iomanip>

class Item
{
public:
	Item();
	~Item();
	inline std::string debugPrint() const { return name; }

private:
	std::string name;
	int buyValue;
	int sellValue;
};
#endif

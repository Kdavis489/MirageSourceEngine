#ifndef SPELL_H
#define SPELL_H
#include <iostream>
#include <string>
#include <iomanip>

class Spell
{
public:
	Spell();
	~Spell();
	inline std::string debugPrint() const { return name; }
	const std::string& getName() const;
	const std::string getDesc() const;
private:
	std::string name;
	std::string desc;
};
#endif
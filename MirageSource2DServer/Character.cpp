#include "Character.h"

Character::Character()
{
	posx = 0.0;
	posy = 0.0;
	name = "";
	level = 1;
	exp = 0;
	expNext = 0;
	str = 0;
	def = 0;
	magi = 0;
	speed = 0;
	//vitals
	hp = 0;
	hpMax = 0;
	mp = 0;
	mpMax = 0;
	sp = 0;
	spMax = 0;
	stamina = 0;
	//stats
	damageMin = 0;
	damageMax = 0;
	statPnt = 0;
	skillpnt = 0;
}

Character::Character(std::string name, int level, int exp, int str, int def, int magi, int speed, int hp, int mp, int sp, int stamina, int statPnt, int skillpnt)
{
	this->name = name;
	this->level = level;
	this->exp = 0;
	this->expNext = 0;
	this->str = 0;
	this->def = 0;
	this->magi = 0;
	this->speed = 0;
	//vitals
	this->hp = 0;
	this->hpMax = 0;
	this->mp = 0;
	this->mpMax = 0;
	this->sp = 0;
	this->spMax = 0;
	this->stamina = 0;
	//stats
	this->damageMin = 0;
	this->damageMax = 0;
	this->statPnt = 0;
	this->skillpnt = 0;
}

Character::~Character()
{
}

void Character::Initialize(std::string name)
{
	this->posx = 0.0;
	this->posy = 0.0;
	this-> name = name;
	this-> level = 1;
	this->exp = 0;
	expNext = static_cast<int>((50 / 3) * (pow(level, 3) - 6 * pow(level, 3) + (17 * level) - 11));
	this->str = 4;
	this->def = 3;
	this->magi = 2;
	this->speed = 5;
	//vitals
	this->hp = 10;
	this->hpMax = 10;
	this->mp = 5;
	this->mpMax = 5;
	this->sp = 10;
	this->spMax = 10;
	this->stamina = 20;
	//stats
	this->damageMin = 3;
	this->damageMax = 5;

	this->statPnt = 0;
	this->skillpnt = 0;
}

std::string Character::getAsString() const
{
	return name + " "
		+ std::to_string(posx) + " "
		+ std::to_string(posy) + " "
		+ std::to_string(level) + " "
		+ std::to_string(exp) + " "
		+ std::to_string(hp) + " "
		+ std::to_string(mp) + " "
		+ std::to_string(stamina) + " "
		+ std::to_string(str) + " "
		+ std::to_string(def) + " "
		+ std::to_string(magi) + " "
		+ std::to_string(speed) + " "
		+ std::to_string(statPnt) + " "
		+ std::to_string(skillpnt) + " ";
}

void Character::levelUp()
{
	while (exp >= expNext)
	{
		level++;
		expNext = static_cast<int>((50 / 3) * ((pow(level, 3) - 6 * pow(level, 2)) + 17 * level - 12)) + 100;

		statPnt++;
		skillpnt++;
	}
}

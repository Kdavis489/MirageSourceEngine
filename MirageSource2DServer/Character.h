#ifndef CHARACTER_H
#define CHARACTER_H
#include "Includes.h"
#include "Inventory.h"
#include "Spellbook.h"

class Character
{
public:
	Character();
	Character(std::string name, int level, int exp, int str, int def, int magi, int speed, int hp, int mp, int sp, int stamina, int statPnt, int skillpnt);
	virtual ~Character();

	//functions
	void Initialize(std::string name);
	std::string getAsString() const;
	void levelUp();

	//accessor
	inline const std::string& getName() const { return this->name; }
	inline const double& getX() const{ return this->posx; }
	inline const double& getY() const{ return this->posy; }
	inline const int& getLevel() const { return this->level; }

	inline const int& getExp() const { return this->exp; }
	inline const int& getexpNext() const { return this->expNext; }
	//vitals
	inline const int& getHp() const { return this->hp; }
	inline const int& gethpMax() const { return this->hpMax; }
	inline const int& getMp() const { return this->mp; }
	inline const int& getmpMax() const { return this->mpMax; }
	inline const int& getSp() const { return this->mp; }
	inline const int& getspMax() const { return this->mpMax; }
	inline const int& getStamina() const { return this->stamina; }
	//stats
	inline const int& getdamagemin() const { return this->damageMin; }
	inline const int& getStr() const { return this->str; }
	inline const int& getDef() const { return this->def; }
	inline const int& getMagi() const { return this->magi; }
	inline const int& getSpeed() const { return this-> speed; }
	//modifier


private:
	std::string name;
	double posx;
	double posy;

	int level;
	int exp;
	int expNext;
	int str;
	int def;
	int magi;
	int speed;
	//vitals
	int hp;
	int hpMax;
	int mp;
	int mpMax;
	int sp;
	int spMax;
	int stamina;
	//stats
	int damageMin;
	int damageMax;

	int statPnt;
	int skillpnt;
};
#endif
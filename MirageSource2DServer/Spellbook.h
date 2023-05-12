#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include "Spell.h"

class spellBook
{
public:
	spellBook();
	~spellBook();

	void addSpell(const Spell& spell);
private:
	int maxSpells;
	int nrOfSpells;
	Spell** spellArr;
	void expandSB();
	void initialize(const int from);
};

#endif
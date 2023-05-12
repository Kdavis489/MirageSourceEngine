#include "Spellbook.h"

spellBook::spellBook()
{
	maxSpells = 50;
	nrOfSpells = 0;
	spellArr = new Spell * [maxSpells];
}

spellBook::~spellBook()
{
	for (size_t i = 0; i < this->nrOfSpells; i++)
	{
		delete spellArr[i];
	}
	delete[] spellArr;
}

void spellBook::addSpell(const Spell& spell)
{
	if (nrOfSpells >= maxSpells)
	{
		expandSB();
	}
	spellArr[nrOfSpells++] = new Spell(spell);
}

void spellBook::expandSB()
{
	maxSpells *= 2;
	Spell** tempArr = new Spell * [maxSpells];
	for (size_t i = 0; i < nrOfSpells; i++)
	{
		tempArr[i] = new Spell(*spellArr[i]);
	}
	for (size_t i = 0; i < nrOfSpells; i++)
	{
		delete[] spellArr[i];
	}
	delete[] spellArr;
	spellArr = tempArr;
	initialize(nrOfSpells);
}

void spellBook::initialize(const int from)
{
	for (size_t i = from; i < maxSpells; i++)
	{
		spellArr[i] = nullptr;
	}
}

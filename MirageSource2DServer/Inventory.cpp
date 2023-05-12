#include "Inventory.h"

Inventory::Inventory()
{
	maxInv = 50;
	nrOfItems = 0;
	itemArr = new Item* [maxInv];
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete itemArr[i];
	}
	delete[] itemArr;
}

void Inventory::initialize(const int from)
{
	for (size_t i = from; i < maxInv; i++)
	{
		itemArr[i] = nullptr;
	}
}

void Inventory::expandInv()
{
	maxInv *= 2;
	Item** tempArr = new Item* [maxInv];

	for (size_t i = 0; i < nrOfItems; i++)
	{
		tempArr[i] = new Item(*itemArr[i]);
	}
	for (size_t i = 0; i < nrOfItems; i++)
	{
		delete itemArr[i];
	}
	delete[] itemArr;

	itemArr = tempArr;

	initialize(nrOfItems);
}

void Inventory::addItem(const Item& item)
{
	if (nrOfItems >= maxInv)
	{
		expandInv();
	}
	itemArr[nrOfItems++] = new Item(item);
}

void Inventory::removeItem(int index)
{
	if (index < 0 || index <= this->nrOfItems)
		throw("OUT OF BOUNDS REMOVE ITEM INVENTORY");
	delete this->itemArr[index];
	this->itemArr[index] = this->itemArr[this->nrOfItems - 1];
	this->itemArr[--this->nrOfItems] = nullptr;
}
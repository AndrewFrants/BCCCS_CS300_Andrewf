/////////////////////////////////////////////////
// Andrew Frantsuzov CS 300
//    Homework 4 : Array implementation of search
/////////////////////////////////////////////////

#include "ScannedItem.h"

// c'tor
ScannedItem::ScannedItem()
{
}

// copy c'tor
ScannedItem::ScannedItem(const ScannedItem& o)
{
	this->barcode = o.barcode;
	this->description = o.description;
}

// c'tor
ScannedItem::ScannedItem(double& barcode, string desc)
{
	this->barcode = barcode;
	this->description = desc;
}

// d'tor
ScannedItem::~ScannedItem()
{
}

// assignment op
const ScannedItem& ScannedItem::operator=(ScannedItem& o) {
	if (!(*this == o)) {
		this->barcode = o.barcode;
		this->description = o.description;
	}
	return *this;
}

// comparison op
bool operator<(ScannedItem& left, ScannedItem& right) {
	return (left.barcode < right.barcode);
}

// comparison op
bool operator>(ScannedItem& left, ScannedItem& right) {
	return (left.barcode > right.barcode);
}

// equality op
bool operator==(ScannedItem& left, ScannedItem& right)
{
	return (left.barcode == right.barcode);
}

// get barcode
double ScannedItem::getBarcode() const
{
	return barcode;
}

// get desc
string ScannedItem::getDescription() const
{
	return description;
}
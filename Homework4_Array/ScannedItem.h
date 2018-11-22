/////////////////////////////////////////////////
// Andrew Frantsuzov CS 300
//    Homework 4 : BST implementation of search
/////////////////////////////////////////////////

#include <iostream>
#pragma once

using namespace std;

// Scanned item
class ScannedItem
{
	double barcode;
	string description;

public:
	// c'tor
	ScannedItem();

	// copy c'tor
	ScannedItem(const ScannedItem& item);

	// c'tor
	ScannedItem(double& barcode, string desc);

	// getters 
	double getBarcode() const;
	string getDescription() const;

	// dtor (empty)
	~ScannedItem();

	// assignment
	const ScannedItem& operator=(ScannedItem& o);

	// used for comparisons
	friend bool operator==(ScannedItem& left, ScannedItem& right);
	friend bool operator>(ScannedItem& left, ScannedItem& right);
	friend bool operator<(ScannedItem& left, ScannedItem& right);
};
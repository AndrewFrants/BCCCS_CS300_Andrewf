#include <iostream>
#pragma once

using namespace std;

class ScannedItem
{
	double barcode;
	string description;

public:
	ScannedItem();
	ScannedItem(const ScannedItem& item);
	ScannedItem(double& barcode, string desc);
	double getBarcode() const;
	string getDescription() const;
	~ScannedItem();
	const ScannedItem& operator=(ScannedItem& o);

	// used for comparisons
	friend bool operator==(ScannedItem& left, ScannedItem& right);
	friend bool operator>(ScannedItem& left, ScannedItem& right);
	friend bool operator<(ScannedItem& left, ScannedItem& right);
};
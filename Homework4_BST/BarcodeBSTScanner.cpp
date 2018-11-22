/////////////////////////////////////////////////
// Andrew Frantsuzov CS 300
//    Homework 4: BST implementation of search
/////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "BinarySearchTree.h"
#include "ScannedItem.h"

using namespace std;

// start clock
clock_t startClock()
{
	clock_t t = clock();
	return t;
}

// measure clock
void measureClock(clock_t t)
{
	t = clock() - t;  
	cout << "time (ms): " << t << " miliseconds" << endl;
	cout << "time (s): " << t * 1.0 / CLOCKS_PER_SEC << " seconds (" << CLOCKS_PER_SEC << " clocks per second)" << endl;
}

// loadData loadCount to be at least 100
bool loadData(BinarySearchTree<ScannedItem>* barcodeBst, long loadCount, double& searchForBarcode)
{
	string token;
	int count = 0;

	ifstream file;
	file.open("upc_corpus.txt");
	if (!file.is_open()) {
		cout << "Barcodes file upc_corpus.txt was not opened. Expected to be in same folder as app.";
		return false;
	}

	while (!file.eof() && count < loadCount)
	{
		std::string line;
		getline(file, line);
		istringstream ss(line);

		int tokenIndex = 0;
		while (getline(ss, token, ','))
		{
			if (tokenIndex == 0)
			{
				double barcode = atof(token.c_str());
				if ((loadCount - 100) == count)
				{
					searchForBarcode = barcode;
				}

				ScannedItem item(barcode, "");
				barcodeBst->insert(item);
			}

			tokenIndex++;
		}

		count++;
	}
}
// entry point
int main()
{
	double searchForBarcode = 0.0;

	for (int i = 10000; i <= 10000000; i *= 10)
	{
		cout << "Count of items (n): " << i << endl;
		BinarySearchTree<ScannedItem>* barcodeBst = new BinarySearchTree<ScannedItem>();

		if (!loadData(barcodeBst, i, searchForBarcode))
		{
			cout << "failed loading barcodes";
			return 1;
		}

		cout << "Performing search 100 times ..." << endl;
		clock_t clock = startClock();

		ScannedItem searchItem(searchForBarcode, "");
		for (int i = 0; i < 100; i++)
		{
			barcodeBst->search(searchItem);
		}

		measureClock(clock);
	}

	return 0;

} //prints a b c
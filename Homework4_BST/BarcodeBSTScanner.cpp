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

// entry point
int main()
{
	string token; 
	int count = 0;
	
	double searchForBarcode = 0.0;

	for (int i = 10000; i <= 10000000; i *= 10)
	{
		cout << "Count of items (n): " << i << endl;

		ifstream file;
		file.open("C:\\Users\\Andrew\\Documents\\Visual Studio 2017\\Projects\\CS300_Hw3\\Debug\\upc_corpus.txt");
		if (!file.is_open()) {
			cout << "Barcodes file was not opened.";
			return 0;
		}

		BinarySearchTree<ScannedItem>* barcodeBst = new BinarySearchTree<ScannedItem>();
		bool firstLine = 0;
		while (!file.eof() && count < i)
		{
			std::string line;
			getline(file, line);
			istringstream ss(line);

			if (firstLine)
			{
				firstLine = false;
				continue;
			}

			int tokenIndex = 0;
			while (getline(ss, token, ','))
			{
				if (tokenIndex == 0)
				{
					double barcode = atof(token.c_str());
					if ((i - 100) == count)
					{
						searchForBarcode = barcode;
					}
					barcodeBst->insert(ScannedItem(barcode, ""));
				}

				tokenIndex++;
			}

			count++;
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
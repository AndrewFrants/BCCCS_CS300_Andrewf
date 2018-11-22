/////////////////////////////////////////////////
// Andrew Frantsuzov CS 300
//    Homework 4 : Array implementation of search
/////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "ScannedItem.h"
#include "ArrayBarcodes.h"

using namespace std;

// start clock
clock_t startClock()
{
	clock_t t = clock();
	return t;
}

// measure time
void measureClock(clock_t t)
{
	t = clock() - t;
	cout << "time (ms): " << t << " miliseconds" << endl;
	cout << "time (s): " << t * 1.0 / CLOCKS_PER_SEC << " seconds (" << CLOCKS_PER_SEC << " clocks per second)" << endl;
}

// loadData loadCount to be at least 100
bool loadTestData(ArrayBarcodes<ScannedItem>* barcodeArray, long loadCount, double& searchForBarcode)
{
	string token;
	ifstream file;
	file.open("upc_corpus.txt");
	if (!file.is_open()) {
		cout << "Barcodes file upc_corpus.txt was not opened. Expected to be in same folder as app.";
		return false;
	}

	bool firstLine = 0;
	int count = 0;
	while (!file.eof() && count < loadCount)
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
				if ((loadCount - 100) == count)
				{
					searchForBarcode = barcode;
				}

				ScannedItem si(barcode, "");
				barcodeArray->insert(si);
			}
			tokenIndex++;
		}

		count++;
	}

	return true;
}

// entry point
int main()
{
	double searchForBarcode = 0.0;

	for (int i = 10000; i <= 10000000; i *= 10) // every order of magnitude
	{
		cout << "Count of items (n): " << i << endl;

		ArrayBarcodes<ScannedItem>* barcodeArray = new ArrayBarcodes<ScannedItem>(i + 1);
		if (!loadTestData(barcodeArray, i, searchForBarcode))
		{
			cout << "failed loading barcodes";
			return 1;
		}
		
		cout << "Performing search 100 times ..." << endl;
		clock_t clock = startClock();

		ScannedItem searchItem(searchForBarcode, "");
		for (int i = 0; i < 100; i++)
		{
			barcodeArray->search(searchItem);
		}
		measureClock(clock);
	}

	return 0;
}
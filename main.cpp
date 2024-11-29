/*
 * main.cpp
 * 
 * 29-11-2024 by madpl
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>

const int numEntries = 20;

// ranges for latitude, longitude
const double latMin = 51.2000000, latMax = 51.3000000;
const double lonMin = 20.0000000, lonMax = 20.1000000;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> latDist(latMin, latMax);
std::uniform_real_distribution<> lonDist(lonMin, lonMax);


int main(void)
{
	std::ofstream gpsFile("gps_data.txt");
	if(!gpsFile)
	{
		std::cerr << "open to write failed!\n";
				
		return -1;
	}

	for(int i = 0; i < numEntries; ++i)
	{
		double lat = latDist(gen);
		double lng = lonDist(gen);
				
		gpsFile << std::fixed << std::setprecision(7) << lat << " " << lng << std::endl;
	}

	gpsFile.close();
	
	std::cout << "done.\n";
		
	return 0;
}

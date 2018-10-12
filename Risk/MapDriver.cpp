// Assignment 1, Part 1: Map [Driver]
// Written by Michael Luger, 40055539

#include "Map.h"
#include <iostream>

int main()
{
	// Territory Declarations
	Territory* usa = new Territory("USA");
	Territory* canada = new Territory("Canada");
	Territory* mexico = new Territory("Mexico");

	Territory* france = new Territory("France");
	Territory* spain = new Territory("Spain");
	Territory* germany = new Territory("Germany");
	Territory* italy = new Territory("Italy");
	Territory* switzerland = new Territory("Switzerland");

	Territory* australia = new Territory("Autralia");
	Territory* nz = new Territory("New Zealand");

	// Neighbor relations
	usa->addNeighbor(*canada);
	usa->addNeighbor(*mexico);
	mexico->addNeighbor(*usa);
	canada->addNeighbor(*usa);

	france->addNeighbor(*spain);
	france->addNeighbor(*germany);
	france->addNeighbor(*italy);
	france->addNeighbor(*switzerland);
	spain->addNeighbor(*france);
	germany->addNeighbor(*france);
	germany->addNeighbor(*switzerland);
	italy->addNeighbor(*france);
	italy->addNeighbor(*switzerland);
	switzerland->addNeighbor(*france);
	switzerland->addNeighbor(*germany);
	switzerland->addNeighbor(*italy);

	// Will make the world (but not Oceania) connected
	//usa->addNeighbor(*australia);
	//spain->addNeighbor(*nz);
	//australia->addNeighbor(*usa);
	//nz->addNeighbor(*spain);

	// Adding territories to continents
	std::vector<Territory> naTerritories;
	naTerritories.push_back(*canada);
	naTerritories.push_back(*usa);
	naTerritories.push_back(*mexico);
	Continent* northAmerica = new Continent("North America", 5, naTerritories);

	std::vector<Territory> europeTerritories;
	europeTerritories.push_back(*france);
	europeTerritories.push_back(*germany);
	europeTerritories.push_back(*italy);
	europeTerritories.push_back(*spain);
	europeTerritories.push_back(*switzerland);
	Continent* europe = new Continent("Europe", 8, europeTerritories);

	std::vector<Territory> oceaniaTerritories;
	oceaniaTerritories.push_back(*australia);
	oceaniaTerritories.push_back(*nz);
	Continent* oceania = new Continent("Oceania", 3, oceaniaTerritories);

	// Adding continents to map
	std::vector<Continent> continents;
	continents.push_back(*northAmerica);
	continents.push_back(*europe);
	continents.push_back(*oceania);

	std::vector<Territory> territories;
	territories.reserve(naTerritories.size() + europeTerritories.size() + oceaniaTerritories.size());
	territories.insert(territories.end(), naTerritories.begin(), naTerritories.end());
	territories.insert(territories.end(), europeTerritories.begin(), europeTerritories.end());
	territories.insert(territories.end(), oceaniaTerritories.begin(), oceaniaTerritories.end());
	Map* world = new Map(continents, territories);

	// Output to user
	std::cout << northAmerica->getName() << std::endl;
	std::cout << "Connected: " << northAmerica->isConnected() << std::endl << std::endl;

	std::cout << europe->getName() << std::endl;
	std::cout << "Connected: " << europe->isConnected() << std::endl << std::endl;

	std::cout << oceania->getName() << std::endl;
	std::cout << "Connected: " << oceania->isConnected() << std::endl << std::endl;

	std::cout << "World" << std::endl;
	std::cout << "Connected: " << world->isConnected() << std::endl;
}


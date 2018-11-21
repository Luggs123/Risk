// Assignment 1, Part 1: Map [Driver]
// Written by Michael Luger, 40055539

#include "../Map/Map.h"
#include "Driver.h"

int driver::map_driver()
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
    usa->add_neighbor(canada);
    usa->add_neighbor(mexico);
    mexico->add_neighbor(usa);
    canada->add_neighbor(usa);

    france->add_neighbor(spain);
    france->add_neighbor(germany);
    france->add_neighbor(italy);
    france->add_neighbor(switzerland);
    spain->add_neighbor(france);
    germany->add_neighbor(france);
    germany->add_neighbor(switzerland);
    italy->add_neighbor(france);
    italy->add_neighbor(switzerland);
    switzerland->add_neighbor(france);
    switzerland->add_neighbor(germany);
    switzerland->add_neighbor(italy);

    // Will make the world (but not Oceania) connected
    usa->add_neighbor(australia);
    canada->add_neighbor(france);
    france->add_neighbor(canada);
    spain->add_neighbor(nz);
    australia->add_neighbor(usa);
    nz->add_neighbor(spain);

    // Adding territories to continents
    std::vector<Territory*> naTerritories;
    naTerritories.push_back(canada);
    naTerritories.push_back(usa);
    naTerritories.push_back(mexico);
    Continent* northAmerica = new Continent("North America", 5, naTerritories);

    std::vector<Territory*> europeTerritories;
    europeTerritories.push_back(france);
    europeTerritories.push_back(germany);
    europeTerritories.push_back(italy);
    europeTerritories.push_back(spain);
    europeTerritories.push_back(switzerland);
    Continent* europe = new Continent("Europe", 8, europeTerritories);

    std::vector<Territory*> oceaniaTerritories;
    oceaniaTerritories.push_back(australia);
    oceaniaTerritories.push_back(nz);
    Continent* oceania = new Continent("Oceania", 3, oceaniaTerritories);

    // Adding continents to map
    std::vector<Continent*> continents;
    continents.push_back(northAmerica);
    continents.push_back(europe);
    continents.push_back(oceania);

    std::vector<Territory*> territories;
    territories.reserve(naTerritories.size() + europeTerritories.size() + oceaniaTerritories.size());
    territories.insert(territories.end(), naTerritories.begin(), naTerritories.end());
    territories.insert(territories.end(), europeTerritories.begin(), europeTerritories.end());
    territories.insert(territories.end(), oceaniaTerritories.begin(), oceaniaTerritories.end());
    Map* world = new Map(continents, territories);

    // Output to user
    std::cout << northAmerica->get_name() << std::endl;
    std::cout << "Connected: " << northAmerica->is_connected() << std::endl << std::endl;

    std::cout << europe->get_name() << std::endl;
    std::cout << "Connected: " << europe->is_connected() << std::endl << std::endl;

    std::cout << oceania->get_name() << std::endl;
    std::cout << "Connected: " << oceania->is_connected() << std::endl << std::endl;

    std::cout << "World" << std::endl;
    std::cout << "Connected: " << world->is_connected() << std::endl;

    //for (Territory* t : world->territories) {
    //	std::cout << t->get_name() << ": ";
    //	for (Territory* e : t->getNeightbors()) {
    //		std::cout << e->get_name() << ", ";
    //	}
    //	std::cout << std::endl;
    //}

	system("PAUSE");
	return 0;
}

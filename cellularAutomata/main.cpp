#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>

struct cell
	{
		bool State;
		cell* neighbour;
		sf::RectangleShape node;
	};

cell** map;

	

void mapGen(int width, int height, int randomSeed, int fillmap)
{
	map = new cell* [height];
	for(int i = 0; i < height; i++)
			{
				map[i] = new cell[width];
				for(int j = 0; j < width; j++)
				{
					randomSeed = rand()%100;
					if(i == 0 || i == height -1 || j == 0 || j == width-1)
					{
						map[i][j].State = true;
					}
					else
					{
						if(randomSeed < fillmap)
						{
							map[i][j].State = true;
						}
						else if(randomSeed > fillmap)
						{
							map[i][j].State = false;
						}
						else
						{
							map[i][j].State = false;
						}
					}
					if(map[i][j].State == true)
					{
						map[i][j].node.setFillColor(sf::Color::Black);
					}
					else
					{
						map[i][j].node.setFillColor(sf::Color::White);
					}

						map[i][j].node.setSize(sf::Vector2f(20,20));
						map[i][j].node.setPosition(j*20, i*20);
						
					}
						
				}
}

int main(int argc, char **argv)
{
	sf::RenderWindow* app = new sf::RenderWindow(sf::VideoMode(1000,600), "cave generation");
	sf::Event e;

	srand(time(NULL));

	

	int width = 40;
	int height = 20;

	

	
	int fillmap = 32;
	int randomSeed = 0;
	
	
			
	mapGen(width,height,randomSeed,fillmap);
	
	

	while(app->isOpen())
	{
		while(app->pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
				app->close();
			
		}
		
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			mapGen(width,height,randomSeed,fillmap);		
		}
		

		app->clear();
		
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				app->draw(map[i][j].node);
			}
		}

		app->display();
		
	}
	delete app;
	delete map;

	std::getchar();
	return 0;
	
}
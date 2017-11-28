#include "background.h"

Background::Background() : Entity()
{
	grid = Vector2(2, 2);
	spawnPos = Vector2(200, 0);
	startX = spawnPos.x;

	size = Vector2(0, 0);

	tileTexture = "assets/cobblestone.png";

	buildBackground();
}

Background::Background(Vector2 gridSize, std::string tiletexture)
{
	grid = gridSize;
	spawnPos = Vector2(0, 0);
	pos = spawnPos;
	startX = spawnPos.x;

	tileTexture = tiletexture;

	buildBackground();
}

Background::Background(Vector2 gridSize, std::string tiletexture, Vector2 tilesize)
{
	grid = gridSize;
	spawnPos2 = Vector2(0, 0);
	pos = spawnPos2;
	startX2 = spawnPos2.x;

	tileTexture = tiletexture;

	buildBackground(tilesize);
}

Background::~Background()
{
	for (unsigned int i = 0; i < tileVector.size(); i++) {
		removechild(tileVector[i]);
		delete tileVector[i];
	}
	tileVector.clear();
}

void Background::update(double deltatime)
{
	Entity::update(deltatime);

}

void Background::buildBackground()
{
	for (int i = 0; i < grid.x * grid.y; i++) {
		spawnTile();
	}
}

void Background::buildBackground(Vector2 tilesize)
{
	for (int i = 0; i < grid.x * grid.y; i++) {
		spawnTile(tilesize);
		//std::cout << i << std::endl;
	}
}

void Background::spawnTile()
{
	Entity* tile = new Entity();
	tile->texturePath = tileTexture;
	tile->size = Vector2(100, 100);
	addchild(tile);
	tileVector.push_back(tile);
	tile->pos = spawnPos;

	if (spawnPos.x <= grid.x * tile->size.x) {
		spawnPos += Vector2(tile->size.x, 0);
	}
	else if(spawnPos.x > grid.x * tile->size.x) {
		spawnPos.x = startX;
		spawnPos.y += tile->size.y;
		//std::cout << spawnPos.x << " " << spawnPos.y << std::endl;
	}

	size = Vector2(grid.x * tile->size.x, grid.y * tile->size.y);
}

void Background::spawnTile(Vector2 tilesize)
{
	Entity* tile = new Entity();
	tile->texturePath = tileTexture;
	tile->size = tilesize;
	
	addchild(tile);
	tileVector.push_back(tile);

	std::cout << spawnPos2.x << std::endl;

	if (spawnPos2.x < grid.x * tile->size.x) {
		spawnPos2 += Vector2(tile->size.x, 0);
	}
	
	tile->pos = spawnPos2;

	if (spawnPos2.x >= grid.x * tile->size.x) {
		spawnPos2.x = startX2;
		spawnPos2.y += tile->size.y;
	}

	size = Vector2(grid.x * tile->size.x, grid.y * tile->size.y);
}

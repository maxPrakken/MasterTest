#include "..\include\entity.h"

int Entity::_nextGuid = 0;

Entity::Entity(SDL_Renderer* renderer)
{
	_guid = _nextGuid;
	_nextGuid++;
	this->_parent = NULL;
	myTex = new Texture(renderer, "assets/INA.tga");

	pos = new Vector2(0, 0);
	scale = new Vector2(100, 100);
}

Entity::~Entity()
{
	delete myTex;
	delete pos;
	delete scale;
}

void Entity::update(double deltatime)
{

}

void Entity::addchild(Entity* child)
{
	if (child->_parent != NULL) {
		child->_parent->removechild(child);
	} 
	if (child->_parent == this) {
		return;
	}
	child->_parent = this;
	this->childrenVec.push_back(child);
}

void Entity::removechild(Entity * child)
{
	std::vector< Entity* >::iterator it = childrenVec.begin();
	while (it != childrenVec.end()) {
		if ((*it)->_guid == child->_guid) {
			it = childrenVec.erase(it);
			return;
		}
		else {
			++it;
		}
	}
}

void Entity::addTexture(std::string path)
{
	myTex = new Texture(Renderer::getInstance()->getRenderer(), path);
}

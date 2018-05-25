#pragma once
#include "Entity.h"
class EmptyEntity :
	public Entity
{
public:
	EmptyEntity();
	~EmptyEntity();
	int ID = 0;
};


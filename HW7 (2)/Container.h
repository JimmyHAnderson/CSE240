#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "room.h"

class Container {
public:
	Room* room;
	Container* next;
	Container();			// constructor
};

#endif // _CONTAINER_H_
#pragma once

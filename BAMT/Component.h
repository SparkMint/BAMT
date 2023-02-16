#ifndef BAMT_COMPONENT
#define BAMT_COMPONENT

#include "Entity.h"

class Entity;

class Component 
{
	public:
		Entity* entity;
		/// <summary>
		/// Called when this instance is loaded.
		/// </summary>
		virtual void Start() = 0;

		/// <summary>
		/// Called every tick.
		/// </summary>
		virtual void Update() = 0;
};
#endif // !BAMT_COMPONENT
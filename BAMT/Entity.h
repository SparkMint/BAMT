#ifndef BAMT_ENTITY
#define BAMT_ENTITY

#include <vector>
#include "Component.h"

class Entity 
{
	private:
		int _ID;

	public:
		/// <summary>
		/// The list of components attached to this entity.
		/// </summary>
		std::vector<Component> components;

		/// <summary>
		/// Collects the ID of this object.
		/// </summary>
		/// <returns>ID Value</returns>
		int GetID();

};

#endif // !BAMT_ENTITY


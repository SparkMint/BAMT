#ifndef BAMT_COMPONENT
#define BAMT_COMPONENT

class Entity;

class Component 
{
	public:
		/// <summary>
		/// The entity we are attached to.
		/// </summary>
		Entity* entity;

		/// <summary>
		/// Called when this instance is loaded.
		/// </summary>
		virtual void Start() = 0;

		/// <summary>
		/// Called every tick.
		/// </summary>
		virtual void Update() = 0;

		/// <summary>
		/// Used for rendering.
		/// </summary>
		virtual void Render() = 0;
};
#endif
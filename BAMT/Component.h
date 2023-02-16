#ifndef BAMT_COMPONENT
#define BAMT_COMPONENT

class Component 
{
	public:
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
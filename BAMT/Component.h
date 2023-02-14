#ifndef BAMT_COMPONENT
#define BAMT_COMPONENT

class Component 
{
	public:
		/// <summary>
		/// Called when this instance is loaded.
		/// </summary>
		void Start();

		/// <summary>
		/// Called every tick.
		/// </summary>
		void Update();
};
#endif // !BAMT_COMPONENT


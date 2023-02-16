#ifndef BAMT_TEST_COMPONENT
#define BAMT_TEST_COMPONENT

#include "Component.h"
#include "Debug.h"

class TestComponent : public Component
{
	public:
		void Start() override;
		void Update() override;
};

class TestComponent2 : public Component
{
};

#endif // !BAMT_TEST_COMPONENT
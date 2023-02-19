#ifndef BAMT_TEST_COMPONENT
#define BAMT_TEST_COMPONENT

#include "Component.h"
#include "Debug.h"
#include "TriRenderer.h"

class TestComponent : public Component
{
	public:
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		bool bamting;
		void DoTheBamt();
};

#endif // !BAMT_TEST_COMPONENT
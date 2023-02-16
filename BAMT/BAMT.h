#ifndef BAMT_ENGINE
#define BAMT_ENGINE

/// WHAT IS THIS FILE? \\\
//----------------------\\

// This file contains all the BAMT related header files.
// Instead of having to include all these files seperately, we can just include
// this header file, which will reference these.

//----------------------\\

#include "EngineManager.h"
#include "Debug.h"
#include "Input.h"


// RENDERING 
#include "Renderer.h"
#include "RectRenderer.h"
#include "TriRenderer.h"


//ENTITY COMPONENT SYSTEM \\

#include "Entity.h"
#include "Component.h"
#include "TestComponent.h"

#endif // !BAMT_ENGINE

#pragma once

namespace SpringEngine
{
	enum class ComponentId
	{
		Invalid,                // Invaild component id
		Transform,              // Transform for component, contains positional data 
		Camera,                 // Stationary camera information
		FPSCamera,              // Functionality for a camera to move
		Mesh,					// Renders a MeshBuilt shape
		Model,					// Renders a Model
		Animator,				// Controls a Model's animation
		RigidBody,              //Adds a rigidbody to the world

		Count
	};

	enum  class ServiceId
	{
		Invalid,               // invalid service id
		Camera,                // Registers and manages focus camera
		Update,				   // Registers and updates any component that requires an update
		Render,                // Registers and renders any graphical components
		Physics,		       // Registers and updates physics based objects

		Count
	};
}

#define SET_TYPE_ID(id)\
static uint32_t StaticGetTypeId(){return static_cast<uint32_t>(id);}\
uint32_t GetTypeId() const override{return StaticGetTypeId();}
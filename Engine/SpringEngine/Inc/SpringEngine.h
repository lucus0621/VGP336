#pragma once

#include "Common.h"
#include "App.h"
#include "AppState.h"

#include "Particle.h"
#include "ParticleSystem.h"
#include "FireworkParticleSystem.h"

#include "Event.h"
#include "EventManager.h"

#include "GameObject.h"
#include "GameObjectHandle.h"
#include "GameWorld.h"
#include "GameObjectFactory.h"

#include "Component.h"
#include "CameraComponent.h"
#include "AnimatorComponent.h"
#include "FPSCameraComponent.h"
#include "MeshComponent.h"
#include "ModelComponent.h"
#include "RenderObjectComponent.h"
#include "TransformComponent.h"

#include "Service.h"
#include "CameraService.h"
#include "RenderService.h"
#include "UpdateService.h"
#include "PhysicsService.h"

namespace SpringEngine
{
	App& MainApp();
}
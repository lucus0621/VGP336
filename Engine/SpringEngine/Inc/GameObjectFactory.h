#pragma once

namespace SpringEngine
{
	class GameObject;
	namespace GameObjectFactory
	{ 
		void Make(const std::filesystem::path& templatePath, GameObject& gameObject);
	}
}
#pragma once

#include "GameObject.h"
#include "Service.h"

namespace SpringEngine
{
	using CustomService = std::function<Service* (const std::string&, GameWorld&)>;

	class GameWorld final
	{
	public:
		static void SetCustomService(CustomService customService);

		[[depricated]]void Initialize();
		void Initialize(uint32_t capacity = 0);
		void Terminate();

		void Update(float deltaTime);
		void Render();
		void DebugUI();

		void LoadLevel(const std::filesystem::path& levelFile);

		GameObject* CreateGameObject(const std::filesystem::path& templateFile, const std::string& name);
		GameObject* GetGameObject(const std::string& name);
		GameObject* GetGameObject(const GameObjectHandle& handle);
		void DestroyGameObject(const GameObjectHandle& handle);

		template<class ServiceType>
		ServiceType* AddService()
		{
			static_assert(std::is_base_of_v<Service, ServiceType>,
				"GameWorld: service must be of type Service");
			ASSERT(!mInitialized, "GameWorld: cant add a service after initialized");
			auto& newService = mServices.emplace_back(std::make_unique<ServiceType>());
			newService->mWorld = this;
			return static_cast<ServiceType*>(newService.get());
		}

		template<class ServiceType>
		const ServiceType* GetService() const
		{
			const GameWorld* thisConst = static_cast<const GameWorld*>(this);
			return const_cast<ServiceType*>(thisConst->GetService<ServiceType>());
		}

		template<class ServiceType>
		 ServiceType* GetService() 
		{
			 for (auto& service : mServices)
			 {
				 if (service->GetTypeId() == ServiceType::StaticGetTypeId())
				 {
					 return static_cast<ServiceType*>(service.get());
				 }
			 }
			 return nullptr;
		}

	private:
		bool IsValid(const GameObjectHandle& handle);
		void ProcessDestroyList();

		struct Slot
		{
			std::unique_ptr<GameObject> gameObject;
			uint32_t generation = 0;
		};

		using Services = std::vector<std::unique_ptr<Service>>;
		using GameObjectSlots = std::vector<Slot>;

		Services mServices;

		GameObjectSlots mGameObjectSlots;
		std::vector<uint32_t> mFreeSlots;
		std::vector<uint32_t> mToBeDestroyed;

		bool mInitialized = false;
	};
}
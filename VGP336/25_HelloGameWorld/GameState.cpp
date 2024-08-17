#include"GameState.h"

using namespace SpringEngine;
using namespace SpringEngine::Graphics;
using namespace SpringEngine::Math;
using namespace SpringEngine::Input;

void GameState::Initialize()
{

	mGameWorld.LoadLevel("../../Assets/Templates/test_level.json");
}
void GameState::Terminate()
{
	mGameWorld.Terminate();
}
void GameState::Update(const float deltaTime)
{
	mGameWorld.Update(deltaTime);
}
void GameState::Render()
{
	mGameWorld.Render();
}
void GameState::DebugUI()
{
	SimpleDraw::AddGroundPlane(10.0f, Colors::White);
	ImGui::Begin("Debug control", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
		mGameWorld.DebugUI();
	ImGui::End();
}
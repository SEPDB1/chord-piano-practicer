#include "Game.h"
#include "Renderer.h"

Game::Game()
{
	Renderer::GetInstance().Init();
	Start();
}

Game::~Game() noexcept = default;

void Game::Render() const
{
	const Renderer& r{ Renderer::GetInstance() };

	r.ClearRenderer();
	RenderGame();
	r.Render();
}

void Game::Update()
{
}

void Game::Start()
{
	key.Press();
	key.Release();
}

void Game::RenderGame() const
{

}

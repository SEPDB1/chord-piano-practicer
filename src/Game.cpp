#include "Game.h"
#include "Renderer.h"
#include "KeyboardModel.h"
#include "KeyboardView.h"
#include <SDL3/SDL_rect.h>
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
	m_pModel = std::make_unique<KeyboardModel>(24, 2);

	const SDL_FPoint center{ Renderer::GetWidth() / 2.f, Renderer::GetHeight() / 2.f };
	m_pView = std::make_unique<KeyboardView>(*m_pModel, center);
}

void Game::RenderGame() const
{
	m_pView->Render();
}

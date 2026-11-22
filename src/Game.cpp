#include "Game.h"
#include "Renderer.h"
#include "KeyboardModel.h"
#include "KeyboardView.h"
#include "KeyboardController.h"
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

void Game::HandleButtonUp(SDL_KeyboardEvent& e)
{
	
}

void Game::HandleButtonDown(SDL_KeyboardEvent& e)
{
	
}

void Game::HandleMouseButtonUp(SDL_MouseButtonEvent& e)
{
	
}

void Game::HandleMouseButtonDown(SDL_MouseButtonEvent& e)
{
	
}

void Game::HandleMouseMotion(SDL_MouseMotionEvent& e)
{
	m_MousePosition.x = e.x;
	m_MousePosition.y = e.y;

	m_pController->OnMouseMotion(m_MousePosition);
}

void Game::Start()
{
	m_pModel = std::make_unique<KeyboardModel>(24, 2);

	const SDL_FPoint center{ Renderer::GetWidth() / 2.f, Renderer::GetHeight() / 2.f };
	m_pView = std::make_unique<KeyboardView>(*m_pModel, center);
	m_pController = std::make_unique<KeyboardController>(*m_pModel, *m_pView);
}

void Game::RenderGame() const
{
	m_pView->Render();
}

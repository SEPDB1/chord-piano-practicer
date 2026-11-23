#include "Game.h"
#include "Renderer.h"
#include "KeyboardModel.h"
#include "AudioManager.h"
#include "KeyboardView.h"
#include "KeyboardController.h"
#include <SDL3/SDL_rect.h>

Game::Game()
{
	Renderer::GetInstance().Init();
	AudioManager::GetInstance().Init();
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
	m_pController->Update(m_MousePosition, m_IsLMBDown);
}

void Game::HandleButtonUp(SDL_KeyboardEvent& e)
{
	switch (e.scancode)
	{
	case SDL_SCANCODE_LSHIFT:
		m_pController->OnPedalUp();
		break;
	}
}

void Game::HandleButtonDown(SDL_KeyboardEvent& e)
{
	switch (e.scancode)
	{
	case SDL_SCANCODE_LSHIFT:
		m_pController->OnPedalDown();
		break;
	}
}

void Game::HandleMouseButtonUp(SDL_MouseButtonEvent& e)
{
	if (e.button == SDL_BUTTON_LEFT)
		m_IsLMBDown = false;
}

void Game::HandleMouseButtonDown(SDL_MouseButtonEvent& e)
{
	if (e.button == SDL_BUTTON_LEFT && !m_IsLMBDown)
		m_IsLMBDown = true;
}

void Game::HandleMouseMotion(SDL_MouseMotionEvent& e)
{
	m_MousePosition.x = e.x;
	m_MousePosition.y = e.y;
}

void Game::Start()
{
	m_pModel = std::make_unique<KeyboardModel>(48, 2);

	const SDL_FPoint center{ Renderer::GetWidth() / 2.f, Renderer::GetHeight() / 2.f };
	m_pView = std::make_unique<KeyboardView>(*m_pModel, center);
	m_pController = std::make_unique<KeyboardController>(*m_pModel, *m_pView);
}

void Game::RenderGame() const
{
	m_pView->Render();
}

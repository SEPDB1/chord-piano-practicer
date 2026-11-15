#include "Renderer.h"
#include <iostream>

Renderer::Renderer() = default;

Renderer::~Renderer() noexcept
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
}

void Renderer::Init()
{
	m_pWindow = SDL_CreateWindow("Chord Practicer", WIDTH, HEIGHT, 0);

	if (!m_pWindow)
		throw std::runtime_error(std::string("Failed to create window: ") + SDL_GetError());

	m_pRenderer = SDL_CreateRenderer(m_pWindow, nullptr);

	if (!m_pRenderer)
		throw std::runtime_error(std::string("Failed to create renderer: ") + SDL_GetError());

	if (!SDL_SetRenderDrawColor(m_pRenderer, 55, 55, 55, 255))
		throw std::runtime_error(std::string("Failed to set draw color") + SDL_GetError());
}

void Renderer::Render() const
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

uint32_t Renderer::GetWidth()
{
	return WIDTH;
}

uint32_t Renderer::GetHeight()
{
	return HEIGHT;
}

SDL_Renderer* Renderer::GetRenderer() const
{
	return m_pRenderer;
}

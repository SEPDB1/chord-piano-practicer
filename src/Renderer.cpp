#include "Renderer.h"
#include <iostream>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

Renderer::Renderer() = default;

Renderer::~Renderer() noexcept
{
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
}

void Renderer::Init()
{
	m_pWindow = SDL_CreateWindow("Chord Practicer", m_Width, m_Height, 0);

	if (!m_pWindow)
		throw std::runtime_error(std::string("Failed to create window: ") + SDL_GetError());

	m_pRenderer = SDL_CreateRenderer(m_pWindow, nullptr);

	if (!m_pRenderer)
		throw std::runtime_error(std::string("Failed to create renderer: ") + SDL_GetError());
}

void Renderer::ClearRenderer() const
{
	SetDrawColor(m_BackgroundColor);
	SDL_RenderClear(m_pRenderer);
}

void Renderer::Render() const
{
	SDL_RenderPresent(m_pRenderer);
}

void Renderer::SetDrawColor(Utils::Color4ub c) const
{
	SDL_SetRenderDrawColor(m_pRenderer, c.r, c.g, c.b, c.a);
}

void Renderer::SetBackgroundColor(Utils::Color4ub c)
{
	m_BackgroundColor = c;
}

void Renderer::DrawRect(const SDL_FRect* rect) const
{
	SDL_RenderRect(m_pRenderer, rect);
}

void Renderer::FillRect(const SDL_FRect* rect) const
{
	SDL_RenderFillRect(m_pRenderer, rect);
}

uint32_t Renderer::GetWidth()
{
	return m_Width;
}

uint32_t Renderer::GetHeight()
{
	return m_Height;
}

SDL_Renderer* Renderer::GetRenderer() const
{
	return m_pRenderer;
}

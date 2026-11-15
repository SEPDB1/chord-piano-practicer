#pragma once
#include "Singleton.h"
#include <cstdint>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_render.h>

/*
 A simple wrapper around SDL_Window
*/
class Renderer final : public Singleton<Renderer>
{
public:
	Renderer();
	~Renderer() noexcept;
	Renderer(const Renderer& other) = delete;
	Renderer(Renderer&& other) = delete;
	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;

	void Init();
	void Render() const;

	static uint32_t GetWidth();
	static uint32_t GetHeight();
	SDL_Renderer* GetRenderer() const;

private:
	static const uint32_t WIDTH{ 1280 };
	static const uint32_t HEIGHT{ 720 };

	SDL_Window* m_pWindow{};
	SDL_Renderer* m_pRenderer{};
};
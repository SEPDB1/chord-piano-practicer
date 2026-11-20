#pragma once
#include "Singleton.h"
#include <cstdint>
#include "Utils.h"

class SDL_Window;
class SDL_Renderer;
struct SDL_FRect;
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

	friend class Game;
	void ClearRenderer() const;
	friend class Game;
	void Render() const;

	void SetDrawColor(Utils::Color4ub c);
	void SetBackgroundColor(Utils::Color4ub c);
	void DrawRect(const SDL_FRect* rect) const;
	void FillRect(const SDL_FRect* rect) const;

	static uint32_t GetWidth();
	static uint32_t GetHeight();
	SDL_Renderer* GetRenderer() const;

private:
	static const uint32_t WIDTH{ 1280 };
	static const uint32_t HEIGHT{ 720 };

	SDL_Window* m_pWindow{};
	SDL_Renderer* m_pRenderer{};
	Utils::Color4ub m_BackgroundColor{ 55, 55, 55 };
};
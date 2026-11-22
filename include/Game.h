#pragma once
#include <memory>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_rect.h>

class KeyboardModel;
class KeyboardView;
class KeyboardController;
class Game final
{
public:
	Game();
	~Game() noexcept;
	Game(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game& operator=(Game&& other) = delete;

	void Render() const;
	void Update();

	void HandleButtonUp(SDL_KeyboardEvent& e);
	void HandleButtonDown(SDL_KeyboardEvent& e);
	void HandleMouseButtonUp(SDL_MouseButtonEvent& e);
	void HandleMouseButtonDown(SDL_MouseButtonEvent& e);
	void HandleMouseMotion(SDL_MouseMotionEvent& e);

private:
	void Start();
	void RenderGame() const;

	std::unique_ptr<KeyboardModel> m_pModel{};
	std::unique_ptr<KeyboardView> m_pView{};
	std::unique_ptr<KeyboardController> m_pController{};
	SDL_FPoint m_MousePosition{};
	bool m_IsLMBDown{ false };
};
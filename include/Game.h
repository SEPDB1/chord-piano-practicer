#pragma once
#include <memory>

class KeyboardModel;
class KeyboardView;
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

private:
	void Start();
	void RenderGame() const;

	std::unique_ptr<KeyboardModel> m_pModel{};
	std::unique_ptr<KeyboardView> m_pView{};
};
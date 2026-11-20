#pragma once
#include <memory>
#include "PianoKeyModel.h"

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

	PianoKeyModel key{ Utils::NoteLetter::ASharp, 1 };
};
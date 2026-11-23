#pragma once
#include "Singleton.h"
#include "Note.h"
#include <fluidsynth.h>

class AudioManager final : public Singleton<AudioManager>
{
public:
	AudioManager() = default;
	~AudioManager() noexcept;
	AudioManager(const AudioManager& other) = delete;
	AudioManager& operator=(const AudioManager& other) = delete;
	AudioManager(AudioManager&& other) noexcept = delete;
	AudioManager& operator=(AudioManager&& other) noexcept = delete;

	void Init();

	void PlayNote(Note::Midi value);
	void StopNote(Note::Midi value);

private:
	fluid_settings_t* m_pSettings{};
	fluid_synth_t* m_pSynth{};
	fluid_audio_driver_t* m_pDriver{};

	inline constexpr static int m_Velocity{ 60 };
};
#include "AudioManager.h"

void AudioManager::Init()
{
	m_pSettings = new_fluid_settings();
	m_pSynth = new_fluid_synth(m_pSettings);
	m_pDriver = new_fluid_audio_driver(m_pSettings, m_pSynth);

	if (fluid_synth_sfload(m_pSynth, "resources/piano.sf2", 1) == FLUID_FAILED)
		std::runtime_error("Failed to load piano.sf2\n");
}

void AudioManager::PlayNote(Note::Midi value)
{
	fluid_synth_noteon(m_pSynth, 0, value, m_Velocity);
}

void AudioManager::StopNote(Note::Midi value)
{
	fluid_synth_noteoff(m_pSynth, 0, value);
}

AudioManager::~AudioManager() noexcept
{
	delete_fluid_audio_driver(m_pDriver);
	delete_fluid_synth(m_pSynth);
	delete_fluid_settings(m_pSettings);
}
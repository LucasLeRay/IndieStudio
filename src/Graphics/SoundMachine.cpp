/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#include "SoundMachine.hpp"

SoundMachine::SoundMachine()
{
	this->volume = VOLUME_BASIC;
	this->engine = irrklang::createIrrKlangDevice();
	this->setVolume(this->volume);
	this->loadSounds();
}

SoundMachine::~SoundMachine()
{
	this->soundList.clear();
}

void SoundMachine::loadSounds()
{
	this->soundSourceList[SoundMachine::SELECT_1] = this->engine->addSoundSourceFromFile("assets/sounds/select_1.wav");
	this->soundSourceList[SoundMachine::MAIN_MUSIC] = this->engine->addSoundSourceFromFile("assets/musics/main_music1.mp3");
	this->soundSourceList[SoundMachine::GAME_MUSIC] = this->engine->addSoundSourceFromFile("assets/musics/game_music1.mp3");
	this->soundSourceList[SoundMachine::START_1] = this->engine->addSoundSourceFromFile("assets/sounds/voice_gamestart.wav");
	this->soundSourceList[SoundMachine::BOMB_EXPLODE] = this->engine->addSoundSourceFromFile("assets/sounds/boom_1.wav");
	this->soundSourceList[SoundMachine::DYING] = this->engine->addSoundSourceFromFile("assets/sounds/voice_no.wav");
	this->soundSourceList[SoundMachine::WINNER] = this->engine->addSoundSourceFromFile("assets/sounds/voice_winner.wav");
	this->soundSourceList[SoundMachine::BONUS] = this->engine->addSoundSourceFromFile("assets/sounds/bonus_1.wav");
}

void SoundMachine::playSound(SoundMachine::typeSound type)
{
	this->soundList[type] = this->engine->play2D(this->soundSourceList[type]);
}

void SoundMachine::stopAllSounds()
{
	this->engine->stopAllSounds();
}

void SoundMachine::setLoopSound(SoundMachine::typeSound type, bool loop)
{
	this->soundList[type] = this->engine->play2D(this->soundSourceList[type], loop);
}

void SoundMachine::setVolume(float volume)
{
	this->engine->setSoundVolume(volume);
}

float SoundMachine::getVolume()
{
	return (this->engine->getSoundVolume());
}
/* 
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description: 
** created by Roméo Nahon 
*/

#ifndef CPP_INDIE_STUDIO_SOUNDMACHINE_HPP
#define CPP_INDIE_STUDIO_SOUNDMACHINE_HPP

#include "irrKlang.h"
#include "indie.hpp"

#define VOLUME_BASIC	0.5f

class   SoundMachine
{
	public:
	enum    typeSound
	{
		SELECT_1,
		START_1,
		MAIN_MUSIC,
		GAME_MUSIC,
		BOMB_EXPLODE,
		DYING,
		WINNER,
		BONUS
	};

	SoundMachine();

	~SoundMachine();

	void            playSound(SoundMachine::typeSound type);

	void            stopAllSounds();

	void            setLoopSound(SoundMachine::typeSound type, bool loop);

	void            setVolume(float volume);

	float           getVolume();

	private:

	void            loadSounds();

	float                                                           volume;
	irrklang::ISoundEngine                                          *engine;
	std::map<SoundMachine::typeSound, irrklang::ISound *>           soundList;
	std::map<SoundMachine::typeSound, irrklang::ISoundSource *>     soundSourceList;
};
#endif //CPP_INDIE_STUDIO_SOUNDMACHINE_HPP

//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The MagicPlayer class is a concrete derived class, inherits from Magic.
///

#pragma once

#include "Magic.h"

// *******************************************************************************
/// The MagicMinion class is a concrete derived class, inherits from Magic.
/// Applies its effect to friendly minions on the board then is discarded.
// *******************************************************************************
class MagicPlayer : public Magic
{
public:

	MagicPlayer(GameDataRef data);
    /// Creates a MagicPlayer object.
    MagicPlayer(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);

    /// Destroys the MagicPlayer object.
    ~MagicPlayer();

    /// Determines the player effect and applies it.
    /// \param[in] board The current game board.
    virtual void effect();

	/// Gets the Minions curHealth.
	/// \return The Minions curHealth.
	virtual sf::Int8 getCurHealth() { return -1; };

	/// Sets the Minions curHealth.
	virtual void setCurHealth(int curHealth) {};

	/// Gets the Minions damageValue.
	/// \return The Minions damageValue.
	virtual sf::Int8 getDamage() { return -1; };

	/// Sets the Minions damageValue.
	virtual void setDamage(int damagealue) {};

	sf::Int8 getId() override
	{
		return MAGIC_PLAYER_CARD;
	}
	
	void read(sf::Packet & is) override;
	sf::Packet write(sf::Packet & os) override;
};


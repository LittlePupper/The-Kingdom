//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose
/// \date Oct 26, 2017
///
///
/// The MagicMinion class is a concrete derived class, inherits from Magic.
///

#pragma once

#include "Magic.h"

// *******************************************************************************
/// The MagicMinion class is a concrete derived class, inherits from Magic.
/// Applies its effect to friendly minions on the board then is discarded.
// *******************************************************************************
class MagicMinion : public Magic
{
public:
    
	MagicMinion(GameDataRef data);
    /// Creates the MagicMinion object and initializes it.
    /// \param[in] id ID of the card.
    /// \param[in] amount The value to be used by the effect.
    MagicMinion(GameDataRef data, std::string name, std::string description, int cost, char ability, int amount);
    
    /// Destroys the MagicMinion object.
    ~MagicMinion();

    /// Determines which minion effect to be used and applies the effect.
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
		return MAGIC_MINION_CARD;
	}

	void read(sf::Packet & is) override;
	sf::Packet write(sf::Packet & os) override;
};



#include "Game.h"
#include "SplashState.h"


Game::Game(int width, int height, std::string title)
{
	//This creates the window for the game and gives it a close button and a titlebar
	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	
	//This adds the first state to the top of the stack which is the Splash Screen
	_data->machine.AddState(StateRef(new SplashState(this->_data)));


	this->Run();
}

void Game::Run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen())
	{
		this->_data->machine.ProcessStateChanges();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;
		while (accumulator >= dt)
		{
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->machine.GetActiveState()->Draw(interpolation);
	}
}

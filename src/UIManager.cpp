#include "UIManager.h"
#include "ResourceManager/ResourceManager.h"
#include <iostream>

// constructor for uimanager
UIManager::UIManager()
    : gameOverOverlay(sf::Vector2f(800, 800)),
      playAgainButton(sf::Vector2f(200, 50)),
      exitButton(sf::Vector2f(200, 50))
{
    std::cout << "uimanager initialized." << std::endl;

    gameOverOverlay.setFillColor(sf::Color(0, 0, 0, 150));

    try
    {
        font = ResourceManager::getInstance().getFont("assets/arial.ttf");
        std::cout << "font loaded successfully." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "error loading font: " << e.what() << std::endl;
    }

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setString("");

    playAgainButton.setFillColor(sf::Color::Green);
    playAgainButton.setPosition(300, 400);

    playAgainText.setFont(font);
    playAgainText.setString("play again");
    playAgainText.setCharacterSize(24);
    playAgainText.setFillColor(sf::Color::White);

    sf::FloatRect playAgainTextBounds = playAgainText.getLocalBounds();
    playAgainText.setPosition(
        playAgainButton.getPosition().x + (playAgainButton.getSize().x - playAgainTextBounds.width) / 2.0f - playAgainTextBounds.left,
        playAgainButton.getPosition().y + (playAgainButton.getSize().y - playAgainTextBounds.height) / 2.0f - playAgainTextBounds.top);

    exitButton.setFillColor(sf::Color::Red);
    exitButton.setPosition(300, 500);

    exitText.setFont(font);
    exitText.setString("exit");
    exitText.setCharacterSize(24);
    exitText.setFillColor(sf::Color::White);

    sf::FloatRect exitTextBounds = exitText.getLocalBounds();
    exitText.setPosition(
        exitButton.getPosition().x + (exitButton.getSize().x - exitTextBounds.width) / 2.0f - exitTextBounds.left,
        exitButton.getPosition().y + (exitButton.getSize().y - exitTextBounds.height) / 2.0f - exitTextBounds.top);
}

// draw the ui elements
void UIManager::draw(sf::RenderWindow &window, GameState gameState)
{
    if (gameState == GameState::GameOver)
    {
        window.draw(gameOverOverlay);
        window.draw(gameOverText);
        window.draw(playAgainButton);
        window.draw(playAgainText);
        window.draw(exitButton);
        window.draw(exitText);
    }
}

// display the game over message
void UIManager::displayGameOver(const std::string &message)
{
    std::cout << "displaying game over message: " << message << std::endl;
    gameOverText.setString(message);

    sf::FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textBounds.left + textBounds.width / 2.0f,
                           textBounds.top + textBounds.height / 2.0f);
    gameOverText.setPosition(400, 200);
}

// handle clicks on game over buttons
void UIManager::handleGameOverClick(sf::Vector2i mousePos,
                                    std::function<void()> onPlayAgain,
                                    std::function<void()> onExit)
{
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    if (playAgainButton.getGlobalBounds().contains(mousePosF))
    {
        std::cout << "play again button clicked." << std::endl;
        onPlayAgain();
    }
    else if (exitButton.getGlobalBounds().contains(mousePosF))
    {
        std::cout << "exit button clicked." << std::endl;
        onExit();
    }
}

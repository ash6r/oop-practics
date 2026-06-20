#include <SFML/Graphics.hpp>
import std;

std::string generate_password(int length, bool use_digits, bool use_symbols) {
	std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (use_digits) {
		chars += "0123456789";
	}
	if (use_symbols) {
		chars += "!@#$%^&*";
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, static_cast<int>(chars.size()) - 1);

	std::string password;
	for (int i = 0; i < length; ++i) {
		password += chars[dist(gen)];
	}
	return password;
}

int main() {
	sf::RenderWindow window(sf::VideoMode({ 400, 300 }), "Password Generator");

	sf::Font font;
	if (!font.openFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
		return 1;
	}

	sf::RectangleShape button(sf::Vector2f(200, 50));
	button.setPosition(sf::Vector2f(100, 50));
	button.setFillColor(sf::Color(70, 130, 180));

	sf::Text button_text(font, "Generate", 20);
    button_text.setFillColor(sf::Color::White);

    sf::FloatRect text_bounds = button_text.getLocalBounds();
    button_text.setOrigin(sf::Vector2f(text_bounds.size.x / 2, text_bounds.size.y / 2));
    button_text.setPosition(sf::Vector2f(
	    button.getPosition().x + button.getSize().x / 2,
	    button.getPosition().y + button.getSize().y / 2
    ));

	sf::Text result_text(font, "", 18);
	result_text.setFillColor(sf::Color::Black);
	result_text.setPosition(sf::Vector2f(50, 150));

	while (window.isOpen()) {
		while (const std::optional<sf::Event> event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			else if (const auto* mouse_button = event->getIf<sf::Event::MouseButtonPressed>()) {
				sf::Vector2f click_pos(static_cast<float>(mouse_button->position.x), static_cast<float>(mouse_button->position.y));
				if (button.getGlobalBounds().contains(click_pos)) {
					std::string password = generate_password(12, true, true);
					result_text.setString(password);
				}
			}
		}

		window.clear(sf::Color::White);
		window.draw(button);
		window.draw(button_text);
		window.draw(result_text);
		window.display();
	}

	return 0;
}

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <array>
#include <sstream>
#include <string>
#include <unordered_map>


namespace
{
struct JoystickObject
{
    sf::Text label;
    sf::Text value;
};

using Texts = std::unordered_map<std::string, JoystickObject>;
Texts              texts;
std::ostringstream sstr;
float              threshold = 0.1f;

// Axes labels in as strings
const std::array<std::string, 8> axislabels = {"X", "Y", "Z", "R", "U", "V", "PovX", "PovY"};

// Helper to set text entries to a specified value
template <typename T>
void set(const std::string& label, const T& value)
{
    sstr.str("");
    sstr << value;
    texts.at(label).value.setString(sstr.str());
}

// Update joystick identification
void updateIdentification(unsigned int index)
{
    sstr.str("");
    sstr << "Joystick " << index << ":";
    auto& [label, value] = texts.at("ID");
    label.setString(sstr.str());
    value.setString(sf::Joystick::getIdentification(index).name);
}

// Update joystick axes
void updateAxes(unsigned int index)
{
    for (unsigned int j = 0; j < sf::Joystick::AxisCount; ++j)
    {
        if (sf::Joystick::hasAxis(index, static_cast<sf::Joystick::Axis>(j)))
            set(axislabels[j], sf::Joystick::getAxisPosition(index, static_cast<sf::Joystick::Axis>(j)));
    }
}

// Update joystick buttons
void updateButtons(unsigned int index)
{
    for (unsigned int j = 0; j < sf::Joystick::getButtonCount(index); ++j)
    {
        sstr.str("");
        sstr << "Button " << j;

        set(sstr.str(), sf::Joystick::isButtonPressed(index, j));
    }
}

// Helper to update displayed joystick values
void updateValues(unsigned int index)
{
    if (sf::Joystick::isConnected(index))
    {
        // Update the label-value sf::Text objects based on the current joystick state
        updateIdentification(index);
        updateAxes(index);
        updateButtons(index);
    }
}
} // namespace


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
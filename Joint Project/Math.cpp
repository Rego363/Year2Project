#include "Math.h"

namespace Math
{
	double distance(sf::Vector2f v1, sf::Vector2f v2)
	{
		return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	}

	sf::Vector2f truncate(sf::Vector2f v, float const num)
	{
		float i;
		i = num / thor::length(v);
		i = i < 1.0 ? i : 1.0;
		v *= i;
		return v;
	}
}
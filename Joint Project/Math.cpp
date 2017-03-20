#include "Math.h"

namespace Math
{
	double distance(sf::Vector2f v1, sf::Vector2f v2)
	{
		return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	}

	sf::Vector2f truncate(sf::Vector2f v, float num)
	{
		num = num / thor::length(v);
		num = num < 1.0 ? num : 1.0;
		v *= num;
		return v;
	}

	float dotProduct(sf::Vector2f a, sf::Vector2f b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	float length(sf::Vector2f a)
	{
		return std::sqrt((a.x * a.x) + (a.y * a.y));
	}
}
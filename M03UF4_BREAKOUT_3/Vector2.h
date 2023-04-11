#pragma once

class Vector2 {
public:
	int x;
	int y;
	Vector2() : x(0), y(0) {}
	Vector2(int x, int y) : x(x), y(y) {}
	const Vector2 operator+ (Vector2& other) {
		Vector2 result(x + other.x, y + other.y);
		return result;
	}
	bool operator== (Vector2& other) {
		return x == other.x && y == other.y;
	}
};


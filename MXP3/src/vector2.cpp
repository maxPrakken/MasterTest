#include "../include/vector2.h"

Vector2::Vector2() {

}

Vector2::Vector2(double x_, double y_) {
	x = x_;
	y = y_;
}

Vector2::~Vector2() {

}

Vector2 Vector2::operator+(const Vector2 & oth)
{
	return Vector2(this->x + oth.x, this->y + oth.y);
}

void Vector2::operator+=(const Vector2 & oth)
{
	this->x += oth.x;
	this->y += oth.y;
}

Vector2 Vector2::operator-(const Vector2 & oth)
{
	return Vector2(this->x - oth.x, this->y - oth.y);
}

void Vector2::operator-=(const Vector2 & oth)
{
	this->x -= oth.x;
	this->y -= oth.y;
}

Vector2 Vector2::operator*(const Vector2 & oth)
{
	return Vector2(this->x * oth.x, this->y * oth.y);
}

Vector2 Vector2::operator*(const float & oth)
{
	return Vector2(x * oth, y * oth);
}

Vector2 Vector2::operator*=(const float & oth)
{
	return Vector2(x *= oth, y *= oth);
}

Vector2 Vector2::operator*(const double & oth)
{
	return Vector2(x * oth, y * oth);
}

void Vector2::operator*=(const Vector2 & oth)
{
	this->x *= oth.x;
	this->y *= oth.y;
}

Vector2 Vector2::operator/(const Vector2 & oth)
{
	return Vector2(this->x / oth.x, this->y / oth.y);
}

void Vector2::operator/=(const Vector2 & oth)
{
	this->x /= oth.x;
	this->y /= oth.y;
}

void Vector2::operator/=(const float & oth)
{
	this->x /= oth;
	this->y /= oth;
}

void Vector2::operator/(const float & oth)
{
	this->x / oth;
	this->y / oth;
}

void Vector2::normalize() {
	int i = mag();
	if (i != 0) {
		y = y / i;
		x = x / i;
	}
}

int Vector2::mag() {
	return sqrt(x*x + y*y);
}
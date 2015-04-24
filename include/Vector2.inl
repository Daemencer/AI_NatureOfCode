template <typename T>
Vector2<T>::Vector2() : x(0), y(0) 
{
}


template <typename T>
Vector2<T>::Vector2(T p_x, T p_y)
{
    x = p_x;
    y = p_y;
}


template <typename T>
Vector2<T>::Vector2(const Vector2<T>& v)
{
    x = v.x;
    y = v.y;
}


template <typename T>
Vector2<T>& Vector2<T>::operator = (const Vector2<T>& v)
{
    x = v.x;
    y = v.y;
    return *this;
}


//Mathematical functions
template <typename T>
auto    Vector2<T>::add(const Vector2<T>& v) -> Vector2<T>&
{
    x += v.x;
    y += v.y;
    return *this;
}


template <typename T>
auto    Vector2<T>::sub(const Vector2<T>& v) -> Vector2<T>&
{
    x -= v.x;
    y -= v.y;
    return *this;
}


template <typename T>
auto    Vector2<T>::mult(const Vector2<T>& v) -> Vector2<T>&
{
    x *= v.x;
    y *= v.y;
    return *this;
}


template <typename T>
auto    Vector2<T>::mult(float f) -> Vector2<T>&
{
    x *= f;
    y *= f;
    return *this;
}


template <typename T>
auto    Vector2<T>::div(float f) -> Vector2<T>&
{
	x /= f;
	y /= f;
	return *this;
}


template <typename T>
auto    Vector2<T>::mag() const -> float
{
	return sqrt(x * x + y * y);
}


template <typename T>
auto    Vector2<T>::normalize() -> Vector2<T>&
{
	float m = mag();

	if (0 != m)
	{
		this->div(m);
	}

	return *this;
}


template <typename T>
auto	Vector2<T>::limit(float max)	-> void
{
	x = std::min((float)x, max);
	y = std::min((float)y, max);
}


template <typename T>
auto	Vector2<T>::dist(const Vector2<T>& v) -> float
{
	return sqrt(((v.x - x)*(v.x - x)) + ((v.y - y)*(v.y - y)));
}


template <typename T>
auto    Vector2<T>::invert() -> Vector2<T>&
{
    x *= -1;
    y *= -1;
    return *this;
}


template <typename T>
auto    Vector2<T>::dotProduct(const Vector2<T>& v) const -> float
{
    return (x * v.x + y * v.y);
}


template <typename T>
auto    Vector2<T>::crossProduct(const Vector2<T>& v) const -> float
{
    return (x * v.y - y * v.x);
}


template <typename T>
auto	Vector2<T>::clip(float min, float max) -> void
{
	x = x < min ? min : (x > max ? max : x);
	y = y < min ? min : (y > max ? max : y);
}


template <typename T>
auto	Vector2<T>::clip(const Vector2<T>& v) -> void
{
	x = x < v.x ? v.x : (x > v.y ? v.y : x);
	y = y < v.x ? v.x : (y > v.y ? v.y : y);
}


template <typename T>
auto 	Vector2<T>::heading() const -> float
{
	return std::atan2(x, y);
}


// STATIC
template <typename T>
auto	Vector2<T>::add(const Vector2<T>& v1, const Vector2<T>& v2) -> Vector2<T>
{
	return Vector2<T>(v1.x + v2.x, v1.y + v2.y);
}


template <typename T>
auto	Vector2<T>::sub(const Vector2<T>& v1, const Vector2<T>& v2) -> Vector2<T>
{
	return Vector2<T>(v1.x - v2.x, v1.y - v2.y);
}


template <typename T>
auto	Vector2<T>::mult(const Vector2<T>& v, float f) -> Vector2<T>
{
	return Vector2<T>(v.x * f, v.y * f);
}


template <typename T>
auto	Vector2<T>::mult(const Vector2<T>& v1, const Vector2<T>& v2) -> Vector2<T>
{
	return Vector2<T>(v1.x * v2.x, v1.y * v2.y);
}


template <typename T>
auto	Vector2<T>::div(const Vector2<T>& v, float f) -> Vector2<T>
{
	return Vector2<T>(v.x / f, v.y / f);
}


template <typename T>
auto	Vector2<T>::normalize(const Vector2<T>& v) -> Vector2<T>
{
	Vector2<T> ret = v;
	return ret.normalize();
}


template <typename T>
auto	Vector2<T>::dist(const Vector2<T>& v1, const Vector2<T>& v2) -> float
{
	Vector2<T> ret = v1;
	return ret.dist(v2);
}


template <typename T>
auto	Vector2<T>::inverted(const Vector2<T>& v) -> Vector2<T>
{
	Vector2<T>	ret = v;
	ret.x *= -1;
	ret.y *= -1;
	return ret;
}


template <typename T>
auto    Vector2<T>::dotProduct(const Vector2<T>& v1, const Vector2<T>& v2) -> float
{
	Vector2<T> ret = v1;
	return ret.dotProduct(v2);
}


template <typename T>
auto    Vector2<T>::crossProduct(const Vector2<T>& v1, const Vector2<T>& v2) -> float
{
	Vector2<T> ret = v1;
	return ret.crossProduct(v2);
}


template <typename T>
auto	Vector2<T>::clip(const Vector2<T>& v, float min, float max) -> Vector2
{
	Vector2<T>	ret = v;

	ret.x = ret.x < min ? min : (ret.x > max ? max : ret.x);
	ret.y = ret.y < min ? min : (ret.y > max ? max : ret.y);

	return ret;
}


template <typename T>
auto	Vector2<T>::clip(const Vector2<T>& v1, const Vector2<T>& v2) -> Vector2
{
	Vector2<T>	ret = v1;

	ret.x = ret.x < v2.x ? v2.x : (ret.x > v2.y ? v2.y : ret.x);
	ret.y = ret.y < v2.x ? v2.x : (ret.y > v2.y ? v2.y : ret.y);

	return ret;
}


//Dereference operator overload
template <typename T>
Vector2<T>  Vector2<T>::operator * () const
{
    return *this;
}


//Arithmetic operators overload
template <typename T>
auto    Vector2<T>::operator +  (const Vector2<T>& rhs) const -> Vector2<T>
{
	return Vector2<T>::add(this, rhs);
}


template <typename T>
auto    Vector2<T>::operator += (const Vector2<T>& rhs) -> Vector2<T>&
{
    return this->add(rhs);
}



template <typename T>
auto    Vector2<T>::operator -  (const Vector2<T>& rhs) const -> Vector2
{
	return Vector2<T>::sub(this, rhs);
}


template <typename T>
auto    Vector2<T>::operator -= (const Vector2<T>& rhs) -> Vector2&
{
    return this->sub(rhs);
}


template <typename T>
auto    Vector2<T>::operator *  (const Vector2<T>& rhs) const -> Vector2
{
	return Vector2<T>::mult(this, rhs);
}


template <typename T>
auto    Vector2<T>::operator *= (const Vector2<T>& rhs) -> Vector2&
{
    return this->mult(rhs);
}


template <typename T>
auto    Vector2<T>::operator /  (const Vector2<T>& rhs) const -> Vector2
{
    return Vector2<T>::div(this, rhs);
}


template <typename T>
auto    Vector2<T>::operator /= (const Vector2<T>& rhs) -> Vector2&
{
    return this->div(rhs);
}


/*
template class Vector2<short>;
template class Vector2<unsigned int>;
template class Vector2<int>;
template class Vector2<long>;
template class Vector2<float>;
template class Vector2<double>;
*/

template <typename T>
std::ostream&   operator << (std::ostream& os, Vector2<T> const& v)
{
    os << "Vector2" << " : [" << v.x << ", " << v.y << "]";
    return os;
}

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
Vector2<T>::Vector2(Vector2<T> const& v)
{
    x = v.x;
    y = v.y;
}


template <typename T>
Vector2<T>& Vector2<T>::operator = (Vector2<T> const& v)
{
    x = v.x;
    y = v.y;
    return *this;
}


//Mathematical functions
template <typename T>
auto    Vector2<T>::add(Vector2<T> const& v) -> Vector2<T>&
{
    x += v.x;
    y += v.y;
    return *this;
}


template <typename T>
auto    Vector2<T>::add(Vector2<T> const& v) const -> Vector2<T>
{
    return Vector2<T>(x + v.x, y + v.y);
}



template <typename T>
auto    Vector2<T>::sub(Vector2<T> const& v) -> Vector2<T>&
{
    x -= v.x;
    y -= v.y;
    return *this;
}


template <typename T>
auto    Vector2<T>::sub(Vector2<T> const& v) const -> Vector2<T>
{
    return Vector2<T>(x - v.x, y - v.y);
}



template <typename T>
auto    Vector2<T>::mult(Vector2<T> const& v) -> Vector2<T>&
{
    x *= v.x;
    y *= v.y;
    return *this;
}


template <typename T>
auto    Vector2<T>::mult(Vector2<T> const& v) const -> Vector2<T>
{
    return Vector2<T>(x * v.x, y * v.y);
}


template <typename T>
auto    Vector2<T>::mult(float f) -> Vector2<T>&
{
    x *= f;
    y *= f;
    return *this;
}


template <typename T>
auto    Vector2<T>::mult(float f) const -> Vector2<T>
{
    return Vector2<T>(x * f, y * f);
}


template <typename T>
auto    Vector2<T>::div(float f) -> Vector2<T>&
{
	x /= f;
	y /= f;
	return *this;
}


template <typename T>
auto    Vector2<T>::div(float f) const -> Vector2<T>
{
	return Vector2<T>(x / f, y / f);
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
auto    Vector2<T>::normalize() const -> Vector2<T>
{
    Vector2<T> ret = *this;
    return ret.normalize();
}


template <typename T>
auto    Vector2<T>::invert() -> Vector2<T>&
{
    x *= -1;
    y *= -1;
    return *this;
}


template <typename T>
auto    Vector2<T>::getInverted() const -> Vector2<T>
{
    Vector2<T> ret = *this;
    ret.x *= -1;
    ret.y *= -1;
    return ret;
}



template <typename T>
auto    Vector2<T>::dotProduct(Vector2<T> const& v) const -> float
{
    return (x * v.x + y * v.y);
}


template <typename T>
auto    Vector2<T>::crossProduct(Vector2<T> const& v) const -> float
{
    return (x * v.y - y * v.x);
}



//Dereference operator overload
template <typename T>
Vector2<T>  Vector2<T>::operator * () const
{
    return *this;
}


//Arithmetic operators overload
template <typename T>
auto    Vector2<T>::operator +  (Vector2<T> const& rhs) const -> Vector2<T>
{
    return this->add(rhs);
}


template <typename T>
auto    Vector2<T>::operator += (Vector2<T> const& rhs) -> Vector2<T>&
{
    return this->add(rhs);
}



template <typename T>
auto    Vector2<T>::operator -  (Vector2 const& rhs) const -> Vector2
{
    return this->sub(rhs);
}


template <typename T>
auto    Vector2<T>::operator -= (Vector2 const& rhs) -> Vector2&
{
    return this->sub(rhs);
}



template <typename T>
auto    Vector2<T>::operator *  (Vector2 const& rhs) const -> Vector2
{
    return this->mult(rhs);
}


template <typename T>
auto    Vector2<T>::operator *= (Vector2 const& rhs) -> Vector2&
{
    return this->mult(rhs);
}



template class Vector2<short>;
template class Vector2<unsigned int>;
template class Vector2<int>;
template class Vector2<long>;
template class Vector2<float>;
template class Vector2<double>;


template <typename T>
std::ostream&   operator << (std::ostream& os, Vector2<T> const& v)
{
    os << "Vector2" << " : [" << v.x << ", " << v.y << "]";
    return os;
}

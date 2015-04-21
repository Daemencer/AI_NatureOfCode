namespace Utils
{
namespace Math
{

template <typename T>
Vector2<T>::Vector2() : _x(0), _y(0) 
{
}


template <typename T>
Vector2<T>::Vector2(T x, T y)
{
    _x = x;
    _y = y;
}


template <typename T>
Vector2<T>::Vector2(Vector2<T> const& v)
{
    _x = v.getX();
    _y = v.getY();
}


template <typename T>
Vector2<T>& Vector2<T>::operator = (Vector2<T> const& v)
{
    _x = v.getX();
    _y = v.getY();
    return *this;
}


//Getters
template <typename T>
T   Vector2<T>::getX() const
{
    return _x;
}


template <typename T>
T   Vector2<T>::getY() const
{
    return _y;
}



//Setters
template <typename T>
auto    Vector2<T>::set(float x, float y) -> void
{
    _x = x;
    _y = y;
}



//Mathematical functions
template <typename T>
auto    Vector2<T>::add(Vector2<T> const& v) -> Vector2<T>&
{
    _x += v._x;
    _y += v._y;
    return *this;
}


template <typename T>
auto    Vector2<T>::add(Vector2<T> const& v) const -> Vector2<T>
{
    return Vector2<T>(_x + v._x, _y + v._y);
}



template <typename T>
auto    Vector2<T>::sub(Vector2<T> const& v) -> Vector2<T>&
{
    _x -= v._x;
    _y -= v._y;
    return *this;
}


template <typename T>
auto    Vector2<T>::sub(Vector2<T> const& v) const -> Vector2<T>
{
    return Vector2<T>(_x - v._x, _y - v._y);
}



template <typename T>
auto    Vector2<T>::mult(Vector2<T> const& v) -> Vector2<T>&
{
    _x *= v._x;
    _y *= v._y;
    return *this;
}


template <typename T>
auto    Vector2<T>::mult(Vector2<T> const& v) const -> Vector2<T>
{
    return Vector2<T>(_x * v._x, _y * v._y);
}



template <typename T>
auto    Vector2<T>::mult(float const& f) -> Vector2<T>&
{
    _x *= f;
    _y *= f;
    return *this;
}


template <typename T>
auto    Vector2<T>::mult(float const& f) const -> Vector2<T>
{
    return Vector2<T>(_x * f, _y * f);
}



template <typename T>
auto    Vector2<T>::getNorm() const -> float
{
    return sqrt(_x * _x + _y * _y);
}



template <typename T>
auto    Vector2<T>::normalize() -> Vector2<T>&
{
    float n = 1 / this->getNorm();

    if (0 != n)
    {
        _x *= n;
        _y *= n;
    }

    return *this;
}


template <typename T>
auto    Vector2<T>::getNormalized() const -> Vector2<T>
{
    Vector2<T> ret = *this;
    return ret.normalize();
}



template <typename T>
auto    Vector2<T>::invert() -> Vector2<T>&
{
    _x *= -1;
    _y *= -1;
    return *this;
}


template <typename T>
auto    Vector2<T>::getInverted() const -> Vector2<T>
{
    Vector2<T> ret = *this;
    ret._x *= -1;
    ret._y *= -1;
    return ret;
}



template <typename T>
auto    Vector2<T>::dotProduct(Vector2<T> const& v) const -> float
{
    return (_x * v._x + _y * v._y);
}


template <typename T>
auto    Vector2<T>::crossProduct(Vector2<T> const& v) const -> float
{
    return (_x * v._y - _y * v._x);
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

} // namespace Math

} /* namespace Engine */


template <typename T>
std::ostream&   operator << (std::ostream& os, Utils::Math::Vector2<T> const& v)
{
    os << "Vector2 -> x:" << v.getX() << ", y:" << v.getY() << std::endl;
    return os;
}

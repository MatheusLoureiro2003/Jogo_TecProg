#pragma once

#include <iostream>

namespace Matematica {

    template <typename TL>
    class Coordenada {
    public:
        TL x;
        TL y;

    public:
        Coordenada(TL x, TL y);
        Coordenada();
        ~Coordenada() { }

        void operator=(Coordenada<TL> other);
        void operator+=(Coordenada<TL> other);
        void operator-=(Coordenada<TL> other);
        void operator*=(double scalar);
        void operator/=(double scalar);

        Coordenada<TL> operator+(Coordenada<TL> other);
        Coordenada<TL> operator-(Coordenada<TL> other);
        Coordenada<TL> operator*(Coordenada<TL> other);
        Coordenada<TL> operator*(double scalar);
        Coordenada<TL> operator/(Coordenada<TL> other);
        Coordenada<TL> operator/(double scalar);
    };

    typedef Coordenada<double> CoordD;
    typedef Coordenada<float> CoordF;
    typedef Coordenada<int> CoordI;
    typedef Coordenada<unsigned int> CoordU;

    template <typename TL>
    Coordenada<TL>::Coordenada(TL x, TL y) :
        x(x),
        y(y) { }

    template <typename TL>
    Coordenada<TL>::Coordenada() {
        this->x = 0;
        this->y = 0;
    }

    template <typename TL>
    void Coordenada<TL>::operator=(Coordenada<TL> other) {
        this->x = other.x;
        this->y = other.y;
    }

    template <typename TL>
    void Coordenada<TL>::operator+=(Coordenada<TL> other) {
        this->x += other.x;
        this->y += other.y;
    }

    template <typename TL>
    void Coordenada<TL>::operator-=(Coordenada<TL> other) {
        this->x -= other.x;
        this->y -= other.y;
    }

    template <typename TL>
    void Coordenada<TL>::operator*=(double scalar) {
        this->x = this->x * scalar;
        this->y = this->y * scalar;
    }

    template <typename TL>
    void Coordenada<TL>::operator/=(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        this->x /= scalar;
        this->y /= scalar;
    }

    template <typename TL>
    Coordenada<TL> Coordenada<TL>::operator+(Coordenada<TL> other) {
        return Coordenada<TL>(this->x + other.x, this->y + other.y);
    }

    template <typename TL>
    Coordenada<TL> Coordenada<TL>::operator-(Coordenada<TL> other) {
        return Coordenada<TL>(this->x - other.x, this->y - other.y);
    }

    template <typename TL>
    Coordenada<TL> Coordenada<TL>::operator*(Coordenada<TL> other) {
        return Coordenada<TL>(this->x * other.x, this->y * other.y);
    }

    template <typename TL>
    Coordenada<TL> Coordenada<TL>::operator*(double scalar) {
        return Coordenada<TL>(this->x * scalar, this->y * scalar);
    }

    template <typename TL>
    Coordenada<TL> Coordenada<TL>::operator/(Coordenada<TL> other) {
        if (other.x == 0.0f || other.y == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        return Coordenada<TL>(this->x / other.x, this->y / other.y);
    }

    template <typename TL>
    Coordenada<TL> Coordenada<TL>::operator/(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }

        return Coordenada<TL>(this->x / scalar, this->y / scalar);
    }

}

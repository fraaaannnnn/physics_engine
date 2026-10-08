#ifndef PHYSICS_ENGINE_VECTOR2_H
#define PHYSICS_ENGINE_VECTOR2_H
#include <cmath>
#include <iostream>

/*  Vector2D.
 *  A class that represents a vector in a 2D space
 *  It has all the basics operations implemented and the dot product
 * */
class Vector2 {
    public:
    float x, y;
    constexpr Vector2() : x(0.0f), y(0.0f) {}
    constexpr Vector2(const float x_val, const float y_val) : x(x_val), y(y_val) {}

    static const Vector2 X;
    static const Vector2 Y;
    static const Vector2 ZERO;

    //Magnitude return
    [[nodiscard]] float getMagnitude() const { return std::sqrt((x * x) + (y * y)); }
    [[nodiscard]] float getMagnitudeSqrd() const { return (x * x) + (y * y); }

    Vector2 operator + (const Vector2 &vector) const {
        return {x + vector.x, y + vector.y};
    }
    Vector2 operator - (const Vector2 &vector) const {
        return {x - vector.x, y - vector.y};
    }
    Vector2 operator * (float scalar) const {
        return {x * scalar, y * scalar};
    }
    [[nodiscard]] float dot_p (const Vector2 &vector) const {
        return x * vector.x + y * vector.y ;
    }
    [[nodiscard]] Vector2 normalize () const {
        float mag = getMagnitude();
        if (mag > 1e-8f) {
            float invMag = 1.0f / mag;
            return {x * invMag, y * invMag};
        }
        return ZERO;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os; // Return the stream so we can chain outputs
    }
};

inline constexpr Vector2 Vector2::X{1.0f, 0.0f};
inline constexpr Vector2 Vector2::Y{0.0f, 1.0f};
inline constexpr Vector2 Vector2::ZERO{0.0f, 0.0f};

/*  Vector3D.
 *  A class that represents a vector in a 3D space
 *  It has the same methods as the 2D vector plus the
 *  cross product method which cant be applied to 2D vectors.
 */
class Vector3 {
    public:
    float x, y, z;
    constexpr Vector3() : x(0.0f), y(0.0f), z(0.0f){}
    constexpr Vector3(const float x_val, const float y_val, const float z_val) : x(x_val), y(y_val), z(z_val){}

    static const Vector3 X;
    static const Vector3 Y;
    static const Vector3 Z;
    static const Vector3 ZERO;

    //Magnitude return
    [[nodiscard]] float getMagnitude() const { return std::sqrt((x * x) + (y * y) + (z * z)); }
    [[nodiscard]] float getMagnitudeSqrd() const { return (x * x) + (y * y) + (z * z); }

    constexpr Vector3 operator + (const Vector3 &vector) const {
        return {x + vector.x, y + vector.y, z + vector.z};
    }
    constexpr Vector3 operator - (const Vector3 &vector) const {
        return {x - vector.x, y - vector.y, z - vector.z};
    }
    constexpr Vector3 operator * (float scalar) const {
        return {scalar * x, y * scalar, z * scalar};
    }
    [[nodiscard]] float dot_p (const Vector3 &vector) const {
        return x * vector.x + y * vector.y + z * vector.z;
    }
    [[nodiscard]] Vector3 cross_p (const Vector3 &vector) const {
        return {y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y *vector.x};
    }
    [[nodiscard]] Vector3 normalize () const {
        float mag = getMagnitude();
        if (mag > 1e-8f) {
            float invMag = 1.0f / mag;
            return {x * invMag, y * invMag, z * invMag};
        }
        return ZERO;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};
inline constexpr Vector3 operator*(float scalar, const Vector3& v) {
    return v * scalar;
}
inline constexpr Vector3 Vector3::X{1.0f, 0.0f, 0.0f};
inline constexpr Vector3 Vector3::Y{0.0f, 1.0f, 0.0f};
inline constexpr Vector3 Vector3::Z{0.0f, 0.0f, 1.0f};
inline constexpr Vector3 Vector3::ZERO{0.0f, 0.0f, 0.0f};

#endif //PHYSICS_ENGINE_VECTOR2_H
#ifndef PHYSICS_ENGINE_VECTOR2_H
#define PHYSICS_ENGINE_VECTOR2_H
#include <cmath>

/*  Vector2D.
 *  A class that represents a vector in a 2D space
 *  It has all the basics operations implemented and the dot product
 * */
class Vector2 {
    private:
    float x, y;
    public:
    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(const float x_val, const float y_val) : x(x_val), y(y_val) {}

    //Getters
    [[nodiscard]] constexpr float getX() const { return x; }
    [[nodiscard]] constexpr float getY() const { return y; }
    [[nodiscard]] constexpr float getMagnitude() const { return std::sqrt((x * x) + (y * y)); }

    //Setters
    void setX(const float x_val) { x = x_val; }
    void setY(const float y_val) { y = y_val; }



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
        return {x/std::sqrt((x * x) + (y * y)), y/std::sqrt((x * x) + (y * y))};
    }
};

/*  Vector3D.
 *  A class that represents a vector in a 3D space
 *  It has the same methods as the 2D vector plus the
 *  cross product method which cant be applied to 2D vectors.
 */
class Vector3 {
    private:
    float x, y, z;
    public:
    constexpr Vector3() : x(0.0f), y(0.0f), z(0.0f){}
    constexpr Vector3(const float x_val, const float y_val, const float z_val) : x(x_val), y(y_val), z(z_val){}

    [[nodiscard]] constexpr float getX() const { return x; }
    [[nodiscard]] constexpr float getY() const { return y; }
    [[nodiscard]] constexpr float getZ() const { return z; }
    [[nodiscard]] constexpr float getMagnitude() const { return std::sqrt((x * x) + (y * y) + (z * z)); }


    static const Vector3 X;
    static const Vector3 Y;
    static const Vector3 Z;
    static const Vector3 ZERO;
    constexpr Vector3 operator + (const Vector3 &vector) const {
        return {x + vector.x, y + vector.y, z + vector.z};
    }
    constexpr Vector3 operator - (const Vector3 &vector) const {
        return {x - vector.x, y - vector.y, z - vector.z};
    }
    constexpr Vector3 operator * (float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }
    [[nodiscard]] float dot_p (const Vector3 &vector) const {
        return x * vector.x + y * vector.y + z * vector.z;
    }
    [[nodiscard]] Vector3 cross_p (const Vector3 &vector) const {
        return {y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y *vector.x};
    }
    [[nodiscard]] Vector3 normalize () const {
        return {x/std::sqrt((x * x) + (y * y) + (z * z)), y/std::sqrt((x * x) + (y * y) + (z * z)), z/std::sqrt((x * x) + (y * y) + (z * z))};
    }
};
inline constexpr Vector3 Vector3::X{1.0f, 0.0f, 0.0f};
inline constexpr Vector3 Vector3::Y{0.0f, 1.0f, 0.0f};
inline constexpr Vector3 Vector3::Z{0.0f, 0.0f, 1.0f};
inline constexpr Vector3 Vector3::ZERO{0.0f, 0.0f, 0.0f};

#endif //PHYSICS_ENGINE_VECTOR2_H
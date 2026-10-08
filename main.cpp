#include <iostream>
#include "Vector.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    Vector2 v2(1,2);
    Vector3 v3(1,2,3);
    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v2.getMagnitude() << std::endl;
    std::cout << v3.getMagnitude() << std::endl;
    v2 = v2.normalize();
    v3 = v3.normalize();

    std::cout << v2 << std::endl;
    std::cout << v3 << std::endl;
    std::cout << v2.getMagnitude() << std::endl;
    std::cout << v3.getMagnitude() << std::endl;

}
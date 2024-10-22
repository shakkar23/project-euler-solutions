#pragma once

#include "../math/math.hpp"

// TRIANGLE/POINT
inline bool triPoint(float x1, float y1, float x2, float y2, float x3, float y3, float px, float py) {
    // get the area of the triangle
    float areaOrig = std::abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));

    // get the area of 3 triangles made between the point
    // and the corners of the triangle
    float area1 = std::abs((x1 - px) * (y2 - py) - (x2 - px) * (y1 - py));
    float area2 = std::abs((x2 - px) * (y3 - py) - (x3 - px) * (y2 - py));
    float area3 = std::abs((x3 - px) * (y1 - py) - (x1 - px) * (y3 - py));

    // if the sum of the three areas equals the original,
    // we're inside the triangle!
    if (area1 + area2 + area3 == areaOrig) {
        return true;
    }
    return false;
}

inline auto problem_102() {
    // download the file from https://projecteuler.net/resources/documents/0102_triangles.txt
    std::ifstream file("problems/0102_triangles.txt");

    if (!file.is_open()) {
        std::cerr << "Could not open file" << std::endl;
        return -1;
    }

    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        std::vector<int> points;
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            points.push_back(std::stoi(token));
        }

        int x1 = points[0];
        int y1 = points[1];
        int x2 = points[2];
        int y2 = points[3];
        int x3 = points[4];
        int y3 = points[5];

        if (triPoint(x1, y1, x2, y2, x3, y3, 0, 0)) {
            count++;
        }
    }

    return count;
}

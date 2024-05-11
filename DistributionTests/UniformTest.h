#ifndef UNIFORMTEST_H
#define UNIFORMTEST_H

#include "Test.h"
#include <random>

template<typename T>
class UniformTest : public Test<T> {
public:
    UniformTest(int numSamples) : Test<T>(numSamples) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-0.0, 100.0);

        for (int i = 0; i < numSamples; ++i) {
            this->data.push_back(dis(gen));
        }
    }

    T getMin() const override {
        return *std::min_element(this->data.begin(), this->data.end());
    }

    T getMax() const override {
        return *std::max_element(this->data.begin(), this->data.end());
    }

    T getMean() const override {
        return std::accumulate(this->data.begin(), this->data.end(), T(0)) / this->data.size();
    }

    T getMedian() override {
        std::sort(this->data.begin(), this->data.end());
        size_t size = this->data.size();
        if (size % 2 == 0)
            return (this->data[size / 2 - 1] + this->data[size / 2]) / 2;
        else
            return this->data[size / 2];
    }

    std::vector<int> getHistogram() override {
        std::map<int, int> histogram;
        T minVal = getMin();
        T maxVal = getMax();
        T range = maxVal - minVal;
        T bucketSize = range / 20;

        for (const T& val : this->data) {
            int bucket = static_cast<int>((val - minVal) / bucketSize);
            if (bucket == 20) bucket = 19; // Edge case for the maximum value
            histogram[bucket * bucketSize + minVal]++;
        }

        std::vector<int> histVec(20, 0);
        for (const auto& pair : histogram) {
            int bucket = static_cast<int>((pair.first - minVal) / bucketSize);
            histVec[bucket] = pair.second;
        }

        return histVec;
    }
};

#endif 


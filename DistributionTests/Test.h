#ifndef TEST_H
#define TEST_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <map>

template<typename T>
class Test {
protected:
    std::vector<T> data;

public:
   
    Test(int numSamples) { data.reserve(numSamples); }

    virtual ~Test() = 0;

 
    virtual T getMin() const = 0;
    virtual T getMax() const = 0;
    virtual T getMean() const = 0;
    virtual T getMedian() = 0;
    virtual std::vector<int> getHistogram() = 0;
};

template <typename T>
Test<T>::~Test() {}

#endif 
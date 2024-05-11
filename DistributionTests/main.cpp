#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include "UniformTest.h"
#include "NormalTest.h"
#include <iomanip>


template<typename T>
void runTests(Test<T>* pTest) {
    std::cout << "Min: " << pTest->getMin() << std::endl;
    std::cout << "Max: " << pTest->getMax() << std::endl;
    std::cout << "Mean: " << pTest->getMean() << std::endl;
    std::cout << "Median: " << pTest->getMedian() << std::endl;

    auto histogram = pTest->getHistogram();
    T minVal = pTest->getMin();
    T maxVal = pTest->getMax();
    T range = maxVal - minVal;
    T bucketSize = range / 20;

    std::cout << "Histogram:" << std::endl;
    for (size_t i = 0; i < histogram.size(); ++i) {
        std::cout << std::fixed << std::setprecision(1) << minVal + i * bucketSize << " - "
            << minVal + (i + 1) * bucketSize << ": " << histogram[i] << std::endl;
    }
}

int main()
{
    using namespace nana;

    form fm(API::make_center(400, 200), appear::decorate<appear::minimize, appear::maximize>());
    fm.caption("Statistics Analysis Program");

    label lbl(fm, rectangle(10, 30, 380, 30));
    lbl.caption("Enter number of samples:");

    textbox samplesBox(fm, rectangle(10, 60, 380, 30));
    samplesBox.multi_lines(false);

    button btnUniform(fm, rectangle(10, 100, 185, 30));
    btnUniform.caption("Run UNIFORM distribution tests");
    btnUniform.events().click([&fm, &samplesBox] {
        auto numSamples = samplesBox.to_int();
        UniformTest<double> test(numSamples);
        runTests(&test);
        });

    button btnNormal(fm, rectangle(205, 100, 185, 30));
    btnNormal.caption("Run NORMAL distribution tests");
    btnNormal.events().click([&fm, &samplesBox] {
        auto numSamples = samplesBox.to_int();
        NormalTest<double> test(numSamples);
        runTests(&test);
        });

    fm.show();
    exec();
}

#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std::chrono;

constexpr int DATA_SIZE = 1000000;

template<class T>
void calculateSMA(const std::vector<T>& data, std::vector<T>& result, size_t window);

template<class T>
std::vector<T> generateRandomData(std::mt19937& random_engine);

int main()
{
    std::random_device random_device;
    std::mt19937 engine(random_device());

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::vector<size_t> window_widths = { 4, 8, 16, 32, 64, 128 };
    std::cout << "Perfomance for float:" << std::endl;
    for (size_t width : window_widths)
    {
        std::vector<float> float_results(DATA_SIZE);
        auto start = high_resolution_clock::now();
        calculateSMA(generateRandomData<float>(engine), float_results, width);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        std::cout << "Window width " << width << ": " << (DATA_SIZE / (float)duration.count()) * 1000 << std::endl;
    }

    std::cout << "Perfomance for double:" << std::endl;
    for (size_t width : window_widths)
    {
        std::vector<double> double_results(DATA_SIZE);
        auto start = high_resolution_clock::now();
        calculateSMA(generateRandomData<double>(engine), double_results, width);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        std::cout << "Window width " << width << ": " << (DATA_SIZE / (float)duration.count()) * 1000 << std::endl;
    }

    return 0;
}

template<class T>
void calculateSMA(const std::vector<T>& data, std::vector<T>& result, size_t window_width)
{
    T sum = 0;
    for (size_t i = 0; i < DATA_SIZE; ++i)
    {
        sum += data[i];
        if (i >= window_width)
        {
            sum -= data[i - window_width];
        }
        if (i + 1 >= window_width)
        {
            result[i] = sum / window_width;
        }
    }
}

template<class T>
std::vector<T> generateRandomData(std::mt19937& random_engine)
{
    std::uniform_real_distribution<T> distribution(0, std::numeric_limits<T>::max());
    std::uniform_int_distribution<> int_disctribution(0, 1);
    std::vector<T> data(DATA_SIZE);
    for (size_t i = 0; i < DATA_SIZE; ++i)
    {
        auto random_value = distribution(random_engine);
        data[i] = int_disctribution(random_engine) ? random_value : -random_value;
    }
    return data;
}
#include <iostream>
#include <random>

constexpr int DATA_SIZE = 100;
constexpr int LOWER_BOUND = 0;
constexpr int UPPER_BOUND = 10000;

const size_t window_width = 4;

template<class T>
void calculateSMA(const std::vector<T>& data, std::vector<T>& result, size_t window);

template<class T>
void print_vector(const std::vector<T>& data);

template<class T>
std::vector<T> generateRandomData(std::mt19937& random_engine);

int main()
{
    std::random_device random_device;
    std::mt19937 engine(random_device());
    std::vector<float> float_results(DATA_SIZE);
    calculateSMA(generateRandomData<float>(engine), float_results, window_width);

    std::vector<double> double_results(DATA_SIZE);
    calculateSMA(generateRandomData<double>(engine), double_results, window_width);

    std::vector<float> src_data = { 2, 4, 6, 8, 12, 14, 16, 18, 20 };
    std::vector<float> sma_result;
    std::vector<size_t> window_widths = { 4, 8, 16, 32, 64, 128 };
    //calculateSMA(src_data, sma_result, width);
    print_vector(float_results);
    print_vector(double_results);

    return 0;
}

template<class T>
void calculateSMA(const std::vector<T>& data, std::vector<T>& result, size_t window)
{
    T sum = 0;
    for (size_t i = 0; i < data.size(); ++i)
    {
        sum += data[i];
        if (i >= window)
        {
            sum -= data[i - window];
        }
        if (i + 1 >= window)
        {
            result[i] = sum / window;
        }
    }
}

template<class T>
void print_vector(const std::vector<T>& data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << "[" << data[i] << "]";
    }
    std::cout << std::endl;
}

template<class T>
std::vector<T> generateRandomData(std::mt19937& random_engine)
{
    std::uniform_real_distribution<T> distribution(LOWER_BOUND, UPPER_BOUND);
    std::vector<T> data(DATA_SIZE);
    for (size_t i = 0; i < DATA_SIZE; ++i)
    {
        data[i] = (distribution(random_engine));
    }
    return data;
}
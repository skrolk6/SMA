#include <iostream>
#include <vector>

static const int width = 3;

template<class T>
void calculateSMA(const std::vector<T>& data, std::vector<T>& result, int window);

void print_vector(const std::vector<float>& data);

int main()
{
    std::vector<float> src_data = { 2, 4, 6, 8, 12, 14, 16, 18, 20 };
    std::vector<float> sma_result;
    calculateSMA(src_data, sma_result, width);
    print_vector(sma_result);

    return 0;
}

template<class T>
void calculateSMA(const std::vector<T>& data, std::vector<T>& result, int window)
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
            result.emplace_back(sum / window);
        }
    }
}

void print_vector(const std::vector<float>& data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << "[" << data[i] << "]";
    }
    std::cout << std::endl;
}
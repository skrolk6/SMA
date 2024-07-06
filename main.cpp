#include <iostream>
#include <vector>
#include <queue>

static const int width = 2;

void print_queue(std::queue<int> data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << "[" << data.front() << "]";
        data.pop();
    }
    std::cout << std::endl;
}

void print_vector(const std::vector<float>& data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << "[" << data[i] << "]";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> src_data = { 2, 4, 6, 8, 12, 14, 16, 18, 20 };
    std::vector<float> sma_result;
    std::queue<int> buffer;
    int sum = 0;
    for (size_t i = 0; i < src_data.size(); ++i)
    {
        buffer.push(src_data[i]);
        sum += src_data[i];
        if (i >= width)
        {
            sum -= buffer.front();
            buffer.pop();
        }
        if (i + 1 >= width)
        {
            sma_result.emplace_back(sum / width);
        }
        print_queue(buffer);
    }
    print_vector(sma_result);

    return 0;
}
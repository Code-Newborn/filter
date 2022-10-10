#include "filter.h"

std::list<float> data_inwindow;

float filter_result_median = 0;

void filter_Median(float input, int filterwindowsize)
{
    data_inwindow.push_back(input);
    if (data_inwindow.size() > filterwindowsize)
        data_inwindow.pop_front();

    std::list<float> data_inwindow_copy;
    for (std::list<float>::iterator iteratorIndex = data_inwindow.begin(); iteratorIndex != data_inwindow.end(); iteratorIndex++)
    {
        data_inwindow_copy.push_back(*iteratorIndex); // 复制数据
    }

    if (data_inwindow.size() > 1)
    {
        data_inwindow_copy.sort(compare_Median);                               // 对复制数据进行排序
        std::list<float>::iterator data_iterator = data_inwindow_copy.begin(); // list迭代器

        if (data_inwindow.size() % 2 == 0) // 滤波窗口大小为偶数
        {
            for (int i = 0; i < (data_inwindow.size() / 2) - 1; i++)
            {
                data_iterator++;
            }
            filter_result_median = (*data_iterator);
            data_iterator++;
            filter_result_median = (filter_result_median + (*data_iterator)) / 2;
        }
        else // 滤波窗口大小为奇数
        {
            for (int i = 0; i < (data_inwindow.size() + 1) / 2 - 1; i++)
            {
                data_iterator++;
            }

            filter_result_median = (*data_iterator);
        }
    }
    else // 数据量不大于1，结果为首值
    {
        filter_result_median = (*(data_inwindow.begin()));
    }
}

bool compare_Median(float a, float b)
{
    return a < b;
}
#include <opencv2/opencv.hpp>
#include "median_filter_4Point.h"
#include "filter.h"
#include <Windows.h>

int main(int argc, char const *argv[])
{
    // ==================== 4坐标点集中值滤波 ====================
    int filterwindowssize_setof4Points = 3; // 滤波窗口大小
    cv::Point set1[4] = {cv::Point(1, 2),
                         cv::Point(32, 4),
                         cv::Point(5, 63),
                         cv::Point(7, 84)};

    cv::Point set2[4] = {cv::Point(36, 21),
                         cv::Point(25, 67),
                         cv::Point(13, 92),
                         cv::Point(50, 31)};

    cv::Point set3[4] = {cv::Point(13, 2),
                         cv::Point(23, 16),
                         cv::Point(11, 19),
                         cv::Point(3, 33)};

    cv::Point set4[4] = {cv::Point(23, 24),
                         cv::Point(23, 10),
                         cv::Point(44, 91),
                         cv::Point(10, 14)};

    MedianFilter_setof4Points(set1, filterwindowssize_setof4Points);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter_setof4Points(set2, filterwindowssize_setof4Points);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter_setof4Points(set3, filterwindowssize_setof4Points);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter_setof4Points(set4, filterwindowssize_setof4Points);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter_setof4Points(set4, filterwindowssize_setof4Points);
    print_result(filter_result);
    std::cout << "" << std::endl;
    // ==================== 4坐标点集中值滤波END ====================

    // ==================== 一维数据中值滤波 ====================
    int filterwindowsize = 4; // 滤波窗口大小
    float data1 = 1.3f;
    float data2 = 12.1f;
    float data3 = 5.9f;
    float data4 = 14.1f;
    float data5 = 9.1f;
    float data6 = 1.6f;
    float data7 = 1.0f;
    float data8 = 0.8f;
    float data9 = 0.4f;

    LARGE_INTEGER t1, t2, tc;
    double timespan;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    filter_Median(data1, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data2, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data3, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data4, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data5, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data6, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data7, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data8, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）

    filter_Median(data9, filterwindowsize);
    std::cout << filter_result_median << std::endl;
    QueryPerformanceCounter(&t2);
    timespan = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    std::cout << "time = " << timespan << std::endl; //输出时间（单位：ｓ）
    // ==================== 一维数据中值滤波END ====================

    return 0;
}

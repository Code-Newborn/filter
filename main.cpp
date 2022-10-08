#include <opencv2/opencv.hpp>
#include "median_filter_4Point.h"
#include "filter.h"

int main(int argc, char const *argv[])
{
    // ==================== 4坐标点集中值滤波 ====================
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

    MedianFilter(set1, 5);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter(set2, 5);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter(set3, 5);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter(set4, 5);
    print_result(filter_result);
    std::cout << "" << std::endl;

    MedianFilter(set4, 5);
    print_result(filter_result);
    std::cout << "" << std::endl;
    // ==================== 4坐标点集中值滤波END ====================

    // ==================== 一维数据中值滤波 ====================
    float data1 = 1.3f;
    float data2 = 12.1f;
    float data3 = 5.9f;
    float data4 = 14.1f;
    float data5 = 9.1f;
    float data6 = 1.6f;
    float data7 = 1.0f;

    filter_Median(data1, 3);
    std::cout << filter_result_median << std::endl;
    filter_Median(data2, 3);
    std::cout << filter_result_median << std::endl;
    filter_Median(data3, 3);
    std::cout << filter_result_median << std::endl;
    filter_Median(data4, 3);
    std::cout << filter_result_median << std::endl;
    filter_Median(data5, 3);
    std::cout << filter_result_median << std::endl;
    filter_Median(data6, 3);
    std::cout << filter_result_median << std::endl;
    filter_Median(data7, 3);
    std::cout << filter_result_median << std::endl;
    // ==================== 一维数据中值滤波END ====================

    return 0;
}

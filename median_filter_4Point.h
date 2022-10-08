#ifndef _MEDIAN_FILTER_H_
#define _MEDIAN_FILTER_H_

#include <opencv2/opencv.hpp>

extern cv::Point filter_result[4];

void MedianFilter(cv::Point *input, int filterwindowsize);

void print_result(cv::Point *result);

bool compare(int a, int b);

#endif

#ifndef _FILTER_H_
#define _FILTER_H_

#include <opencv2/opencv.hpp>

extern float filter_result_median;

void filter_Median(float input, int filterwindowsize);

bool compare_Median(float a, float b);

#endif
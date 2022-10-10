#include "median_filter_4Point.h"

std::list<cv::Point *> set_ofPoints4;
cv::Point filter_result[4];

void MedianFilter_setof4Points(cv::Point *input, int filterwindowsize)
{
    set_ofPoints4.push_back(input);
    if (set_ofPoints4.size() > filterwindowsize)
    {
        set_ofPoints4.pop_front(); // 数据队列
    }
    std::list<int> leftTop_x;
    std::list<int> leftTop_y;
    std::list<int> rightTop_x;
    std::list<int> rightTop_y;
    std::list<int> rightBottom_x;
    std::list<int> rightBottom_y;
    std::list<int> leftBottom_x;
    std::list<int> leftBottom_y;
    for (std::list<cv::Point *>::iterator iteratorIndex = set_ofPoints4.begin(); iteratorIndex != set_ofPoints4.end(); iteratorIndex++)
    {
        leftTop_x.push_back((*iteratorIndex)[0].x); // 数据列表
        leftTop_y.push_back((*iteratorIndex)[0].y);
        rightTop_x.push_back((*iteratorIndex)[1].x);
        rightTop_y.push_back((*iteratorIndex)[1].y);
        rightBottom_x.push_back((*iteratorIndex)[2].x);
        rightBottom_y.push_back((*iteratorIndex)[2].y);
        leftBottom_x.push_back((*iteratorIndex)[3].x);
        leftBottom_y.push_back((*iteratorIndex)[3].y);
        /* code */
    }
    if (set_ofPoints4.size() > 1)
    {
        leftTop_x.sort(compare); // 左上角x坐标排序
        leftTop_y.sort(compare);
        rightTop_x.sort(compare);
        rightTop_y.sort(compare);
        rightBottom_x.sort(compare);
        rightBottom_y.sort(compare);
        leftBottom_x.sort(compare);
        leftBottom_y.sort(compare);
        std::list<int>::iterator index_leftTop_x = leftTop_x.begin(); // list
        std::list<int>::iterator index_leftTop_y = leftTop_y.begin();
        std::list<int>::iterator index_rightTop_x = rightTop_x.begin();
        std::list<int>::iterator index_rightTop_y = rightTop_y.begin();
        std::list<int>::iterator index_rightBottom_x = rightBottom_x.begin();
        std::list<int>::iterator index_rightBottom_y = rightBottom_y.begin();
        std::list<int>::iterator index_leftBottom_x = leftBottom_x.begin();
        std::list<int>::iterator index_leftBottom_y = leftBottom_y.begin();
        if (set_ofPoints4.size() % 2 == 0) // 滤波窗口大小为偶数
        {
            for (int i = 0; i < (set_ofPoints4.size() + 1) / 2 - 1; i++)
            {
                index_leftTop_x++;
                index_leftTop_y++;
                index_rightTop_x++;
                index_rightTop_y++;
                index_rightBottom_x++;
                index_rightBottom_y++;
                index_leftBottom_x++;
                index_leftBottom_y++;
            }
            filter_result[0].x = (*index_leftTop_x);
            filter_result[0].y = (*index_leftTop_y);
            filter_result[1].x = (*index_rightTop_x);
            filter_result[1].y = (*index_rightTop_y);
            filter_result[2].x = (*index_rightBottom_x);
            filter_result[2].y = (*index_rightBottom_y);
            filter_result[3].x = (*index_leftBottom_x);
            filter_result[3].y = (*index_leftBottom_y);
            index_leftTop_x++;
            index_leftTop_y++;
            index_rightTop_x++;
            index_rightTop_y++;
            index_rightBottom_x++;
            index_rightBottom_y++;
            index_leftBottom_x++;
            index_leftBottom_y++;

            filter_result[0].x = (filter_result[0].x + (*index_leftTop_x)) / 2;
            filter_result[0].y = (filter_result[0].y + (*index_leftTop_y)) / 2;
            filter_result[1].x = (filter_result[1].x + (*index_rightTop_x)) / 2;
            filter_result[1].y = (filter_result[1].y + (*index_rightTop_y)) / 2;
            filter_result[2].x = (filter_result[2].x + (*index_rightBottom_x)) / 2;
            filter_result[2].y = (filter_result[2].y + (*index_rightBottom_y)) / 2;
            filter_result[3].x = (filter_result[3].x + (*index_leftBottom_x)) / 2;
            filter_result[3].y = (filter_result[3].y + (*index_leftBottom_y)) / 2;
        }
        else // 滤波窗口大小为奇数
        {
            for (int i = 0; i < (set_ofPoints4.size() + 1) / 2 - 1; i++)
            {
                index_leftTop_x++;
                index_leftTop_y++;
                index_rightTop_x++;
                index_rightTop_y++;
                index_rightBottom_x++;
                index_rightBottom_y++;
                index_leftBottom_x++;
                index_leftBottom_y++;
            }

            filter_result[0].x = (*index_leftTop_x);
            filter_result[0].y = (*index_leftTop_y);
            filter_result[1].x = (*index_rightTop_x);
            filter_result[1].y = (*index_rightTop_y);
            filter_result[2].x = (*index_rightBottom_x);
            filter_result[2].y = (*index_rightBottom_y);
            filter_result[3].x = (*index_leftBottom_x);
            filter_result[3].y = (*index_leftBottom_y);
        }
    }
    else
    {
        filter_result[0].x = (*(set_ofPoints4.begin()))[0].x;
        filter_result[0].y = (*(set_ofPoints4.begin()))[0].y;
        filter_result[1].x = (*(set_ofPoints4.begin()))[1].x;
        filter_result[1].y = (*(set_ofPoints4.begin()))[1].y;
        filter_result[2].x = (*(set_ofPoints4.begin()))[2].x;
        filter_result[2].y = (*(set_ofPoints4.begin()))[2].y;
        filter_result[3].x = (*(set_ofPoints4.begin()))[3].x;
        filter_result[3].y = (*(set_ofPoints4.begin()))[3].y;
    }
}
void print_result(cv::Point *result)
{
    // 打印输出
    std::cout << "(" << result[0].x << "," << result[0].y << ")"
              << "   "
              << "(" << result[1].x << "," << result[1].y << ")"
              << "   "
              << "(" << result[2].x << "," << result[2].y << ")"
              << "   "
              << "(" << result[3].x << "," << result[3].y << ")" << std::endl;
}
bool compare(int a, int b)
{
    return a < b;
}
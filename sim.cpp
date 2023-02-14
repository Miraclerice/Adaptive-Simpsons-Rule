// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

double a, b, c, l, r;

/**
 * 原函数
*/
inline double f(double x) {
    return a * exp(b * pow(x, c)); 
}

/**
 * Simpson公式
 * f：被积函数
 * l：积分下限
 * r：积分上限
*/
inline double simpson(double l, double r) { 
    double mid = (l + r) / 2;
    return (f(l) + 4 * f(mid) + f(r)) * (r - l) / 6;
}

/**
 * 自适应辛普森积分求解函数
 * l：积分下限
 * r：积分上限
 * eps：期望误差
 * ans: simpson值
*/
double adaptive_simpson_integration(double l, double r, double eps, double ans) {
    double mid = (l + r) / 2;
    double l_ = simpson(l, mid), r_ = simpson(mid, r);
    if (fabs(l_ + r_ - ans) < 15 * eps) {
        return l_ + r_ + (l_ + r_ - ans) / 15;         // 确认精度
        // return l_ + r_; // 近似
    }
    // 精度不足递归调用该函数
    return adaptive_simpson_integration(l, mid, eps / 2, l_) + adaptive_simpson_integration(mid, r, eps / 2, r_); 
}

/**
 * 自适应辛普森积分函数接口
*/
inline double adaptive_simpson_integration(double l, double r, double eps) {
    return adaptive_simpson_integration(l, r, eps, simpson(l, r));
}

/**
 * 输入参数，打印结果
*/
inline void integral_value() {
    std::cout << "请您输入原函数各参数：" << std::endl;
    scanf_s("%lf%lf%lf", &a, &b, &c);
    std::cout << "请您输入积分区间左右值：" << std::endl;
    scanf_s("%lf%lf", &l, &r);

    std::cout << "计算输出的结果为：" << std::endl;
    // 0.139403
    printf("%.6lf", adaptive_simpson_integration(l, r, 1e-6));
}

int main() {
    integral_value();

    return 0;
}
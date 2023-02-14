// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

double a, b, c, l, r;

/**
 * ԭ����
*/
inline double f(double x) {
    return a * exp(b * pow(x, c)); 
}

/**
 * Simpson��ʽ
 * f����������
 * l����������
 * r����������
*/
inline double simpson(double l, double r) { 
    double mid = (l + r) / 2;
    return (f(l) + 4 * f(mid) + f(r)) * (r - l) / 6;
}

/**
 * ����Ӧ����ɭ������⺯��
 * l����������
 * r����������
 * eps���������
 * ans: simpsonֵ
*/
double adaptive_simpson_integration(double l, double r, double eps, double ans) {
    double mid = (l + r) / 2;
    double l_ = simpson(l, mid), r_ = simpson(mid, r);
    if (fabs(l_ + r_ - ans) < 15 * eps) {
        return l_ + r_ + (l_ + r_ - ans) / 15;         // ȷ�Ͼ���
        // return l_ + r_; // ����
    }
    // ���Ȳ���ݹ���øú���
    return adaptive_simpson_integration(l, mid, eps / 2, l_) + adaptive_simpson_integration(mid, r, eps / 2, r_); 
}

/**
 * ����Ӧ����ɭ���ֺ����ӿ�
*/
inline double adaptive_simpson_integration(double l, double r, double eps) {
    return adaptive_simpson_integration(l, r, eps, simpson(l, r));
}

/**
 * �����������ӡ���
*/
inline void integral_value() {
    std::cout << "��������ԭ������������" << std::endl;
    scanf_s("%lf%lf%lf", &a, &b, &c);
    std::cout << "�������������������ֵ��" << std::endl;
    scanf_s("%lf%lf", &l, &r);

    std::cout << "��������Ľ��Ϊ��" << std::endl;
    // 0.139403
    printf("%.6lf", adaptive_simpson_integration(l, r, 1e-6));
}

int main() {
    integral_value();

    return 0;
}
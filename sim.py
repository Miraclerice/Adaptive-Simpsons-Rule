# -*- coding: UTF-8 -*-
# @author  : M_Xie
# @date    : 2022-12-22 14:30:12
import numpy as np


def adaptive_simpson_integration(f, a, b, eps):
    """
    自适应辛普森积分函数
    f：被积函数
    a：积分下限
    b：积分上限
    eps：期望误差
    """

    # 定义辛普森积分的公式
    def simpson_rule(f, a, b):
        return (b - a) / 6 * (f(a) + 4 * f((a + b) / 2) + f(b))

    # 递归计算积分
    def recursive_integrate(f, a, b, eps, whole):
        # 计算两个子区间的中点
        c = (a + b) / 2
        left = simpson_rule(f, a, c)
        right = simpson_rule(f, c, b)

        # 如果误差在容忍范围内，直接返回当前整个区间的积分
        if abs(left + right - whole) <= 15 * eps:
            return left + right + (left + right - whole) / 15

        # 否则递归计算两个子区间的积分，并将它们相加
        return recursive_integrate(f, a, c, eps / 2, left) + recursive_integrate(f, c, b, eps / 2, right)

    whole = simpson_rule(f, a, b)
    return recursive_integrate(f, a, b, eps, whole)


def f(x):
    return np.exp(-(x ** 2))


if __name__ == '__main__':
    print(adaptive_simpson_integration(f, 1, 100, 1e-6))  # 输出：0.13940279918249773

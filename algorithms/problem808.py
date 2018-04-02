#!/usr/bin/python
# -*- coding: utf-8 -*-
# author: Guilherme Steinmann
# date: 2018-04-02

class Solution(object):
    def __init__(self):
        self.precalc = {}

    def soupServings(self, N):
        if N >= 5000:
            return 1.0

        precalc = {}
        def probCalc(A, B):
            if A <= 0 and B <= 0:
                return 0.5
            if A <= 0:
                return 1.0
            if B <= 0:
                return 0.0

            if (A, B) in precalc:
                return precalc[(A, B)]

            prob = 0.25 * probCalc(A - 100, B)
            prob += 0.25 * probCalc(A - 75, B - 25)
            prob += 0.25 * probCalc(A - 50, B - 50)
            prob += 0.25 * probCalc(A - 25, B - 75)

            precalc[(A, B)] = prob
            return prob

        return probCalc(N, N)


if __name__ == "__main__":
    s = Solution()
    print s.soupServings(2200)

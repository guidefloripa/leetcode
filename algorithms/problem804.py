#!/usr/bin/python
# -*- coding: utf-8 -*-
# author: Guilherme Steinmann
# date: 2018-03-30

class Solution(object):
    def uniqueMorseRepresentations(self, words):
        code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        codes = []
        for word in words:
            c = ''
            for w in word:
                c += code[ord(w)-97]
            if c not in codes:
                codes.append(c)

        return len(codes)

if __name__ == "__main__":
    s = Solution()
    w = ["gin", "zen", "gig", "msg"]
    print s.uniqueMorseRepresentations(w)

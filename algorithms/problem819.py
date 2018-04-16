#!/usr/bin/python
# -*- coding: utf-8 -*-
# author: Guilherme Steinmann
# date: 2018-04-19

import string

class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        words = {}
        for word in paragraph.split():
            word = ''.join(w for w in word if w not in string.punctuation).lower()
            if word not in banned:
                if word in words:
                    words[word] += 1
                else:
                    words[word] = 1
        return max(words.iterkeys(), key=(lambda k: words[k]))


if __name__ == "__main__":
    s = Solution()
    paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    banned = ['hit']
    print s.mostCommonWord(paragraph, banned)

import sys
sys.path.append("E:/study_series/python_mofan/python_weixin/")
from nowcoder.pow import Solution

import unittest
from unittest import TestCase

class TestPow(unittest.TestCase):
    def test_resolve(self):
        s=Solution()
        self.assertEqual(s.resolve(2, 2),4)
        self.assertTrue(s.resolve(2,2)==4)


    def test_resolve_v3(self):
        s=Solution()
        self.assertEqual(s.resolve(2, 2),4)
        self.assertTrue(s.resolve(2,2)==4)
if __name__=="__main__":
    unittest.main()




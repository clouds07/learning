import unittest

from leafnode import LeafNode

class TestLeafNode(unittest.TestCase):
    def test_eq_tag(self):
        node = LeafNode("p", "This is a paragraph of text.")
        node2 = LeafNode("div", "This is a paragraph of text.")
        self.assertNotEqual(node, node2)
    def test_eq_value(self):
        node = LeafNode("p", "This is a paragraph of text.")
        node2 = LeafNode("p", "This is a div of text.")
        self.assertNotEqual(node, node2)
    def test_eq_props(self):
        node = LeafNode("p", "This is a paragraph of text.", {"class": "paragraph"})
        node2 = LeafNode("p", "This is a paragraph of text.", {"class": "div"})
        self.assertNotEqual(node, node2)
'''
    def test_repr(self):
        node = LeafNode("p", "This is a paragraph of text.")
        self.assertEqual(repr(node), "LeafNode(p, This is a paragraph of text., None)")
    def test_eq(self):
        node = LeafNode("p", "This is a paragraph of text.")
        node2 = LeafNode("p", "This is a paragraph of text.")
        self.assertEqual(node, node2)
'''

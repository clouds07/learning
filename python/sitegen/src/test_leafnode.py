import unittest

from leafnode import LeafNode
from textnode import TextNode
from textnode import TextType
from parentnode import ParentNode
from htmlnode import HTMLNode
from leafnode import text_node_to_html_node

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

    def test_leaf_to_html_p(self):
        node = LeafNode("p", "Hello, world!")
        self.assertEqual(node.to_html(), "<p>Hello, world!</p>")

    def test_eq(self):
        node = LeafNode("p", "This is a paragraph of text.")
        node2 = LeafNode("p", "This is a paragraph of text.")
        self.assertEqual(str(node), str(node2))

    def test_text(self):
        node = TextNode("This is a text node", TextType.TEXT)
        html_node = text_node_to_html_node(node)
        self.assertEqual(html_node.tag, None)
        self.assertEqual(html_node.value, "This is a text node")

if __name__ == "__main__":
    unittest.main()

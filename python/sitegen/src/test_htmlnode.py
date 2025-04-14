import unittest

from htmlnode import HTMLNode

class TestHTMLNode(unittest.TestCase):
    def test_repr(self):
        node = HTMLNode("p", "This is a paragraph")
        self.assertEqual(repr(node), "HTMLNode(p, This is a paragraph, None, None)")

    def test_eq_tag(self):
        node = HTMLNode("p", "This is a paragraph")
        node2 = HTMLNode("div", "This is a paragraph")
        self.assertNotEqual(str(node), str(node2))

    def test_eq_value(self):
        node = HTMLNode("p", "This is a paragraph")
        node2 = HTMLNode("p", "This is a div")
        self.assertNotEqual(str(node), str(node2))

    def test_eq_children(self):
        node = HTMLNode("p", "This is a paragraph", [HTMLNode("span", "This is a span")])
        node2 = HTMLNode("p", "This is a paragraph", [HTMLNode("span", "This is a div")])
        self.assertNotEqual(str(node), str(node2))

    def test_eq_props(self):
        node = HTMLNode("p", "This is a paragraph", None, {"class": "paragraph"})
        node2 = HTMLNode("p", "This is a paragraph", None, {"class": "div"})
        self.assertNotEqual(str(node), str(node2))

    def test_props_to_html(self):
        node = HTMLNode("p", "This is a paragraph", None, {"class": "paragraph", "id": "1"})
        self.assertEqual(node.props_to_html(), ' class="paragraph" id="1"')

    def test_props_to_html_none(self):
        node = HTMLNode("p", "This is a paragraph")
        self.assertEqual(node.props_to_html(), "")

if __name__ == "__main__":
    unittest.main()

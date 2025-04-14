import unittest

from parentnode import ParentNode
from leafnode import LeafNode

class TestParentNode(unittest.TestCase):
#    def test_repr(self):
#        node = ParentNode("div", "This is a div")
#        self.assertEqual(repr(node), "ParentNode(div, This is a div, None, None)")
    
    def test_eq_tag(self):
        node = ParentNode("div", "This is a div")
        node2 = ParentNode("p", "This is a div")
        self.assertNotEqual(node, node2)
    
    def test_eq_value(self):
        node = ParentNode("div", "This is a div")
        node2 = ParentNode("div", "This is a paragraph")
        self.assertNotEqual(node, node2)
    
    def test_eq_children(self):
        node = ParentNode("div", "This is a div", [ParentNode("span", "This is a span")])
        node2 = ParentNode("div", "This is a div", [ParentNode("span", "This is a paragraph")])
        self.assertNotEqual(node, node2)
    
    def test_eq_props(self):
        node = ParentNode("div", "This is a div", {"class": "div"})
        node2 = ParentNode("div", "This is a div", {"class": "paragraph"})
        self.assertNotEqual(node, node2)
    
    def test_props_to_html(self):
        node = ParentNode("div", "This is a div", {"class": "div", "id": "1"})
        self.assertEqual(node.props_to_html(), ' class="div" id="1"')
    
    def test_props_to_html_none(self):
        node = ParentNode("div", "This is a div")
        self.assertEqual(node.props_to_html(), "")

    # Test the to_html method with a parent node containing a single child node
    # def test_to_html_with_children(self):
    #     child_node = LeafNode("span", "child")
    #     parent_node = ParentNode("div", [child_node])
    #     self.assertEqual(parent_node.to_html(), "<div><span>child</span></div>")

    # Test the to_html method with a parent node containing a child node that has its own child (grandchild)
    # def test_to_html_with_grandchildren(self):
    #     grandchild_node = LeafNode("b", "grandchild")
    #     child_node = ParentNode("span", [grandchild_node])
    #     parent_node = ParentNode("div", [child_node])
    #     self.assertEqual(
    #         parent_node.to_html(),
    #         "<div><span><b>grandchild</b></span></div>",
    #     )

if __name__ == "__main__":
    unittest.main()

from textnode import TextNode
from textnode import TextType

def main():
    text_node = TextNode("hello world", TextType.NORMAL, "http://www.softix.nl")
    print(text_node)

main()

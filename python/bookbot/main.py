def get_book_text(path):
    with open(path) as f:
        return f.read()

def get_chars_count_dict(text):
    chars_count = {}
    for text_char in text:
        if str(text_char).isalpha():
            if text_char in chars_count:
                chars_count[text_char] += 1
            else:
                chars_count[text_char] = 1
    return chars_count

def sort_on(dict):
    return dict["num"]

def sort_dict(dict):
    return

def main():
    book_path = "books/frankenstein.txt"
    book_text = get_book_text(book_path)
    words = book_text.split()
    print(f"Opening file {book_path}")
    print(f"The file contains {len(words)} words")

    book_char_dictionary = get_chars_count_dict(book_text.lower())
    book_char_sorted = dict(sorted(book_char_dictionary.items()))
    for entry in book_char_sorted:
        print(f"Character '{entry}': {book_char_sorted[entry]}")

main()


from PIL import Image
import time
import pyfiglet

def print_ascii_text(text):
    ascii_art = pyfiglet.figlet_format(text, font='slant')
    print(ascii_art)

def image_to_ascii(image_path, output_width=100, characters="@%#*+=-:. "):
    image = Image.open(image_path)

    aspect_ratio = image.height / image.width
    output_height = int(output_width * aspect_ratio)
    image = image.resize((output_width, output_height))
    image = image.convert('L')

    pixels = list(image.getdata())

    max_pixel_value = max(pixels)
    min_pixel_value = min(pixels)
    
    ascii_art_lines = []
    for pixel in pixels:
        character_index = int((pixel - min_pixel_value) / (max_pixel_value - min_pixel_value) * (len(characters) - 1))
        ascii_art_lines.append(characters[character_index])

    greeting_text = "HAPPY BIRTHDAY TANYA!"
    print_ascii_text(greeting_text)

    for i in range(0, len(ascii_art_lines), output_width):
        line = ''.join(ascii_art_lines[i:i + output_width])
        print(line)
        time.sleep(0.1)

image_path = r"C:\Users\devan\OneDrive\Pictures\Screenshots\IMG-20230921-WA0009.jpg"
image_to_ascii(image_path)



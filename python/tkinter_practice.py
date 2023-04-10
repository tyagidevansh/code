import tkinter as tk 
from tkinter import ttk
import random

window = tk.Tk()
window.title('Paint')
window.geometry("800x800")

def very_basic_paint_app():
    global brush_size
    brush_size = 4
    
    canvas = tk.Canvas(window, width = 800, height = 800, bg = 'white')
    canvas.pack()

    def draw(event):
        x = event.x
        y = event.y
        canvas.create_oval((x-brush_size/2, y-brush_size/2, x+brush_size/2, y+brush_size/2), fill='black')
        
    def brush_size_adjust(event):
        global brush_size
        if event.delta > 0:
            brush_size += 2
        elif event.delta < 0:
            brush_size -= 2
        brush_size = max(0,min(brush_size, 50))
        
    
    canvas.bind('<Motion>', draw)
    canvas.bind('<MouseWheel>', brush_size_adjust)
    
def random_name_gui_table():
    first_names = ['John', 'Steve', 'Ellyse', 'Emily', 'Thomas', 'Nero', 'Magnus', 'Taylor', 'Anna', 'Levy', 'Harry']
    last_names = ['Caesar', 'Augustus', 'Rockefeller', 'Rothschild', 'Zedong', 'Windsor', 'Mountbatten']

    table = ttk.Treeview(window, columns = ('first', 'last', 'email'), show = 'headings')
    table.heading('first', text='First name')
    table.heading('last', text = 'Last name')
    table.heading('email', text = "Email address")
    table.pack(fill = 'both', expand = True)

    for i in range(100):
        first = random.choice(first_names)
        last = random.choice(last_names)
        mail = first + str(random.randint(1,999)) + '@pedomail.com'
        
        table.insert(parent = '', index = 0, values = (first, last, mail))

    def get_value(_):
        print(table.selection())
        for i in table.selection():
            value = table.item(i)['values']
            print('Name:', value[0] + " " + value[1],"\nEmail address:", value[2] )

    def delete_data(_):
        for i in table.selection():
            table.delete(i)
        

    table.bind('<<TreeviewSelect>>', get_value)
    table.bind('<Delete>', delete_data)



window.mainloop()